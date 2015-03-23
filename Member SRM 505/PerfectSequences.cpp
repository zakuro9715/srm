#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct PerfectSequences
{
  int check(vector<int>& seq, int index, int v)
  {
    int tmp = seq[index];
    seq[index] = v;
  
    ll s = 0;
    ll p = 1;
    for(int i = 0; i < seq.size(); i++)
    {
      s += seq[i];
      p *= seq[i];
      if(p < 0)
      {
        p = s + 1;
        break;
      }
    }
    seq[index] = tmp;
    if(s == p)
      return 0;
    return s < p ? 1 : -1;
  }

  bool search(vector<int>& seq, int index)
  {
    int l = 0, r = 1000000000;
    while(l + 1 < r)
    {
      int m = (l + r) / 2;
      int v = check(seq, index, m);
      if(v < 0)
        l = m;
      if(v > 0)
        r = m;
      if(v == 0)
        return m != seq[index];
    }
    for(int i = l; i <= r; i++)
      if(i != seq[index] && !check(seq, index, i))
        return true;
    return seq[index] != 0 && !check(seq, index, 0);
  }

  string fixIt(vector<int> seq)
  {
    for(int i = 0; i < seq.size(); i++)
    {
      if(search(seq, i))
        return "Yes";
    }
    return "No";
  }
};

// CUT begin
ifstream data("PerfectSequences.sample");

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

bool do_test(vector<int> seq, string __expected) {
    time_t startClock = clock();
    PerfectSequences *instance = new PerfectSequences();
    string __result = instance->fixIt(seq);
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
        string __answer;
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
        int T = time(NULL) - 1427123898;
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
        cout << "PerfectSequences (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
