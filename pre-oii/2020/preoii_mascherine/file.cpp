#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, a = 0;
vi v;

ll f(vector<int> &v) {
	v.push_back(0);
	ll res = 0;

	for (int i = 1; i < n; i++) {
		if (v[i] == v[i-1]) {
			res++;
			if (v[i-1] != 1 and v[i+1] != 1) v[i] = 1;
			else if (v[i-1] != 2 and v[i+1] != 2) v[i] = 2;
			else v[i] = 3;
		}
	}

	v.pop_back();
	return res;
}

void riprogramma(int n, int k, vector<int>& v) {
	::n = n;
	if (k == 2) {
		for (int i = 0; i < n; i++)
			if ((v[i] + i) % 2) a++;

		bool b = a <= n/2;
		for (int i = 0; i < n; i++)
			v[i] = (i%2^b)+1;

		return;
	}

	vector<int> rv(v.rbegin(), v.rend());
	if (f(rv) < f(v))
		v.assign(rv.rbegin(), rv.rend());

	v.pop_back();
}

