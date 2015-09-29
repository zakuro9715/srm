#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct OrderOfOperationsDiv2
{
  bool c[20];
  bool done[20];
  int minTime(vector<string> s)
  {
    int ans = 0;
    int done_n = 0;
    while(done_n < s.size())
    {
      done_n++;
      int min_n = 10000000;
      int target = -1;
      for(int i = 0; i < s.size(); i++)
      {
        if(done[i])
          continue;
        int n = 0;
        for(int j = 0; j < s[0].size(); j++)
        {
          if(s[i][j] == '1' && !c[j])
            n++;
        }
        if(n <= min_n)
        {
          min_n = n;
          target = i;
        }
      }
      ans += min_n * min_n;
      for(int j = 0; j < s[0].size(); j++)
      {
        if(s[target][j] == '1')
          c[j] = true;
      }
      done[target] = true;
    }
    return ans;
  }
};

// CUT begin
ifstream data("OrderOfOperationsDiv2.sample");

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

bool do_test(vector<string> s, int __expected) {
    time_t startClock = clock();
    OrderOfOperationsDiv2 *instance = new OrderOfOperationsDiv2();
    int __result = instance->minTime(s);
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
        vector<string> s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1441984548;
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
        cout << "OrderOfOperationsDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
