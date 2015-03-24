#include<bits/stdc++.h>
#define INF (1 << 30)
#define NN 110000
using namespace std;
typedef long long ll;
struct CubeRoll
{

  int d[NN * 2 + 1];
  int off = NN;
  
  int bfs(int l, int r, int st, int gl)
  {
    fill(d, d + NN * 2 + 1, INF);
    queue<int> q;
    q.push(st);
    q.push(0);
    while(q.size())
    {
      int p = q.front(); q.pop();
      int n = q.front(); q.pop();
      if(p == gl)
        return n;
      for(int i = 1; i * i < NN; i++)
      {
        int ll = p - i * i, rr = p + i * i;
        if(l < ll && ll < r && d[ll + off] == INF)
        {
          q.push(ll);
          q.push(n + 1);
          d[ll + off] = n + 1;
        }
        if(l < rr && rr < r && d[rr + off] == INF)
        {
          q.push(rr);
          q.push(n + 1);
          d[rr + off] = n + 1;
        }
      }
    }
    return -1;
  }
  
  bool square(int a)
  {
    double aa = sqrt(a);
    return aa == (int)aa;
  }

  int getMinimumSteps(int initPos, int goalPos, vector<int> holePos)
  {
    bool aaa = false;
    int l = -INF, r = INF;
    for(int i = 0; i < holePos.size(); i++)
    {
      if(holePos[i] < initPos)
        l = max(l, holePos[i]);
      if(holePos[i] > initPos && holePos[i] < goalPos)
        aaa = true;
      if(holePos[i] > goalPos)
        r = min(r, holePos[i]);
    }
    if(aaa)
      return -1;
    if(l > -INF && r < INF)
      return bfs(l, r, initPos, goalPos);
    int d = abs(goalPos - initPos);
    if(square(d))
      return 1;
    if(d % 2)
      return 2;
    if(d % 4 != 2)
      return 2;
    for(int i = 0; i * i <= NN * 2; i++)
      for(int j = 0; j * j <= NN * 2; j++)
        if(i * i + j * j == d || i * i - j * j == d)
          return 2;
    return 3;
  }
};

// CUT begin
ifstream data("CubeRoll.sample");

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

bool do_test(int initPos, int goalPos, vector<int> holePos, int __expected) {
    time_t startClock = clock();
    CubeRoll *instance = new CubeRoll();
    int __result = instance->getMinimumSteps(initPos, goalPos, holePos);
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
        int initPos;
        from_stream(initPos);
        int goalPos;
        from_stream(goalPos);
        vector<int> holePos;
        from_stream(holePos);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(initPos, goalPos, holePos, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427175651;
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
        cout << "CubeRoll (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
