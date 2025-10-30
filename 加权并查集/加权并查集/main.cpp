#include "WeightedUnionFind.h"
#include <chrono>
using namespace std;
using namespace chrono;

void test1()
{
    // ===== 1. 定义初始节点 =====
    vector<string> nodes = { "安徽省", "浙江省", 
                             "合肥", "安庆",
                             "杭州", "绍兴", "余姚" };

    // ===== 2. 构造并查集对象 =====
    WUFS<string, CPM::HALVE> uf(nodes); 

    // ===== 3. 建立省份与城市的合并关系 =====
    vector<pair<string, string>> edges = 
    {   {"安徽省", "合肥"},{"安徽省", "安庆"},
        {"浙江省", "杭州"}, {"浙江省", "绍兴" } , {"浙江省", "余姚" }  };

    for (auto& e : edges)
        uf.Union(e.first, e.second);

    // ===== 4. 打印当前集合划分 =====
    PrintSet(uf, nodes);

    // ===== 5. 输出集合数量 =====
    cout << "\n当前集合数量：" << uf.GetSetQuantity() << endl;

}

void test2()
{
    vector<string> users = { "A","B","C","D","E","F" };
    WUFS<string, CPM::HALVE> uf(users);

    vector<pair<string, string>> edges = { {"A","B"},{"B","C"},{"E","F"} };
    for (auto& e : edges) uf.Union(e.first, e.second);

    PrintSet(uf, users);

    cout << "连通块数量: " << uf.GetSetQuantity() << "\n";

    cout << boolalpha; 
    cout << "A 和 C 同集合？ " << uf.SameSet("A", "C") << '\n';
    cout << "A 和 F 同集合？ " << uf.SameSet("A", "F") << '\n';
}


void test_mode()
{
   
    cout << "======== 四种路径压缩方式性能测试 ========\n";

    // 1. 随机生成节点数据
    random_device seed;
    mt19937 gen(seed());
    uniform_real_distribution<> dist(0.0, 1.0);

    const size_t N = 10000;   // 节点数量
    vector<double> numbers;
    numbers.reserve(N);
    for (size_t i = 0; i < N; ++i)
        numbers.push_back(dist(gen));

    // 2. 构造四种并查集对象
    WUFS<double, CPM::NONE>  wufs_NONE(numbers);
    WUFS<double, CPM::FULL>  wufs_FULL(numbers);
    WUFS<double, CPM::HALVE> wufs_HALVE(numbers);
    WUFS<double, CPM::SPLIT> wufs_SPLIT(numbers);

    // 3. 随机生成 Union 操作
    uniform_int_distribution<int> idx_dist(0, N - 1);
    vector<pair<int, int>> edges;
    edges.reserve(N * 2);
    for (int i = 0; i < N * 2; ++i)
        edges.emplace_back(idx_dist(gen), idx_dist(gen));

    // 4. 定义计时函数
    auto measure = [&](auto& uf, const string& mode_name) 
        {
        auto start = steady_clock::now();
        for (auto& e : edges)
            uf.Union(numbers[e.first], numbers[e.second]);
        // 每次执行若干 FindRoot 操作以触发路径压缩
        for (int i = 0; i < N; ++i)
            uf.FindRoot(i);
        auto end = steady_clock::now();
        double ms = duration<double, milli>(end - start).count();
        cout << mode_name << " 模式耗时: " << ms << " ms\n";
        };

    // 5. 依次测试四种压缩模式
    measure(wufs_NONE, "无路径压缩 (NONE)");
    measure(wufs_FULL, "完全压缩 (FULL)");
    measure(wufs_HALVE, "折半压缩 (HALVE)");
    measure(wufs_SPLIT, "分裂压缩 (SPLIT)");

    cout << "==========================================\n";

}


int main()
{
    //test1();
    //test2();
    test_mode();
    return 0;
}
