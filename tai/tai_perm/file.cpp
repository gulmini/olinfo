#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";
constexpr int mod = 1000000007;

ll n, fact[1000001];
vi v;

int trova(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = (fact[i-1] * i) % mod;

	if (n <= 3) return fact[n];

	ll res = 0;
	for (int i = 1; i < n; i++) {
		res += fact[i];
		res %= mod;
	}

	return (res + 3) % mod;
}

int main() {
	cin >> n;
	cout << trova(n);
}

