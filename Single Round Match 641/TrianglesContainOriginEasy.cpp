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

#include<vector>
#include<iterator> 
#include<utility>
#include<cmath>
using namespace std;

#define INF 1000000000
#define PTYPE long double
#define EPS 0.0000000000001

struct Point
{ 
  PTYPE x, y; 
  Point(PTYPE _x, PTYPE _y) : x(_x), y(_y) { } 
  Point() : x(0), y(0) { }

#define DEFINE_OPERATOR(OP) \
  bool operator OP(const Point& rhs) const { return x OP rhs.x && y OP rhs.y; }
  DEFINE_OPERATOR(==)
    DEFINE_OPERATOR(<)
#undef DEFINE_OPERATOR
};

Point intersection_lines(PTYPE a1, PTYPE b1, PTYPE a2, PTYPE b2)
{
  if(a1 == a2)
    return Point(INF, INF);
  /* y = a1x + b1
   * y = a2x + b2
   * 
   * a1x + b1 = a2x + b2
   * (a1 - a2)x = b2 - b1
   * x = (b2 - b1) / (a1 - a2)
   * y = a1((b2 - b1) / (a1 - a2)) + b1
   */
  return Point((b2 - b1) / (a1 - a2), a1 * ((b2 - b1) / (a1 - a2)) + b1);
}

const Point intersection_lines(
    const Point& p11, 
    const Point& p12, 
    const Point& p21, 
    const Point& p22)
{
  PTYPE a1 = INF;
  PTYPE a2 = INF;
  if(!(p12.x - p11.x || p21.x - p22.x))
    return Point(INF, INF);
  if(p12.x - p11.x)
    a1 = (p12.y - p11.y) / (p12.x - p11.x); 
  if(p22.x - p21.x)
    a2 = (p22.y - p21.y) / (p22.x - p21.x);
  /*
   * y = ax + b
   * b = y - ax
   */
  auto b1 = p12.y - a1 * p12.x;
  auto b2 = p22.y - a2 * p22.x;

  Point p;

  if(a1 == INF)
    p = Point(p12.x, a2 * p12.x + b2);
  else if(a2 == INF)
    p = Point(p22.x, a1 * p22.x + b1);
  else
    p = intersection_lines(a1, b1, a2, b2);

  if(
      p.x + EPS >= max(min(p11.x, p12.x), min(p21.x, p22.x)) &&
      p.x - EPS <= min(max(p11.x, p12.x), max(p21.x, p22.x)) &&
      p.y + EPS >= max(min(p11.y, p12.y), min(p21.y, p22.y)) &&
      p.y - EPS <= min(max(p11.y, p12.y), max(p21.y, p22.y)))
    return p;
  return Point(INF, INF);
}

class TrianglesContainOriginEasy {
  public:
    int count(vector<int> x, vector<int> y) {
      int n = 0;  
      vector<int> xx, yy;
      for(int i = 0;i < x.size(); i++)
      {
        PTYPE a;
        if(x[i] == 0)
        {
          xx.push_back(x[i]);
          yy.push_back(y[i] / abs(y[i]) * 2000);
        }
        else
        {
          a = y[i] / (PTYPE)x[i];
          xx.push_back(x[i] / abs(x[i]) * 2000);
          yy.push_back(a * xx[i]);
        }
      }

      for(int i1 = 0; i1 < x.size(); i1++)
      {
        for(int i2 = i1 + 1; i2 < x.size(); i2++)
        {  
          for(int i3 = i2 + 1; i3 < x.size(); i3++)
          {
            Point p0(0, 0), p1(x[i1], y[i1]), p2(x[i2], y[i2]), p3(x[i3], y[i3]);
            if(intersection_lines(p0, Point(xx[i1], yy[i1]), p2, p3) == Point(INF, INF) &&
                intersection_lines(p0, Point(xx[i2], yy[i2]), p3, p1) == Point(INF, INF) &&
                intersection_lines(p0, Point(xx[i3], yy[i3]), p1, p2) == Point(INF, INF))
            {
              n++;
            }
          }
        }
      }
      return n;
    }
};

// CUT begin
ifstream data("TrianglesContainOriginEasy.sample");

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

bool do_test(vector<int> x, vector<int> y, int __expected) {
  time_t startClock = clock();
  TrianglesContainOriginEasy *instance = new TrianglesContainOriginEasy();
  int __result = instance->count(x, y);
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
    vector<int> x;
    from_stream(x);
    vector<int> y;
    from_stream(y);
    next_line();
    int __answer;
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
    int T = time(NULL) - 1418314020;
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
    cout << "TrianglesContainOriginEasy (500 Points)" << endl << endl;
  }
  return run_test(mainProcess, cases, argv[0]);
}
// CUT end

