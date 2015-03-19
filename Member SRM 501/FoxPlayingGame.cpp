#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

class FoxPlayingGame
{
public:
  double theMax(int nA, int nB, int paramA, int paramB)
  {
    double A = paramA / 1000.0, B = paramB / 1000.0;
    double sb = 1, sa = 0;
    for(int i = 0; i < nB; i++)
      sb *= B;
    for(int i = 0; i < nA; i++)
      sa += A;
    if(!nA) A = 0; if(!nB) B = 0;
    if(sa > 0)
    {
      if(sb < 0)
        sb /= B;
      if(sb >= 1)
        return sa * sb;
      return sa;
    }
    else
    {
      if(B >= 0)
      {
        if(sb >= 1)
          return sa;
        return sa * sb;
      }
      if(sb > 0)
        sb /= B;
      if(sb >= -1)
        return sa * B;
      return sa * sb;
    }
  }
};

// CUT begin
ifstream data("FoxPlayingGame.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int nA, int nB, int paramA, int paramB, double __expected) {
    time_t startClock = clock();
    FoxPlayingGame *instance = new FoxPlayingGame();
    double __result = instance->theMax(nA, nB, paramA, paramB);
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
        int nA;
        from_stream(nA);
        int nB;
        from_stream(nB);
        int paramA;
        from_stream(paramA);
        int paramB;
        from_stream(paramB);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(nA, nB, paramA, paramB, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1426768589;
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
        cout << "FoxPlayingGame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
