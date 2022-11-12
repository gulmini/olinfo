#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

const ll MOD = 1e9 + 7;
ll n, k;
bool b = false;
vector<vi> p;

int main() {
	cin >> n >> k;
	p.resize(2, vi(k+1));
	iota(p[0].begin(), p[0].end(), 0);
	for (int i = 1; i < n; i++) {
		b = not b;
		for (int j = 1; j <= k; j++)
			p[b][j] = (p[not b][j/2] + p[b][j-1]) % MOD;
	}
	cout << p[b][k];
}
