// STD !!!

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
template<class T> inline int size(const T&c) { return c.size();}

const int BILLION = 1000000000;
const double INF = 1e20;
typedef long long LL;

struct Point {
  int x,y;
  Point() {}
  Point(int x,int y):x(x),y(y) {}
};

inline Point middle(const Point &a, const Point &b) {
  return Point((a.x+b.x)/2, (a.y+b.y)/2);
}

struct CmpX {
  inline bool operator()(const Point &a, const Point &b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  }
} cmpx;

struct CmpY {
  inline bool operator()(const Point &a, const Point &b) {
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
  }
} cmpy;

inline LL sqr(int x) { return LL(x) * LL(x); }

inline double dist(const Point &a, const Point &b) {
  return sqrt(double(sqr(a.x-b.x) + sqr(a.y-b.y)));
}

inline double perimeter(const Point &a,
                        const Point &b,
                        const Point &c) {
  return dist(a,b) + dist(b,c) + dist(c,a);
}

double calc(int n, const Point points[],
            const vector<Point> &pointsByY) {
  if(n<3) return INF;
  int left = n/2;
  int right = n-left;
  Point split = middle(points[left-1], points[left]);
  vector<Point> pointsByYLeft, pointsByYRight;
  pointsByYLeft.reserve(left);
  pointsByYRight.reserve(right);
  REP(i,n) {
    if(cmpx(pointsByY[i], split))
      pointsByYLeft.push_back(pointsByY[i]);
    else
      pointsByYRight.push_back(pointsByY[i]);
  }
  double res = INF;
  res = min(res, calc(left, points, pointsByYLeft));
  res = min(res, calc(right, points+left, pointsByYRight));
  static vector<Point> closeToTheLine;
  int margin = (res > INF/2) ? 2*BILLION : int(res/2);
  closeToTheLine.clear();
  closeToTheLine.reserve(n);
  int start = 0;
  for(int i=0;i<n;++i) {
    Point p = pointsByY[i];
    if(abs(p.x - split.x) > margin) continue;
    while(start < size(closeToTheLine) &&
          p.y - closeToTheLine[start].y > margin) ++start;
    for(int i=start;i<size(closeToTheLine);++i) {
      for(int j=i+1;j<size(closeToTheLine);++j) {
        res = min(res, perimeter(p, closeToTheLine[i],
                                 closeToTheLine[j]));
      }
    }
    closeToTheLine.push_back(p);
  }
  return res;
}

double calc(vector<Point> &points) {
  sort(points.begin(), points.end(), cmpx);
  vector<Point> pointsByY = points;
  sort(pointsByY.begin(), pointsByY.end(), cmpy);
  return calc(size(points), &points[0], pointsByY);
}

int main() {
	freopen("perimeter.ans","w",stdout);
  FILE *f = fopen("perimeter.in", "r");
  int ntc; fscanf(f, "%d", &ntc);
  REP(tc,ntc) {
    int n; fscanf(f, "%d", &n);
    vector<Point> points;
    points.reserve(n);
    REP(i,n) {
      int x,y; fscanf(f, "%d%d", &x, &y);
      points.push_back(Point(2*x-BILLION,2*y-BILLION));
    }
    double res = calc(points);
    printf("Case #%d: %.11f\n", tc+1, res/2);
  }
  fclose(f);
}

// STD !!!
