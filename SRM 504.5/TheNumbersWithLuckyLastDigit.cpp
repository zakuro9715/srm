#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct TheNumbersWithLuckyLastDigit
{
  int find(int n)
  {
    int m = n % 10;
    switch(m)
    {
      case 0:
        // 100 96 92 88 84
        return n > 100 - 84 ? 5 : -1;
      case 1:
        // 101 97
        return n > 101 - 97 ? 2 : -1;
      case 2:
        // 102 98 94
        return n > 102 - 94 ? 3 : -1;
      case 3:
        // 103 99 95 91 87
        return n > 103 - 87 ? 5 : -1;
      case 4:
        return 1;
      case 5:
        // 105 101 94
        return n > 105 - 94 ? 3 : -1;
      case 6:
        // 106 102 98 94
        return n > 106 - 94 ? 4 : -1;
      case 7:
        return 1;
      case 8:
        // 108 104
        return n > 108 - 104 ? 2 : -1;
      case 9:
        // 109 105 101 97
        return n > 109 - 97 ? 4 : -1;
    }
    return 0;
  }
};

// CUT begin
ifstream data("TheNumbersWithLuckyLastDigit.sample");

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

bool do_test(int n, int __expected) {
    time_t startClock = clock();
    TheNumbersWithLuckyLastDigit *instance = new TheNumbersWithLuckyLastDigit();
    int __result = instance->find(n);
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
        int n;
        from_stream(n);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427169981;
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
        cout << "TheNumbersWithLuckyLastDigit (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
