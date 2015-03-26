#include<bits/stdc++.h>
#define INF (1 << 30)
#define NR (1 << 16)
using namespace std;
typedef long long ll;

static const int MOD = 1000000009;

struct YetAnotherORProblem2
{
  int dp[11][NR];
  int countSequences(int N, int R)
  {
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
    {
      for(int j = 0; j < NR; j++)
      {
        for(int k = j; k >= 0; k--)
        {
          k &= j;
          if(k <= R)
            dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
        }
      }
    }
    int a = 0;
    for(int i = 0; i < NR; i++)
      a = (a + dp[N][i]) % MOD;
    return a;
  }
};

// CUT begin
ifstream data("YetAnotherORProblem2.sample");

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

bool do_test(int N, int R, int __expected) {
    time_t startClock = clock();
    YetAnotherORProblem2 *instance = new YetAnotherORProblem2();
    int __result = instance->countSequences(N, R);
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
        int N;
        from_stream(N);
        int R;
        from_stream(R);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427360132;
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
        cout << "YetAnotherORProblem2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
