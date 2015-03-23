#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;
typedef pair<double, int> P;

struct KingdomXCitiesandVillagesAnother
{
  double dis(int x1, int y1, int x2, int y2)
  {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  }
  double dp[100][2], c[100], g[100][100];
  bool done[100];
  double determineLength(vector<int> cx, vector<int> cy, vector<int> vx, vector<int> vy)
  {
    fill(c, c + 200, INF);
    fill((double*)g, (double*)g + 100 * 100, INF);
    for(int i = 0; i < vx.size(); i++)
    {
      for(int j = 0; j < cx.size(); j++)
        c[i] = min(c[i], dis(vx[i], vy[i], cx[j], cy[j]));
    }
    for(int i = 0; i < vx.size(); i++)
      for(int j = 0; j < vx.size(); j++)
        if(i != j)
          g[i][j] = dis(vx[i], vy[i], vx[j], vy[j]);

    priority_queue<P, vector<P>, greater<P> > q;
    for(int i = 0; i < vx.size(); i++)
      q.push(P(c[i], i));
    double ans = 0;
    while(q.size())
    {
      P p = q.top(); q.pop();
      int i = p.second;
      if(done[i])
        continue;
      done[i] = true;
      ans += p.first;
      for(int j = 0; j < vx.size(); j++)
        if(g[i][j] != INF && !done[j])
          q.push(P(g[i][j], j));
    }
    return ans;
  }
};

// CUT begin
ifstream data("KingdomXCitiesandVillagesAnother.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<int> cityX, vector<int> cityY, vector<int> villageX, vector<int> villageY, double __expected) {
    time_t startClock = clock();
    KingdomXCitiesandVillagesAnother *instance = new KingdomXCitiesandVillagesAnother();
    double __result = instance->determineLength(cityX, cityY, villageX, villageY);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        vector<int> cityX;
        from_stream(cityX);
        vector<int> cityY;
        from_stream(cityY);
        vector<int> villageX;
        from_stream(villageX);
        vector<int> villageY;
        from_stream(villageY);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cityX, cityY, villageX, villageY, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427095894;
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
        cout << "KingdomXCitiesandVillagesAnother (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
