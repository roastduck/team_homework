// STD !!

#include <iostream>
#include <set>
#include <algorithm>
#include <tuple>
#include <utility>

using namespace std;

int n, m;
const int MAXN = 100000;
tuple<int, int, bool> a[MAXN * 2];
multiset<int> t;
int tot, l[MAXN * 2], r[MAXN * 2];
long long s1[MAXN * 2 + 1], s2[MAXN * 2 + 1];

int main()
{
	freopen("path.in","r",stdin), freopen("path.ans","w",stdout);
	std::cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		int l, r, t; cin >> l >> r >> t;
		a[i + i] = make_tuple(l, t, true);
		a[i + i + 1] = make_tuple(r, t, false);
	}
	sort(a, a + n + n);
	for (int i = 0; i < n + n; ++i) {
		if (!t.empty()) {
			l[tot] = *t.begin() - get<0>(a[i - 1]);
			r[tot++] = *t.begin() - get<0>(a[i]);
		}
		if (get<2>(a[i])) t.insert(get<1>(a[i]));
		else t.erase(t.lower_bound(get<1>(a[i])));
	}
	sort(l, l + tot); sort(r, r + tot);
	for (int i = 0; i < tot; ++i) {
		s1[i + 1] = s1[i] + l[i]; s2[i + 1] = s2[i] + r[i];
	}
	while (m--) {
		int q; cin >> q;
		int p1 = lower_bound(l, l + tot, q) - l;
		int p2 = lower_bound(r, r + tot, q) - r;
		cout << (long long)q * (p2 - p1) + s1[p1] - s2[p2] << endl;
	}
}

// STD !!
