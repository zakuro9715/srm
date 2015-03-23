#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct RectangleArea
{

  int par[1000];
  int find(int n)
  {
    return par[n] == n ? n : find(par[n]);
  }
  void unite(int a, int b)
  {
    int aa = find(a), bb = find(b);
    if(aa == bb)
      return;
    par[aa] = bb;
  }

  int minimumQueries(vector<string> known)
  {
    int H = known.size(), W = known[0].size();
    for(int i = 0; i < W + H; i++)
      par[i] = i;
    for(int y = 0; y < H; y++)
    {
      for(int x = 0; x < W; x++)
      {
        if(known[y][x] == 'Y')
        {
          for(int i = 0; i < H; i++)
            if(known[i][x] == 'Y')
              unite(x, W + i);
          for(int i = 0; i < W; i++)
            if(known[y][i] == 'Y')
              unite(W + y, i);
        }
      }
    }
    set<int> s;
    for(int i = 0; i < W + H; i++)
      s.insert(find(i));
    return s.size() - 1;
  }
};

// CUT begin
ifstream data("RectangleArea.sample");

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

bool do_test(vector<string> known, int __expected) {
    time_t startClock = clock();
    RectangleArea *instance = new RectangleArea();
    int __result = instance->minimumQueries(known);
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
        vector<string> known;
        from_stream(known);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(known, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427126235;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "RectangleArea (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
