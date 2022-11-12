#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const string quack = "quack";

void scavi(int n, int m, int q, vi &y1, vi &x1, vi &y2, vi &x2, vi &p, vector<vi> &d) {
	d.resize(n+1);
	for (int i = 0; i <= n; i++)
		d[i].resize(m+1);

	while (q--) {
		d[y1[q]][x1[q]] += p[q];
		d[y1[q]][x2[q]+1] -= p[q];
		d[y2[q]+1][x1[q]] -= p[q];
		d[y2[q]+1][x2[q]+1] += p[q];
	}

	for (int j = 0; j < m; j++)
		for (int i = 1; i < n; i++)
			d[i][j] += d[i-1][j];

	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++)
			d[i][j] += d[i][j-1];
	
	d.resize(n, vi(m));
}


