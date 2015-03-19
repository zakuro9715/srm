#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

static const int MOD = 1000000007;

class FoxAverageSequence
{
  vector<int> S;
  int dp[41][1700][41][2], N;
  int dfs(int n, int s, int b, bool f)
  {
    if(n == N)
      return 1;
    if(dp[n][s][b][f] != INF)
      return dp[n][s][b][f];
    
    double a = n == 0 ? INF : s / (double)n;
    if(S[n] != -1)
    {
      if(f && b > S[n] || a < S[n])
        return 0;
      return dp[n][s][b][f] = dfs(n + 1, s + S[n], S[n], b > S[n]) % MOD;
    }
    
    ll res = 0;
    for(int i = 0; i <= min(a, 40.1); i++)
      if(!(f && b > i))
        res += dfs(n + 1, s + i, i, b > i);
    return dp[n][s][b][f] = res % MOD;
  }
public:
  int theCount(vector<int> seq)
  {
    S = seq; N = seq.size();
    fill((int*)dp, (int*)dp + 41 * 1700 * 41 * 2, INF);
    return dfs(0, 0, 0, false);
  }
};

// CUT begin
ifstream data("FoxAverageSequenceEasy.sample");

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

bool do_test(vector<int> seq, int __expected) {
    time_t startClock = clock();
    FoxAverageSequence *instance = new FoxAverageSequence();
    int __result = instance->theCount(seq);
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
        vector<int> seq;
        from_stream(seq);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(seq, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426778781;
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
        cout << "FoxAverageSequenceEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
