#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

vi p;
vi factors;

void factorize(ll n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) factors.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n != 1) factors.push_back(n);
}

int taglia(int n, vector<int> v) {
	p.resize(n);
	p[0] = v[0];
	for (int i = 1; i < n; i++) p[i] = p[i-1] + v[i];
	ll sum = p[n-1];

	if (sum == 0)
		return count(p.begin(), p.end(), 0) > 1 ? 2 : -1;

	if (sum < 0)
		for (int i = 0; i < n; i++) p[i] *= -1;

	sum = p[n-1];
	factorize(sum);

	ll lf, k;
	for (auto f: factors) {
		k = sum/f;
		lf = k;
		for (int i = 0; i < n; i++) {
			if (p[i] == lf) {
				lf += k;
				if (lf == sum + k) return f;
			}
		}
	}
	return -1;
}

