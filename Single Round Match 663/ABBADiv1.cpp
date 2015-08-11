#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct ABBADiv1
{
  string getans(bool value)
  {
    return value ? "Possible" : "Impossible";
  }

  string canObtain(string initial, string target)
  {
    bool reversed = false;
    int initial_a = 0, initial_b = 0, target_a = 0, target_b = 0;
    for(int i = 0; i < initial.size(); i++)
    {
      if(initial[i] == 'A')
        initial_a++;
      else
        initial_b++;
    }
    for(int i = 0; i < target.size(); i++)
    {
      if(target[i] == 'A')
        target_a++;
      else
        target_b++;
    }
    if(target_a < initial_a || target_b < initial_b)
      return getans(false);
    if((target_b - initial_b) % 2)
      reversed = true;

    if(reversed)
    {
      string initial2 = initial;
      for(int i = 0; i < initial.size(); i++)
        initial[i] = initial2[initial.size() - 1 - i];
    }
    vector<int> m;
    for(int i = 0; i < target.size() - initial.size() + 1; i++)
    {
      bool ok = true;
      int j;
      for(j = 0; j < initial.size(); j++)
        if(target[i + j] != initial[j])
        {
          ok = false;
          break;
        }
      if(ok)
        m.push_back(i);
      i += max(0, j - 1);
    }
    for(int i = 0; i < m.size(); i++)
    {
      int before_b = 0, after_b = 0;
      for(int j = max(0, m[i] - 1); j >= 0; j--)
        if(target[j] == 'B')
          before_b++;
      for(int j = m[i] + initial.size(); j < target.size(); j++)
        if(target[j] == 'B')
          after_b++;
      if(reversed)
        return getans(before_b == after_b + 1);
      else
        return getans(before_b == after_b);
    }
    return getans(false);
  }
};

// CUT begin
ifstream data("ABBADiv1.sample");

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

bool do_test(string initial, string target, string __expected) {
    time_t startClock = clock();
    ABBADiv1 *instance = new ABBADiv1();
    string __result = instance->canObtain(initial, target);
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
        string initial;
        from_stream(initial);
        string target;
        from_stream(target);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(initial, target, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1437663618;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ABBADiv1 (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
