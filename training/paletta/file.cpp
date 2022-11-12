#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int t[1500000];
int n;

void update(int x) {
	for (int i = x; i < n; i |= i+1) t[i]++;
}

int query(int x) {
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1) res += t[i];
	return res;
}

long long paletta_sort(int n, int v[]) {
	for (int i = 0; i < n; i++) if (v[i] % 2 != i % 2) return -1;
	::n = n;
	long long res = 0;
	for (int b = 0; b < 2; b++) {
		for (int i = n-1-b; i >= 0; i -= 2) {
			res += (v[i] - i) / 2 + query(v[i]);
			update(v[i]);
		}
		for (int i = 0; i < n; i++) t[i] = 0;
	}
	return res;
}

