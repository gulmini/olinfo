#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
const string quack = "quack";

ll n;
vi v;

int scarta(int m, vb l, vb d, vb n) {
	ll res = 0;
	for (int i = 0; i < m; i++) {
		if (l[i] + d[i] + n[i] != 1) res++;
	}
	return res;
}

