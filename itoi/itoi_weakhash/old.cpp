#include <iostream>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;

constexpr int mod = 10000019;
constexpr int maxn = 51;

ll n, k, res = 0;
ll fact[maxn];
ll inv[mod];
ll conf[10];
int calls = 0;
bool timeout;

inline ll c(int i) {
	ll res = fact[n];
	for (int j = 0; j < 10; j++) {
		res *= inv[fact[conf[j]]];
		res %= mod;
	}
	return res * inv[fact[n-i]] % mod;
}

void dp(int i, ll curr, int p) {
	// calls++;
	if (curr == k) {
		res += c(i);
		res %= mod;
	}
	if (i == n) return;
	for (int c = p; c < 10; c++) {
		conf[c]++;
		dp(i+1, curr*c%mod, c);
		conf[c]--;
	}
}

int main() {
	ios::sync_with_stdio(false); cout.tie(0);
	cin >> n >> k;

	fact[0] = 1;
	for (int j = 1; j < maxn; j++)
		fact[j] = fact[j-1] * j % mod;

	inv[1] = 1;
	for (int j = 2; j < mod; j++)
		inv[j] = - (mod/j) * inv[mod%j] % mod + mod;

	dp(0, 1, 2);
	cout << res << '\n';
}
