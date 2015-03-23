#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct Algrid
{
  bool check(string a, string b, string output)
  {
    for(int i = 0; i < a.size() - 1; i++)
    {
      if(a[i] == 'W')
      {
        if(a[i + 1] == 'B')
          b[i] = b[i + 1] = 'W';
      }
      else
      {
        if(a[i + 1] == 'B')
          swap(b[i], b[i + 1]);
        if(a[i + 1] == 'W')
          b[i] = b[i + 1] = 'B';
      }
    }
    return b == output;
  }
  vector<string> c;
  vector<string> makeProgram(vector<string> output)
  {
    for(int y = 0; y < output.size(); y++)
        c.push_back(output[y]);
    for(int y = 1; y < output.size(); y++)
    {
      for(int v = 0; v < pow(2, output[0].size()); v++)
      {
        for(int i = 0; i < output[0].size(); i++)
          c[y][output[0].size() - i - 1] = v & (1 << i) ? 'W' : 'B';
        if(check(output[y - 1], c[y], output[y]))
          goto next;
      }
      return vector<string>();
next:;
    }
    return c;
  }
};

// CUT begin
ifstream data("Algrid.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> output, vector<string> __expected) {
    time_t startClock = clock();
    Algrid *instance = new Algrid();
    vector<string> __result = instance->makeProgram(output);
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
        vector<string> output;
        from_stream(output);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(output, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427112356;
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
        cout << "Algrid (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
