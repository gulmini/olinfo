#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";
constexpr ll mod = 1000000007;
constexpr ll maxn = 100002;

ll n;
vi v;
ll fact[maxn], invfact[maxn];
vi conf(10);

ll modpow(int b, int n) {
	if (n == 0) return 1;
	ll r = modpow(b, n/2);
	r = r * r % mod;
	return n % 2 ? r * b % mod : r;
}

inline ll c(int n, int k) {
	return ((fact[n] * invfact[n-k] % mod) * invfact[k]) % mod;
}

inline ll mul(int i) {
	ll res = fact[n] * invfact[n-i] % mod;
	for (int j = 2; j < 10; j++) {
		res *= invfact[conf[j]];
		res %= mod;
	}
	return res;
}

ll dp(int i, int currp, int currs, int p) {
	dbg(i, currp, currs);
	if (currp > currs + n-i + 10) return 0;
	if (currp == currs + n-i) return mul(i);
	if (i == n) return 0;
	ll res = 0;
	for (int c = p; c < 10; c++) {
		conf[c]++;
		res += dp(i+1, currp * c, currs + c - 1, c);
		res %= mod;
		conf[c]--;
	}
	return res;
}

int main() {
	init();
	cin >> n;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fact[i] = fact[i-1] * i % mod;
		invfact[i] = modpow(fact[i], mod-2);
	}
	if (n == 1) cout << 10 << '\n';
	else cout << dp(0, 1, 0, 2) + 1;
}

