#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const string quack = "quack";

ll aggiorna(int n, vi a, vi b) {
	ll res = 0;
	for (ll i = n-2; i >= 0; i--) {
		ll q = (a[i+1] - a[i]) / b[i];
		a[i] += q * b[i];
		res += q;
	}
	return res;
}

