#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
const string quack = "quack";

#define init() freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

ll n, k;
vi v;
vector<pi> p;

bool check(ll d) {
	ll l = 0;
	for (auto [a, b]: p) {
		if (d >= b) l += (b - a + 1);
		else if (d >= a) l += (d - a + 1);
	}
	return l >= k;
}

int main() {
	init();
	cin >> n >> k;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	ll l = 0, r = (1ll << 32), m = -1;
	while (r > l) {
		m = (l + r) / 2;
		if (check(m)) r = m;
		else l = m+1;
	}
	if (not check(m)) m++;
	cout << m << endl;
}

