#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>

using namespace std;

class Fragile2 {
    bool g[20][20];
    bool mem[100];
    int N;

    void bfs(int st)
    {
      queue<int> q;
      q.push(st);
      mem[st] = true;
      while(!q.empty())
      {
        int n = q.front(); q.pop();
        for(int i = 0; i < 20; i++)
        {
          if(!g[n][i])
            continue;
          if(mem[i])
            continue;
          mem[i] = true;
          q.push(i);
        }
      }
    }

    int count(int x1, int x2)
    {
      for(int i = 0; i < N; i++)
        mem[i] = false;
      mem[x1] = mem[x2] = true;
      int cnt = 0;
      for(int i = 0; i < N; i++)
      {
        if(mem[i])
          continue;
        cnt++;
        bfs(i);
      }
      return cnt;
    }

    public:
    int countPairs(vector<string> graph) {
      N = graph.size();
      for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
          g[i][j] = graph[i][j] == 'Y';
      int ini = count(50, 50);
      int ans = 0;
      for(int i = 0; i < N; i++)
      {
        for(int j = i + 1; j < N; j++)
        {
          if(count(i, j) > ini)
            ans++;
        }
      }
      return ans;
    }
};

// CUT begin
ifstream data("Fragile2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> graph, int __expected) {
    time_t startClock = clock();
    Fragile2 *instance = new Fragile2();
    int __result = instance->countPairs(graph);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> graph;
        from_stream(graph);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(graph, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1422878966;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "Fragile2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end