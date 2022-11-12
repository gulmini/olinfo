#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const string quack = "quack";
constexpr int maxc = 100001;
constexpr int maxq = 900001;

int n;
vi v, p, h, e, color;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return;
	if (h[a] < h[b] and a < n) swap(a, b);
	p[b] = a;
	if (h[a] == h[b]) h[a]++;
}

void Colora(int n, int q, vi &a, vi &b, vi &c, vi &murale) {
	::n = n;
	p.resize(n+q); h.resize(n+q, 1); e.resize(q);
	iota(p.begin(), p.end(), 0);

	for (int i = q-1; i >= 0; i--) {
		for (int j = a[i]; j <= b[i]; j++) {
			int x = find(j);
			if (x >= n) {
				j = e[x-n];
			}
			else {
				p[x] = n+i;
				e[i] = b[i];
			}
		}
	}

	int ix;
	for (int j = 0; j < n; j++) {
		ix = find(j);
		murale[j] = (ix >= n) ? c[ix-n] : 0;
	}
}

