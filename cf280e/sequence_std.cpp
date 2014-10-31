#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define REP0(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 1; i <= n; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define RP(i, r, l) for (int i = r; i >= l; i--)
#define FORE(i, x) for (int i = fi[x]; i != -1; i = e[i].n)
#define sqr(_) ((_) * (_))
#define MAX_N 110000
#define lc c[0]
#define rc c[1]
#define eps 1E-12

typedef double ld;
typedef struct node* ntp;   ntp st[MAX_N], rt;
struct node
{
       ntp c[2], f; ld x, dx, y, k, b; //存点x+dx处的函数图像的斜率 
       inline int d(void) { return f->rc == this; }
       inline void sc(ntp x, int d) { if (this) if (c[d] = x) x->f = this; }
       inline void rot(void)
       {
              ntp p = f; int dd = d();
              if (!p->f) f = NULL, rt = this; else p->f->sc(this, p->d());
              p->sc(c[!dd], dd), sc(p, !dd);
       }
       inline void down(int x)
       { if (c[x]) c[x]->b += b - dx * c[x]->k, c[x]->dx += dx, c[x]->k += k; }
       inline void down(void)
       { if (!this) return ; x += dx, y += k * x + b, down(0), down(1), k = b = dx = 0; }
       void push(void)
       {
            ntp t = this; int top = 0;
            while (t) st[++top] = t, t = t->f; while (top) st[top--]->down();
       }
       void splay(void)
       { push(); while (f) { if (!f->f) rot(); else (f->d() == d() ? f : this)->rot(), rot(); } }
       ntp next(int x)
       { down(); ntp t = c[x]; while (t->c[!x]) (t = t->c[!x])->down(); return t; }
       ntp get(void)
       {
           ntp t = this, s = NULL; down();
           while (true)
           {
                 if (t->y > 0) s = t;
                 if (fabs(t->y) <= eps) return t;
                 bool d = t->y < 0; if (!t->c[d]) return s;
                 (t = t->c[d])->down();
           }
       }
       void print(void)
       {
            down();
            if (lc) lc->print(); printf ("[%.5lf %.5lf]", x, y), fflush(stdout);
            if (rc) rc->print();
       }
       void pr(void) { print(), puts(""), fflush(stdout); }
} pool[MAX_N], *pos = pool;

int xi[MAX_N]; ld yi[MAX_N], mins[MAX_N];
int n, q, A, B;

inline ntp gnew(ld x, ld y) { pos++, pos->x = x, pos->y = y; return pos; }

void solve(void)
{
  //   REP1(i, n) printf ("%d ", xi[i]); puts(""); fflush(stdout);
     rt = gnew(1.0, 2.0 * (1 - xi[1])), rt->sc(gnew(q, 2.0 * (q - xi[1])), 1);
     rt->sc(gnew(-1, -1E30), 0);
     REP(i, 2, n)
     {
       // rt->pr();
        rt->get()->splay(); ld &p = mins[i - 1]; ntp t, t2;
      //  printf ("miny = %.5lf[x = %.5lf]\n", rt->y, rt->x);
        if (fabs(rt->y) <= eps)
        {
           rt->y = 0, p = rt->x;
           if (A != B) t = gnew(p, 0), t->sc(rt->rc, 1), rt->sc(t, 1);
        }
        else
        {
            ld X1 = rt->x, Y1 = rt->y, X2, Y2; rt->next(0)->splay(), X2 = rt->x, Y2 = rt->y;
            p = (X2 * Y1 - Y2 * X1) / (Y1 - Y2);
            if (A != B)
            {
               t = gnew(p, 0), t->sc(rt->rc, 1), rt->sc(t, 1);
               t2 = gnew(p, 0), t2->sc(rt->rc, 1), rt->sc(t2, 1), t2->splay();
            }
        }
        if (A != B) t->dx = B, t->push(), t->splay(), rt->lc->dx = A;
        else rt->dx = A;
        rt->k = 2, rt->b = -2.0 * xi[i];
      //  printf ("%.5lf\n", mins[i - 1]);
     }
  //   rt->pr();
     rt->get()->splay(); ld ts;
     //  printf ("miny = %.5lf[x = %.5lf]\n", rt->y, rt->x);
     if (fabs(rt->y) <= eps) ts = rt->x;
     else
     {
         ld X1 = rt->x, Y1 = rt->y, X2, Y2; rt->next(0)->splay(), X2 = rt->x, Y2 = rt->y;
         ts = (X2 * Y1 - Y2 * X1) / (Y1 - Y2);
     }
     yi[n] = ts > q ? q : max(ts, (ld)A * (n - 1) + 1);
     RP(i, n - 1, 1) yi[i] = yi[i + 1] < mins[i] + A ? yi[i + 1] - A : yi[i + 1] > mins[i] + B
                     ? yi[i + 1] - B : mins[i];
}

int main(void)
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.ans","w",stdout);
    scanf ("%d%d%d%d", &n, &q, &A, &B);
    REP1(i, n) scanf ("%d", xi + i); solve(); REP1(i, n) printf ("%.8lf ", yi[i]);
    ld ans = 0; REP1(i, n) ans += sqr(xi[i] - yi[i]);
    printf ("\n%.8lf\n", ans);
    return 0;
}

