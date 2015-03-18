#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

class MiningGoldEasy
{
  vector<int> ei, ej, eei, eej, pi, pj;
  int N, M, D, dp[100][100][100];
public:
  int cal(int d, int i, int j)
  {
    if(d == D)
      return 0;
    return (N + M) - abs(ei[d] - pi[i]) - abs(ej[d] - pj[j]);
  }

  int dfs(int d, int i, int j)
  {
    if(d == D)
      return 0;
    if(dp[d][i][j] != -1)
      return dp[d][i][j];
    int ans = 0;
    for(int a = 0; a < eei.size(); a++)
      ans = max(ans, max(dfs(d + 1, eei[a], j), dfs(d + 1, i, eej[a])) + cal(d, i, j));
    return dp[d][i][j] = ans;
  }

  int GetMaximumGold(int n, int m, vector<int> event_i, vector<int> event_j)
  {
    N = n; M = m; ei = event_i, ej = event_j; D = ei.size();
    for(int i = 0; i < ei.size(); i++)
    {
      pi.push_back(ei[i]);
      pj.push_back(ej[i]);
    }
    sort(pi.begin(), pi.end());
    sort(pj.begin(), pj.end());
    
    pi.erase(unique(pi.begin(), pi.end()), pi.end());
    pj.erase(unique(pj.begin(), pj.end()), pj.end()); 
   
    for(int i = 0; i < ei.size(); i++)
      for(int j = 0; j < pi.size(); j++)
        if(ei[i] == pi[j])
          eei.push_back(j);
    for(int i = 0; i < ej.size(); i++)
      for(int j = 0; j < pj.size(); j++)
        if(ej[i] == pj[j])
          eej.push_back(j);
    fill((int*)dp, (int*)dp + 100 * 100 * 100, -1);
    int a = -1;
    for(int i = 0; i < pi.size(); i++)
      for(int j = 0; j < pj.size(); j++)
        a = max(a, dfs(0, i, j));
    return a;
  }
};

// CUT begin
ifstream data("MiningGoldEasy.sample");

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

bool do_test(int N, int M, vector<int> event_i, vector<int> event_j, int __expected) {
    time_t startClock = clock();
    MiningGoldEasy *instance = new MiningGoldEasy();
    int __result = instance->GetMaximumGold(N, M, event_i, event_j);
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
        int M;
        from_stream(M);
        vector<int> event_i;
        from_stream(event_i);
        vector<int> event_j;
        from_stream(event_j);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, M, event_i, event_j, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426676121;
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
        cout << "MiningGoldEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
