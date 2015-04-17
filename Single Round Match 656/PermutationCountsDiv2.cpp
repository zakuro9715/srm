#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

static const int MOD = 1000000007;

struct PermutationCountsDiv2
{
  bool r[200];
  ll dp[200][200], pdp[200][200], s[100];
  int sn;

  ll p(int n, int r)
  {
    if(pdp[n][r] != -1)
      return pdp[n][r];
    ll a = 1;
    for(int i = r + 1; i < n; i++)
      a = (a * i) % MOD;
    return pdp[n][r] = a;
  }

  ll dfs(int n, int x)
  {
    if(n == sn)
      return 1;
    cout << n << " " << x << endl;
    if(dp[n][x] != -1)
      return dp[n][x];
    int a = 0;
    for(int i = 0; i < x - s[n]; i++)
      a = (a + dfs(n + 1, x - s[n] - 1)) % MOD;
    return dp[n][x] = a;
  }
  
  int countPermutations(int N, vector<int> pos)
  {
    fill((ll*)pdp, (ll*)pdp + 200 * 200, -1);
    fill((ll*)dp, (ll*)dp + 200 * 200, -1);
    for(int i = 0; i < pos.size(); i++)
      r[pos[i] - 1] = true;
    bool b = false;
    sn = 0;
    for(int i = 0; i < N;)
    {
      int st = i;
      while(i < N && (b && r[i] || !r[i]))
        i++;
      b = !b;
      s[sn++] = i  - st;
      cout << i  - st << endl;
    }
    cout << endl;
    ll a = 0;
    for(int i = 0; i < N; i++)
      a = (a + dfs(a, N - i)) % MOD;
    return a;
  }
};

// CUT begin
ifstream data("PermutationCountsDiv2.sample");

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

bool do_test(int N, vector<int> pos, int __expected) {
    time_t startClock = clock();
    PermutationCountsDiv2 *instance = new PermutationCountsDiv2();
    int __result = instance->countPermutations(N, pos);
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
        vector<int> pos;
        from_stream(pos);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, pos, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1429270741;
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
        cout << "PermutationCountsDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
