#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

struct T {
  int cost = 0, red = 0, green = 0;

  // redが前に来る
  bool operator<(const T& rhs)
  {
    return green - red < rhs.green - rhs.red;
  }

  bool rr()
  {
    return red - green > 0;
  }
};

class TheKingsTree {
  vector<int> ch[50];
  T rch[50];
  T dfs(int n)
  {
    int cn = ch[n].size();
    int diff = 0;
    for(int i = 0; i < cn; i++)
    {
      rch[i] = dfs(ch[n][i]);
      if(rch[i].rr())
        diff++;
      else
        diff--;
    }
    sort(rch, rch + cn);
    T tt;
    for(int i = 0; i < cn; i++)
    {
      if(diff > 1 && rch[i].rr() || diff < -1 && !rch[i].rr())
      {
        int tmp = rch[i].red;
        rch[i].red = rch[i].green;
        rch[i].green = tmp;
        diff -= rch[i].red - rch[i].green;
      }
      tt.cost += rch[i].cost;
      tt.red += rch[i].red;
      tt.green += rch[i].green;
    }
    if(diff > 0)
    {
      tt.green += 1;
      tt.cost += tt.green;
    }
    else
    {
      tt.red += 1;
      tt.cost += tt.red;
    }
    cout << n << " " << cn << " " << diff << " " << tt.cost << " " << tt.red << " " << tt.green << endl;
    return tt;
  }

  public:
    int getNumber(vector<int> parent) {
      for(int i = 0; i < parent.size(); i++)
        ch[parent[i]].push_back(i + 1);
      return dfs(0).cost;
    }
};

// CUT begin
ifstream data("TheKingsTree.sample");

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

bool do_test(vector<int> parent, int __expected) {
  time_t startClock = clock();
  TheKingsTree *instance = new TheKingsTree();
  int __result = instance->getNumber(parent);
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
    vector<int> parent;
    from_stream(parent);
    next_line();
    int __answer;
    from_stream(__answer);

    cases++;
    if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
      continue;

    cout << "  Testcase #" << cases - 1 << " ... ";
    if ( do_test(parent, __answer)) {
      passed++;
    }
  }
  if (mainProcess) {
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1419701390;
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
    cout << "TheKingsTree (1000 Points)" << endl << endl;
  }
  return run_test(mainProcess, cases, argv[0]);
}
// CUT end
