#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
struct SlimeXResidentSlime
{
  vector<pair<int, int> > p;
  vector<string> f;
  int d[100][100], W, H;
  bool done[100][100];

  int dist(int x1, int y1, int x2, int y2)
  {
    fill((bool*)done, (bool*)done + 100 * 100, false);
    queue<int> q;
    q.push(x1);
    q.push(y1);
    q.push(0);
    while(q.size())
    {
      int x = q.front(); q.pop();
      int y = q.front(); q.pop();
      int n = q.front(); q.pop();
      if(x == x2 && y == y2)
        return n;
      for(int k = 0; k < 4; k++)
      {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if(tx >= 0 && tx < W && ty >= 0 && ty < H && f[ty][tx] != '#' && !done[ty][tx])
        {
          q.push(tx);
          q.push(ty);
          q.push(n + 1);
          done[ty][tx] = true;
        }
      }
    }
    return INF;
  }

  int exterminate(vector<string> field)
  {
    f = field;
    H = f.size(); W = f[0].size();
    int sx, sy;
    for(int i = 0; i < field.size(); i++)
    {
      for(int j = 0; j < field[0].size(); j++)
      {
        if(field[i][j] > '0' && field[i][j] <= '9')
          p.push_back(make_pair(j, i));
        if(field[i][j] == '$')
          sy = i, sx = j;
      }
    }
    if(p.size() > 9)
      return -1;
    for(int i = 0; i < p.size(); i++)
    {
      for(int j = i + 1; j < p.size(); j++)
      {
        int x1 = p[i].first, y1 = p[i].second, x2 = p[j].first, y2 = p[j].second;
        d[i][j] = d[j][i] = dist(x1, y1, x2, y2);
      }
      int x = p[i].first, y = p[i].second;
      d[i][p.size()] = dist(sx, sy, x, y); 
    }
   
    vector<int> v;
    for(int i = 0; i < p.size(); i++)
      v.push_back(i);
    int ans = INF;
    do
    {
      int x = p[v[0]].first, y = p[v[0]].second;
      int n = f[y][x] - '0';
      int ans0 = d[v[0]][p.size()];
      for(int i = 1; i < p.size(); i++)
      {
        int dd = d[v[i]][v[i - 1]];
        n = min(n - dd, f[p[v[i]].second][p[v[i]].first] - '0');
        ans0 += dd;
        if(n <= 0)
          goto fail;
      }
      ans = min(ans, ans0);
fail:;
    }while(next_permutation(v.begin(), v.end()));
    return ans == INF ? -1 : ans;
  }
};

// CUT begin
ifstream data("SlimeXResidentSlime.sample");

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

bool do_test(vector<string> field, int __expected) {
    time_t startClock = clock();
    SlimeXResidentSlime *instance = new SlimeXResidentSlime();
    int __result = instance->exterminate(field);
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
        vector<string> field;
        from_stream(field);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(field, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1427164299;
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
        cout << "SlimeXResidentSlime (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
