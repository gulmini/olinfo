#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";
constexpr ll mod = 1000000007;
constexpr ll maxval = 200003;
constexpr ll maxn = 101;

ll n;
ll v[maxn], fact[maxval], invfact[maxval];
ll memo[maxn][maxn], mul[maxn][maxn];

ll modpow(ll b, ll n) {
	if (n == 0) return 1;
	ll r = modpow(b, n/2);
	r = r * r % mod;
	return n % 2 ? r * b % mod : r;
}

inline ll c(ll n, ll k) {
	return ((fact[n] * invfact[k] % mod) * invfact[n-k]) % mod;
}

ll dp(ll i, ll curr) {
	if (i == n) return curr == 0;
	if (memo[i][curr]) return memo[i][curr];
	ll res = 0;

	for (ll j = 0; j <= min(v[i], n-1); j++) {
		res += (mul[i][j] * dp(i+1, (curr + j * (i+1)) % n)) % mod;
		res %= mod;
	}
	return memo[i][curr] = res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < maxval; i++) fact[i] = fact[i-1] * i % mod;
	for (int i = 1; i < maxval; i++) invfact[i] = modpow(fact[i], mod-2);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= min(v[i], n-1); j++) {
			int k = 0;
			ll m = 0;
			while (n*k+j <= v[i]) {
				m += c(v[i], n*k+j);
				m %= mod;
				k++;
			}
			mul[i][j] = m;
		}
	}

	cout << dp(0, 0) << endl;
}

