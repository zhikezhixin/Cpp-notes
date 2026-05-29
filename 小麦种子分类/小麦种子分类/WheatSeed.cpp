#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>
#include <map>
#include <iomanip>

// 简化版的小麦种子分类器类
class WheatSeedsClassifier {
public:
    // 数据结构定义
    struct DataPoint {
        std::vector<double> features;
        int label;
    };

    // 统计信息结构
    struct Statistics {
        double mean;
        double std;
        double min;
        double max;
    };

    // 混淆矩阵结构
    struct ConfusionMatrix {
        std::vector<std::vector<int>> matrix;
        int size;
    };

private:
    std::vector<DataPoint> dataset;
    std::vector<DataPoint> trainSet;
    std::vector<DataPoint> testSet;
    std::vector<std::string> featureNames;
    std::vector<std::string> classNames;
    std::vector<double> featureMeans;
    std::vector<double> featureStds;

    const int NUM_FEATURES = 7;
    const int NUM_CLASSES = 3;

public:
    WheatSeedsClassifier() {
        // 初始化特征名称
        featureNames = {
            "Area", "Perimeter", "Compactness", "Length_of_kernel",
            "Width_of_kernel", "Asymmetry_coefficient", "Length_of_groove"
        };

        // 初始化类别名称
        classNames = { "Kama", "Rosa", "Canadian" };

        featureMeans.resize(NUM_FEATURES, 0.0);
        featureStds.resize(NUM_FEATURES, 0.0);
    }

    // 数据加载函数
    bool loadData(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cout << "无法打开文件: " << filePath << std::endl;
            return false;
        }

        std::string line;
        dataset.clear();

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            DataPoint point;
            point.features.resize(NUM_FEATURES);

            // 读取7个特征值
            for (int i = 0; i < NUM_FEATURES; i++) {
                if (!(iss >> point.features[i])) {
                    std::cout << "数据格式错误" << std::endl;
                    return false;
                }
            }

            // 读取类别标签
            if (!(iss >> point.label)) {
                std::cout << "标签读取错误" << std::endl;
                return false;
            }

            // 将标签转换为0-2范围
            point.label = point.label - 1;
            dataset.push_back(point);
        }

        file.close();
        std::cout << "数据加载成功! 数据点数量: " << dataset.size() << std::endl;
        return true;
    }

    // 数据探索函数
    void exploreData() {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "数据探索" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        // 基本统计信息
        std::cout << "\n数据集大小: " << dataset.size() << " 个样本" << std::endl;
        std::cout << "特征数量: " << NUM_FEATURES << std::endl;
        std::cout << "类别数量: " << NUM_CLASSES << std::endl;

        // 类别分布
        std::vector<int> classCounts(NUM_CLASSES, 0);
        for (const auto& point : dataset) {
            classCounts[point.label]++;
        }

        std::cout << "\n类别分布:" << std::endl;
        for (int i = 0; i < NUM_CLASSES; i++) {
            std::cout << classNames[i] << " (类别" << (i + 1) << "): "
                << classCounts[i] << " 个样本 ("
                << (100.0 * classCounts[i] / dataset.size()) << "%)" << std::endl;
        }

        // 特征统计信息
        std::cout << "\n特征统计信息:" << std::endl;
        std::cout << std::setw(20) << "特征" << std::setw(10) << "均值"
            << std::setw(10) << "标准差" << std::setw(10) << "最小值"
            << std::setw(10) << "最大值" << std::endl;
        std::cout << std::string(60, '-') << std::endl;

        for (int f = 0; f < NUM_FEATURES; f++) {
            Statistics stats = calculateFeatureStatistics(f);
            std::cout << std::setw(20) << featureNames[f]
                << std::setw(10) << std::fixed << std::setprecision(3) << stats.mean
                    << std::setw(10) << stats.std
                    << std::setw(10) << stats.min
                    << std::setw(10) << stats.max << std::endl;
        }
    }

    // 计算特征统计信息
    Statistics calculateFeatureStatistics(int featureIndex) {
        Statistics stats;
        std::vector<double> values;

        for (const auto& point : dataset) {
            values.push_back(point.features[featureIndex]);
        }

        stats.mean = std::accumulate(values.begin(), values.end(), 0.0) / values.size();

        double variance = 0.0;
        for (double val : values) {
            variance += (val - stats.mean) * (val - stats.mean);
        }
        stats.std = std::sqrt(variance / values.size());

        stats.min = *std::min_element(values.begin(), values.end());
        stats.max = *std::max_element(values.begin(), values.end());

        return stats;
    }

    // 数据预处理
    void preprocessData(double testSize = 0.2) {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "数据预处理" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        // 随机打乱数据
        std::random_device rd;
        std::mt19937 gen(42); // 固定种子保证可重现
        std::shuffle(dataset.begin(), dataset.end(), gen);

        // 分割训练测试集
        size_t testSize_count = static_cast<size_t>(dataset.size() * testSize);
        size_t trainSize_count = dataset.size() - testSize_count;

        trainSet = std::vector<DataPoint>(dataset.begin(), dataset.begin() + trainSize_count);
        testSet = std::vector<DataPoint>(dataset.begin() + trainSize_count, dataset.end());

        std::cout << "训练集大小: " << trainSet.size() << std::endl;
        std::cout << "测试集大小: " << testSet.size() << std::endl;

        // 计算训练集的均值和标准差用于标准化
        calculateNormalizationParameters();

        // 标准化数据
        normalizeData(trainSet);
        normalizeData(testSet);

        std::cout << "数据预处理完成!" << std::endl;
    }

    // 计算标准化参数
    void calculateNormalizationParameters() {
        for (int f = 0; f < NUM_FEATURES; f++) {
            double sum = 0.0;
            for (const auto& point : trainSet) {
                sum += point.features[f];
            }
            featureMeans[f] = sum / trainSet.size();

            double variance = 0.0;
            for (const auto& point : trainSet) {
                variance += (point.features[f] - featureMeans[f]) * (point.features[f] - featureMeans[f]);
            }
            featureStds[f] = std::sqrt(variance / trainSet.size());
        }
    }

    // 数据标准化
    void normalizeData(std::vector<DataPoint>& data) {
        for (auto& point : data) {
            for (int f = 0; f < NUM_FEATURES; f++) {
                if (featureStds[f] > 0) {
                    point.features[f] = (point.features[f] - featureMeans[f]) / featureStds[f];
                }
            }
        }
    }

    // K近邻分类器实现
    class KNNClassifier {
    private:
        std::vector<DataPoint> trainingData;
        int k;

    public:
        KNNClassifier(int neighbors = 5) : k(neighbors) {}

        void train(const std::vector<DataPoint>& trainData) {
            trainingData = trainData;
        }

        int predict(const std::vector<double>& features) {
            std::vector<std::pair<double, int>> distances;

            // 计算到所有训练点的距离
            for (const auto& point : trainingData) {
                double distance = 0.0;
                for (size_t i = 0; i < features.size(); i++) {
                    distance += (features[i] - point.features[i]) * (features[i] - point.features[i]);
                }
                distance = std::sqrt(distance);
                distances.push_back({ distance, point.label });
            }

            // 按距离排序
            std::sort(distances.begin(), distances.end());

            // 统计前k个邻居的类别
            std::vector<int> votes(3, 0); // 3个类别
            for (int i = 0; i < k && i < distances.size(); i++) {
                votes[distances[i].second]++;
            }

            // 返回票数最多的类别
            return std::max_element(votes.begin(), votes.end()) - votes.begin();
        }
    };

    // 朴素贝叶斯分类器实现
    class NaiveBayesClassifier {
    private:
        std::vector<std::vector<double>> classMeans;  // [class][feature]
        std::vector<std::vector<double>> classVars;   // [class][feature]
        std::vector<double> classPriors;              // [class]

    public:
        NaiveBayesClassifier() {
            classMeans.resize(3, std::vector<double>(7, 0.0));
            classVars.resize(3, std::vector<double>(7, 0.0));
            classPriors.resize(3, 0.0);
        }

        void train(const std::vector<DataPoint>& trainData) {
            std::vector<std::vector<std::vector<double>>> classFeatures(3, std::vector<std::vector<double>>(7));
            std::vector<int> classCounts(3, 0);

            // 按类别分组特征数据
            for (const auto& point : trainData) {
                classCounts[point.label]++;
                for (int f = 0; f < 7; f++) {
                    classFeatures[point.label][f].push_back(point.features[f]);
                }
            }

            // 计算类别先验概率
            for (int c = 0; c < 3; c++) {
                classPriors[c] = static_cast<double>(classCounts[c]) / trainData.size();
            }

            // 计算每个类别每个特征的均值和方差
            for (int c = 0; c < 3; c++) {
                for (int f = 0; f < 7; f++) {
                    if (!classFeatures[c][f].empty()) {
                        // 计算均值
                        double sum = std::accumulate(classFeatures[c][f].begin(), classFeatures[c][f].end(), 0.0);
                        classMeans[c][f] = sum / classFeatures[c][f].size();

                        // 计算方差
                        double variance = 0.0;
                        for (double val : classFeatures[c][f]) {
                            variance += (val - classMeans[c][f]) * (val - classMeans[c][f]);
                        }
                        classVars[c][f] = variance / classFeatures[c][f].size();
                        if (classVars[c][f] < 1e-6) classVars[c][f] = 1e-6; // 避免除零
                    }
                }
            }
        }

        int predict(const std::vector<double>& features) {
            std::vector<double> logProbs(3, 0.0);

            for (int c = 0; c < 3; c++) {
                logProbs[c] = std::log(classPriors[c]);

                for (int f = 0; f < 7; f++) {
                    // 计算高斯概率密度的对数
                    double diff = features[f] - classMeans[c][f];
                    logProbs[c] -= 0.5 * std::log(2 * M_PI * classVars[c][f]);
                    logProbs[c] -= (diff * diff) / (2 * classVars[c][f]);
                }
            }

            return std::max_element(logProbs.begin(), logProbs.end()) - logProbs.begin();
        }
    };

    // 决策树分类器（简化版）
    class DecisionTreeClassifier {
    private:
        struct Node {
            int feature;
            double threshold;
            int prediction;
            bool isLeaf;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            Node() : feature(-1), threshold(0.0), prediction(-1), isLeaf(false) {}
        };

        std::unique_ptr<Node> root;

        double calculateGini(const std::vector<DataPoint>& data) {
            if (data.empty()) return 0.0;

            std::vector<int> counts(3, 0);
            for (const auto& point : data) {
                counts[point.label]++;
            }

            double gini = 1.0;
            for (int count : counts) {
                double prob = static_cast<double>(count) / data.size();
                gini -= prob * prob;
            }
            return gini;
        }

        std::pair<std::vector<DataPoint>, std::vector<DataPoint>> split(
            const std::vector<DataPoint>& data, int feature, double threshold) {
            std::vector<DataPoint> left, right;

            for (const auto& point : data) {
                if (point.features[feature] <= threshold) {
                    left.push_back(point);
                }
                else {
                    right.push_back(point);
                }
            }

            return { left, right };
        }

        std::unique_ptr<Node> buildTree(const std::vector<DataPoint>& data, int depth = 0) {
            auto node = std::make_unique<Node>();

            // 停止条件
            if (data.empty() || depth >= 5) {
                node->isLeaf = true;
                if (!data.empty()) {
                    std::vector<int> counts(3, 0);
                    for (const auto& point : data) {
                        counts[point.label]++;
                    }
                    node->prediction = std::max_element(counts.begin(), counts.end()) - counts.begin();
                }
                return node;
            }

            // 检查是否所有标签相同
            bool allSame = true;
            int firstLabel = data[0].label;
            for (const auto& point : data) {
                if (point.label != firstLabel) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                node->isLeaf = true;
                node->prediction = firstLabel;
                return node;
            }

            // 寻找最佳分割
            double bestGini = 1.0;
            int bestFeature = -1;
            double bestThreshold = 0.0;

            for (int f = 0; f < 7; f++) {
                std::vector<double> values;
                for (const auto& point : data) {
                    values.push_back(point.features[f]);
                }
                std::sort(values.begin(), values.end());

                for (size_t i = 1; i < values.size(); i++) {
                    double threshold = (values[i - 1] + values[i]) / 2.0;
                    auto [left, right] = split(data, f, threshold);

                    if (left.empty() || right.empty()) continue;

                    double gini = (left.size() * calculateGini(left) + right.size() * calculateGini(right)) / data.size();

                    if (gini < bestGini) {
                        bestGini = gini;
                        bestFeature = f;
                        bestThreshold = threshold;
                    }
                }
            }

            if (bestFeature == -1) {
                node->isLeaf = true;
                std::vector<int> counts(3, 0);
                for (const auto& point : data) {
                    counts[point.label]++;
                }
                node->prediction = std::max_element(counts.begin(), counts.end()) - counts.begin();
                return node;
            }

            node->feature = bestFeature;
            node->threshold = bestThreshold;

            auto [leftData, rightData] = split(data, bestFeature, bestThreshold);
            node->left = buildTree(leftData, depth + 1);
            node->right = buildTree(rightData, depth + 1);

            return node;
        }

        int predictNode(const std::vector<double>& features, const std::unique_ptr<Node>& node) {
            if (node->isLeaf) {
                return node->prediction;
            }

            if (features[node->feature] <= node->threshold) {
                return predictNode(features, node->left);
            }
            else {
                return predictNode(features, node->right);
            }
        }

    public:
        void train(const std::vector<DataPoint>& trainData) {
            root = buildTree(trainData);
        }

        int predict(const std::vector<double>& features) {
            if (!root) return 0;
            return predictNode(features, root);
        }
    };

    // 训练和评估模型
    void trainAndEvaluateModels() {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "模型训练和评估" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        // K近邻分类器
        std::cout << "\n训练 K近邻分类器 (k=5)..." << std::endl;
        KNNClassifier knn(5);
        knn.train(trainSet);
        double knnAccuracy = evaluateModel(knn, "K近邻");

        // 朴素贝叶斯分类器
        std::cout << "\n训练 朴素贝叶斯分类器..." << std::endl;
        NaiveBayesClassifier nb;
        nb.train(trainSet);
        double nbAccuracy = evaluateModel(nb, "朴素贝叶斯");

        // 决策树分类器
        std::cout << "\n训练 决策树分类器..." << std::endl;
        DecisionTreeClassifier dt;
        dt.train(trainSet);
        double dtAccuracy = evaluateModel(dt, "决策树");

        // 输出最终结果
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "模型性能总结" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        std::cout << "K近邻分类器准确率: " << std::fixed << std::setprecision(4) << knnAccuracy << std::endl;
        std::cout << "朴素贝叶斯分类器准确率: " << std::fixed << std::setprecision(4) << nbAccuracy << std::endl;
        std::cout << "决策树分类器准确率: " << std::fixed << std::setprecision(4) << dtAccuracy << std::endl;
    }

    // 评估模型性能
    template<typename Classifier>
    double evaluateModel(Classifier& classifier, const std::string& name) {
        int correct = 0;
        std::vector<int> predictions;

        for (const auto& testPoint : testSet) {
            int prediction = classifier.predict(testPoint.features);
            predictions.push_back(prediction);
            if (prediction == testPoint.label) {
                correct++;
            }
        }

        double accuracy = static_cast<double>(correct) / testSet.size();
        std::cout << name << " 准确率: " << std::fixed << std::setprecision(4) << accuracy << std::endl;

        // 显示混淆矩阵
        showConfusionMatrix(predictions, name);

        return accuracy;
    }

    // 显示混淆矩阵
    void showConfusionMatrix(const std::vector<int>& predictions, const std::string& modelName) {
        std::cout << "\n" << modelName << " 混淆矩阵:" << std::endl;

        // 初始化混淆矩阵
        std::vector<std::vector<int>> cm(3, std::vector<int>(3, 0));

        // 计算混淆矩阵
        for (size_t i = 0; i < testSet.size(); i++) {
            cm[testSet[i].label][predictions[i]]++;
        }

        // 显示混淆矩阵
        std::cout << "实际\\预测";
        for (int i = 0; i < 3; i++) {
            std::cout << std::setw(8) << classNames[i];
        }
        std::cout << std::endl;

        for (int i = 0; i < 3; i++) {
            std::cout << std::setw(10) << classNames[i];
            for (int j = 0; j < 3; j++) {
                std::cout << std::setw(8) << cm[i][j];
            }
            std::cout << std::endl;
        }

        // 计算精确率、召回率和F1分数
        std::cout << "\n分类报告:" << std::endl;
        std::cout << std::setw(10) << "类别" << std::setw(10) << "精确率"
            << std::setw(10) << "召回率" << std::setw(10) << "F1分数" << std::endl;
        std::cout << std::string(40, '-') << std::endl;

        for (int i = 0; i < 3; i++) {
            // 计算精确率
            int truePositive = cm[i][i];
            int falsePositive = 0;
            for (int j = 0; j < 3; j++) {
                if (j != i) falsePositive += cm[j][i];
            }
            double precision = (truePositive + falsePositive > 0) ?
                static_cast<double>(truePositive) / (truePositive + falsePositive) : 0.0;

            // 计算召回率
            int falseNegative = 0;
            for (int j = 0; j < 3; j++) {
                if (j != i) falseNegative += cm[i][j];
            }
            double recall = (truePositive + falseNegative > 0) ?
                static_cast<double>(truePositive) / (truePositive + falseNegative) : 0.0;

            // 计算F1分数
            double f1 = (precision + recall > 0) ? 2 * precision * recall / (precision + recall) : 0.0;

            std::cout << std::setw(10) << classNames[i]
                << std::setw(10) << std::fixed << std::setprecision(3) << precision
                    << std::setw(10) << recall
                    << std::setw(10) << f1 << std::endl;
        }
    }

    // 运行完整分析
    void runCompleteAnalysis(const std::string& dataPath) {
        std::cout << "开始小麦种子分类分析..." << std::endl;

        // 加载数据
        if (!loadData(dataPath)) {
            std::cout << "数据加载失败，程序终止" << std::endl;
            return;
        }

        // 数据探索
        exploreData();

        // 数据预处理
        preprocessData();

        // 训练和评估模型
        trainAndEvaluateModels();

        std::cout << "\n分析完成!" << std::endl;
    }
};

// 主函数
int main() {
    // 设置控制台输出编码为UTF-8（Windows系统）
#ifdef _WIN32
    system("chcp 65001");
#endif

    // 数据文件路径 - 请根据实际情况修改
    std::string dataPath = "seeds_dataset.txt";

    // 创建分类器实例
    WheatSeedsClassifier classifier;

    // 运行完整分析
    classifier.runCompleteAnalysis(dataPath);

    // 等待用户输入后退出
    std::cout << "\n按任意键退出..." << std::endl;
    std::cin.get();

    return 0;
}