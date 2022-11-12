#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr ll MOD = 1e9 + 7;
constexpr int maxn = 2000002;
const string quack = "quack";

ll n, q, k, type, a, b, x, s, i;
vi v, t, fact(maxn);
ll flag[10];

ll fast_exp(int b, int n) {
	if (b == 0) return 0;
	if (b == 1 or n == 0) return 1;
	ll r = fast_exp(b, n/2);
	r = r * r % MOD;
	if (n % 2) r = r * b % MOD;
	return r;
}

void upd(int i, int val) {
	for (; i < n; i |= i+1)
		t[i] += val;
}

ll qry(int i) {
	ll res = 0;
	for (; i >= 0; i = (i & (i+1)) - 1)
		res += t[i];
	return res;
}

ll qry(int l, int r) {
	return qry(r) - qry(l-1);
}

ll inv(int n) { return fast_exp(n, MOD-2); }

ll calc(int n, int k) {
	return fact[n] * inv(fact[k] * fact[n-k] % MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> k;
	v.resize(n); t.resize(n);

	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = fact[i-1] * i % MOD;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] = max(v[i], k);
		upd(i, v[i]);
	}

	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> i >> x; i--;
			x = max(x, k);
			upd(i, x - v[i]);
			v[i] = x;
		}
		else {
			cin >> a >> b >> s; a--; b--;
			s -= qry(a, b); int k = b-a+1;
			if (s < 0) cout << 0 << '\n';
			else cout << calc(s+k-1, k-1) << '\n';
		}
	}
}

