#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

static const int MOD = 1000000007;

class VocaloidsAndSongs
{
  ll dp[51][51][51][51];
  ll dfs(int s, int g, int i, int m)
  {
    if(g < 0 || i < 0 || m < 0)
      return 0;
    if(dp[s][g][i][m] != INF)
      return dp[s][g][i][m];
    if(!s)
      return !g && !i && !m ? 1 : 0;
    return dp[s][g][i][m] = (
      + dfs(s - 1, g - 1, i - 1, m - 1)
      + dfs(s - 1, g - 1, i - 1, m)
      + dfs(s - 1, g, i - 1, m - 1)
      + dfs(s - 1, g - 1, i, m - 1)
      + dfs(s - 1, g - 1, i, m)
      + dfs(s - 1, g, i - 1, m)
      + dfs(s - 1, g, i, m - 1)
    ) % MOD;
  }
public:
  int count(int S, int gumi, int ia, int mayu)
  {
    for(int i = 0; i < 51; i++)
      for(int i2 = 0; i2 < 51; i2++)
        for(int i3 = 0; i3 < 51; i3++)
          for(int i4 = 0; i4 < 51; i4++)
            dp[i][i2][i3][i4] = INF;
    return dfs(S, gumi, ia, mayu);
  }
};

// CUT begin
ifstream data("VocaloidsAndSongs.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int S, int gumi, int ia, int mayu, int __expected) {
    time_t startClock = clock();
    VocaloidsAndSongs *instance = new VocaloidsAndSongs();
    int __result = instance->count(S, gumi, ia, mayu);
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
        int S;
        from_stream(S);
        int gumi;
        from_stream(gumi);
        int ia;
        from_stream(ia);
        int mayu;
        from_stream(mayu);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, gumi, ia, mayu, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426672139;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "VocaloidsAndSongs (950 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
