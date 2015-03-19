#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

class ElephantDrinkingEasy
{
  int H, W;
  int b[20];
  bool f[5][5];
  int near[20];
  
  bool filll(int x1, int y1, int x2, int y2)
  {
    if(x1 > x2)
      swap(x1, x2);
    if(y1 > y2)
      swap(y1, y2);
    for(int y = y1; y < y2 + 1; y++)
    {
      for(int x = x1; x < x2 + 1; x++)
      {
        if(f[y][x])
          return false;
        f[y][x] = true;
      }
    }
    return true;
  }
public:
  int maxElephants(vector<string> field)
  {
    H = field.size(); W = field[0].size();
    int n = (int)pow(2, 2 * (H + W));
    
    fill(near, near + 20, INF);
    
    for(int y = 0; y < H; y++)
    {
      for(int x = 0; x < W; x++)
      {
        if(near[x] == INF && field[y][x] == 'Y')
          near[x] = y;
        if(near[W + x] == INF && field[H - y - 1][x] == 'Y')
          near[W + x] = H - y - 1;
        if(near[W + W + y] == INF && field[y][x] == 'Y')
          near[W + W + y] = x;
        if(near[W + W + H + y] == INF && field[y][W - x - 1] == 'Y')
          near[W + W + H + y] = W - x - 1;
      }
    }
    int ans = 0;
    for(int p = 0; p < n; p++)
    {
      fill((bool*)f, (bool*)f + 25, false);
      int cnt = 0;
      for(int i = 0; i < 2 * (H + W); i++)
      {
        b[i] = 1 << i & p;
        if(b[i])
          cnt++;
      }
      bool ok = true;
      for(int i = 0; i < 2 * (H + W); i++)
      {
        if(!b[i])
          continue;
        if(near[i] == INF)
          ok = false;
        else if(i < W)
          ok &= filll(i, 0, i, near[i]);
        else if(i < 2 * W)
          ok &= filll(i % W, near[i], i % W, H - 1);
        else if(i < 2 * W + H)
          ok &= filll(0, i - 2 * W, near[i], i - 2 * W);
        else
          ok &= filll(near[i], (i - 2 * W) % H, W - 1, (i - 2 * W) % H);
        if(!ok)
          break;
      }
      if(ok)
        ans = max(ans, cnt);
    }
    return ans;
  }
};

// CUT begin
ifstream data("ElephantDrinkingEasy.sample");

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

bool do_test(vector<string> map, int __expected) {
    time_t startClock = clock();
    ElephantDrinkingEasy *instance = new ElephantDrinkingEasy();
    int __result = instance->maxElephants(map);
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
        vector<string> map;
        from_stream(map);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(map, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426758018;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ElephantDrinkingEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
