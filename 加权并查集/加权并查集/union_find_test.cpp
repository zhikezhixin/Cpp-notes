/*
 * Weighted Union-Find Performance Test System
 * Compiler: Visual Studio 2022
 * Standard: C++17
 *
 * No Chinese characters - Perfect for VS2022
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;
using namespace std::chrono;

// ==================== Console Color ====================
class ConsoleColor {
public:
    static void SetColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
    static void Reset() { SetColor(7); }
    static void Red() { SetColor(12); }
    static void Green() { SetColor(10); }
    static void Yellow() { SetColor(14); }
    static void Cyan() { SetColor(11); }
    static void Magenta() { SetColor(13); }
};

// ==================== Union-Find Implementation ====================

enum class CompressionMode {
    NONE,
    FULL,
    HALVE,
    SPLIT
};

typedef CompressionMode CPM;

template<class NODE, CPM M>
struct FindPolicy;

template<class NODE>
struct FindPolicy<NODE, CPM::NONE> {
    static NODE apply(vector<NODE>& parent, NODE cur) {
        while (parent[cur] != cur)
            cur = parent[cur];
        return cur;
    }
};

template<class NODE>
struct FindPolicy<NODE, CPM::FULL> {
    static NODE apply(vector<NODE>& parent, NODE cur) {
        NODE x = cur;
        while (parent[x] != x) x = parent[x];
        while (parent[cur] != cur) {
            NODE p = parent[cur];
            parent[cur] = x;
            cur = p;
        }
        return x;
    }
};

template<class NODE>
struct FindPolicy<NODE, CPM::HALVE> {
    static NODE apply(vector<NODE>& parent, NODE cur) {
        while (parent[cur] != cur) {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }
};

template<class NODE>
struct FindPolicy<NODE, CPM::SPLIT> {
    static NODE apply(vector<NODE>& parent, NODE cur) {
        while (parent[cur] != cur) {
            NODE p = parent[cur];
            NODE gp = parent[p];
            parent[cur] = gp;
            cur = p;
        }
        return cur;
    }
};

template<class NodeType, CPM mode = CPM::FULL>
class WUFS {
public:
    WUFS(size_t n) : _SetQuantity(n), _findCount(0), _unionCount(0),
        _pathLengthSum(0), _maxPathLength(0) {
        _parent.resize(n);
        _SetSize.resize(n, 1);
        for (size_t i = 0; i < n; i++) {
            _parent[i] = i;
        }
    }

    size_t FindRoot(size_t x) {
        _findCount++;
        size_t pathLen = 0;
        size_t cur = x;
        while (_parent[cur] != cur) {
            cur = _parent[cur];
            pathLen++;
        }
        _pathLengthSum += pathLen;
        if (pathLen > _maxPathLength) {
            _maxPathLength = pathLen;
        }
        return FindPolicy<size_t, mode>::apply(_parent, x);
    }

    bool Union(size_t n1, size_t n2) {
        if (n1 == n2) return false;
        _unionCount++;
        size_t root_n1 = FindRoot(n1);
        size_t root_n2 = FindRoot(n2);
        if (root_n1 == root_n2) return false;

        if (_SetSize[root_n1] < _SetSize[root_n2]) {
            _SetSize[root_n2] += _SetSize[root_n1];
            _parent[root_n1] = root_n2;
        }
        else {
            _SetSize[root_n1] += _SetSize[root_n2];
            _parent[root_n2] = root_n1;
        }
        _SetQuantity--;
        return true;
    }

    bool SameSet(size_t n1, size_t n2) {
        return FindRoot(n1) == FindRoot(n2);
    }

    size_t GetSetQuantity() const { return _SetQuantity; }
    size_t GetFindCount() const { return _findCount; }
    size_t GetUnionCount() const { return _unionCount; }
    double GetAvgPathLength() const {
        return _findCount > 0 ? static_cast<double>(_pathLengthSum) / _findCount : 0.0;
    }
    size_t GetMaxPathLength() const { return _maxPathLength; }

private:
    vector<size_t> _parent;
    vector<size_t> _SetSize;
    size_t _SetQuantity;
    size_t _findCount;
    size_t _unionCount;
    size_t _pathLengthSum;
    size_t _maxPathLength;
};

// ==================== Test Framework ====================

string ModeToString(CPM mode) {
    switch (mode) {
    case CPM::NONE: return "No Compression";
    case CPM::FULL: return "Full Compression";
    case CPM::HALVE: return "Path Halving";
    case CPM::SPLIT: return "Path Splitting";
    default: return "Unknown";
    }
}

struct TestResult {
    string modeName;
    size_t dataSize;
    double timeElapsed;
    size_t findCount;
    size_t unionCount;
    double avgPathLength;
    size_t maxPathLength;
    size_t finalSetCount;
};

class PerformanceTester {
public:
    PerformanceTester() : gen(random_device{}()) {}

    template<CPM Mode>
    TestResult TestRandomUnions(size_t size, double unionRatio = 0.8) {
        ConsoleColor::Cyan();
        cout << "\nTest: " << ModeToString(Mode)
            << " | Size: " << size
            << " | Union Ratio: " << static_cast<int>(unionRatio * 100) << "%" << endl;
        ConsoleColor::Reset();

        WUFS<size_t, Mode> ufs(size);
        size_t numOperations = size * 2;
        size_t numUnions = static_cast<size_t>(numOperations * unionRatio);
        size_t numQueries = numOperations - numUnions;

        vector<pair<size_t, size_t>> operations;
        operations.reserve(numUnions);
        for (size_t i = 0; i < numUnions; i++) {
            operations.push_back(make_pair(RandomInt(size), RandomInt(size)));
        }

        auto start = high_resolution_clock::now();

        for (const auto& op : operations) {
            ufs.Union(op.first, op.second);
        }
        for (size_t i = 0; i < numQueries; i++) {
            ufs.SameSet(RandomInt(size), RandomInt(size));
        }

        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        TestResult result;
        result.modeName = ModeToString(Mode);
        result.dataSize = size;
        result.timeElapsed = elapsed.count();
        result.findCount = ufs.GetFindCount();
        result.unionCount = ufs.GetUnionCount();
        result.avgPathLength = ufs.GetAvgPathLength();
        result.maxPathLength = ufs.GetMaxPathLength();
        result.finalSetCount = ufs.GetSetQuantity();

        PrintResult(result);
        return result;
    }

    template<CPM Mode>
    TestResult TestWorstCase(size_t size) {
        ConsoleColor::Cyan();
        cout << "\nTest (Worst Case): " << ModeToString(Mode)
            << " | Size: " << size << endl;
        ConsoleColor::Reset();

        WUFS<size_t, Mode> ufs(size);
        auto start = high_resolution_clock::now();

        for (size_t i = 0; i < size - 1; i++) {
            ufs.Union(i, i + 1);
        }
        for (size_t i = 0; i < size; i++) {
            ufs.SameSet(0, RandomInt(size));
        }

        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        TestResult result;
        result.modeName = ModeToString(Mode);
        result.dataSize = size;
        result.timeElapsed = elapsed.count();
        result.findCount = ufs.GetFindCount();
        result.unionCount = ufs.GetUnionCount();
        result.avgPathLength = ufs.GetAvgPathLength();
        result.maxPathLength = ufs.GetMaxPathLength();
        result.finalSetCount = ufs.GetSetQuantity();

        PrintResult(result);
        return result;
    }

    void RunComprehensiveTest() {
        ConsoleColor::Yellow();
        cout << "\n" << string(70, '=') << endl;
        cout << "  Weighted Union-Find Performance Test" << endl;
        cout << string(70, '=') << endl;
        ConsoleColor::Reset();

        vector<size_t> sizes = { 1000, 5000, 10000, 50000 };

        ConsoleColor::Green();
        cout << "\n[Scenario 1] Random Union Test" << endl;
        ConsoleColor::Reset();

        for (size_t size : sizes) {
            cout << "\n" << string(70, '-') << endl;
            cout << "Data Size: " << size << endl;
            cout << string(70, '-') << endl;

            allResults.push_back(TestRandomUnions<CPM::NONE>(size));
            allResults.push_back(TestRandomUnions<CPM::FULL>(size));
            allResults.push_back(TestRandomUnions<CPM::HALVE>(size));
            allResults.push_back(TestRandomUnions<CPM::SPLIT>(size));
        }

        ConsoleColor::Green();
        cout << "\n\n[Scenario 2] Worst Case Test (Chain Structure)" << endl;
        ConsoleColor::Reset();

        cout << "\n" << string(70, '-') << endl;
        cout << "Data Size: 10000" << endl;
        cout << string(70, '-') << endl;

        allResults.push_back(TestWorstCase<CPM::NONE>(10000));
        allResults.push_back(TestWorstCase<CPM::FULL>(10000));
        allResults.push_back(TestWorstCase<CPM::HALVE>(10000));
        allResults.push_back(TestWorstCase<CPM::SPLIT>(10000));

        GenerateCSVReport();
        GenerateSummary();
    }

private:
    mt19937 gen;
    vector<TestResult> allResults;

    size_t RandomInt(size_t max_val) {
        uniform_int_distribution<size_t> dist(0, max_val - 1);
        return dist(gen);
    }

    void PrintResult(const TestResult& result) {
        cout << fixed << setprecision(6);
        cout << "  Time Elapsed: " << result.timeElapsed << " seconds" << endl;
        cout << "  Avg Path Length: " << result.avgPathLength << endl;
        cout << "  Max Path Length: " << result.maxPathLength << endl;
        cout << "  Final Set Count: " << result.finalSetCount << endl;
        cout << "  Find Operations: " << result.findCount << endl;
        cout << "  Union Operations: " << result.unionCount << endl;
    }

    void GenerateCSVReport() {
        ofstream file("performance_report.csv");
        if (!file.is_open()) {
            ConsoleColor::Red();
            cout << "\nError: Cannot create CSV file" << endl;
            ConsoleColor::Reset();
            return;
        }

        file << "Strategy,DataSize,TimeElapsed(s),FindCount,UnionCount,"
            << "AvgPathLength,MaxPathLength,FinalSetCount\n";

        for (const auto& r : allResults) {
            file << r.modeName << ","
                << r.dataSize << ","
                << fixed << setprecision(6) << r.timeElapsed << ","
                << r.findCount << ","
                << r.unionCount << ","
                << fixed << setprecision(2) << r.avgPathLength << ","
                << r.maxPathLength << ","
                << r.finalSetCount << "\n";
        }
        file.close();

        ConsoleColor::Green();
        cout << "\n✓ CSV Report Generated: performance_report.csv" << endl;
        ConsoleColor::Reset();
    }

    void GenerateSummary() {
        ConsoleColor::Yellow();
        cout << "\n" << string(70, '=') << endl;
        cout << "  Performance Test Summary" << endl;
        cout << string(70, '=') << endl;
        ConsoleColor::Reset();

        map<size_t, map<string, double>> sizeStats;
        for (const auto& r : allResults) {
            sizeStats[r.dataSize][r.modeName] = r.timeElapsed;
        }

        cout << "\nFastest Strategy for Each Size:" << endl;
        for (const auto& sizeEntry : sizeStats) {
            size_t size = sizeEntry.first;
            const auto& modeMap = sizeEntry.second;

            string fastest;
            double minTime = 1e9;
            for (const auto& modeEntry : modeMap) {
                if (modeEntry.second < minTime) {
                    minTime = modeEntry.second;
                    fastest = modeEntry.first;
                }
            }

            ConsoleColor::Cyan();
            cout << "  N=" << size << ": " << fastest
                << " (" << fixed << setprecision(6) << minTime << "s)" << endl;
            ConsoleColor::Reset();
        }

        cout << "\nSpeedup (Full Compression vs No Compression):" << endl;
        for (const auto& sizeEntry : sizeStats) {
            const auto& modeMap = sizeEntry.second;
            auto noneIt = modeMap.find("No Compression");
            auto fullIt = modeMap.find("Full Compression");

            if (noneIt != modeMap.end() && fullIt != modeMap.end()) {
                double speedup = noneIt->second / fullIt->second;
                ConsoleColor::Green();
                cout << "  N=" << sizeEntry.first << ": "
                    << fixed << setprecision(2) << speedup << "x" << endl;
                ConsoleColor::Reset();
            }
        }

        ConsoleColor::Yellow();
        cout << "\n" << string(70, '=') << endl;
        cout << "Test Complete! All data saved." << endl;
        cout << string(70, '=') << endl;
        ConsoleColor::Reset();
    }
};

// ==================== Main ====================

int main() {
    ConsoleColor::Magenta();
    cout << "\n╔══════════════════════════════════════════════════════╗" << endl;
    cout << "║   Weighted Union-Find Performance Test System   ║" << endl;
    cout << "║          Visual Studio 2022 Version          ║" << endl;
    cout << "╚══════════════════════════════════════════════════════╝\n" << endl;
    ConsoleColor::Reset();

    PerformanceTester tester;
    tester.RunComprehensiveTest();

    ConsoleColor::Yellow();
    cout << "\nPress any key to exit..." << endl;
    ConsoleColor::Reset();
    system("pause > nul");

    return 0;
}