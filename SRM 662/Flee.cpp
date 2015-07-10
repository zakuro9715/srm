#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

#define PI 3.141592

int winding_number(double x, double y, double p[][2], int n)
{
  double x1 = p[n - 1][0] - x, y1 = p[n - 1][1] - y;
  double s = 0;
  for(int i = 0; i < n; i++)
  {
    double x2 = p[i][0] - x, y2 = p[i][1] - y;
    double tx = acos((x1 * x2 + y1 * y2) / sqrt((x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2)));
    s += tx;
    x1 = x2; y1 = y2;
  }
  return (abs(s) + 0.000001) / 2 / PI;
}



struct Flee
{
  double p[3][2];
  double maximalSafetyLevel(vector<int> x, vector<int> y)
  {
    double s = 1000000000000;
    for(int i = 0; i < x.size(); i++)
    {
      p[i][0] = x[i];
      p[i][1] = y[i];
      s = min(s, sqrt(x[i] * x[i] + y[i] * y[i]));
    }
    if(x.size() < 3 || !winding_number(0, 0, p, 3))
      return s;
    double a = 0;
    for(int i = 0; i < x.size(); i++)
    {
      int i2 = (i + 1) % x.size();
      int dx = x[i] - x[i2], dy = y[i] - y[i2];
      a = max(a, sqrt(dx * dx + dy * dy) / 2);
    }
    return min(a, s);
  }
};

// CUT begin
ifstream data("Flee.sample");

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

bool do_test(vector<int> x, vector<int> y, double __expected) {
    time_t startClock = clock();
    Flee *instance = new Flee();
    double __result = instance->maximalSafetyLevel(x, y);
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
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1436491377;
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
        cout << "Flee (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
