#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";
constexpr ll INF = INT32_MAX / 2;
constexpr ll shift = 1001;
constexpr ll maxd = 100001;
constexpr ll maxn = 500;

array<ll, maxd+2*shift> m;
ll n, d, X[maxn], R[maxn], WR[maxn], WT[maxn], D[maxn];

inline ll calc(ll a, ll b, ll i) {
	const ll x = X[i];
	if ((x-a)*(x-b) > 0) return WT[i] * abs(a - b);
	else return WR[i] + WT[i] * abs(2*x - a - b);
}

ll linear_dp() {
	for (ll i = 0; i < n; i++) {
		const ll x = X[i], r = R[i];
		for (ll a = x-r; a <= x+r; a++) {
			if (a == x) continue;
			ll pickup = (
				WR[i] * (D[i] ^ (a > x)) +
				WT[i] * (min(a - (x-r), (x+r) - a))
			);
			for (ll b = x-r; b <= x+r; b++) {
				if (b == x or m[a+shift] >= m[b+shift]) continue;
				m[b+shift] = min(
					m[b+shift],
					m[a+shift] + pickup + calc(a, b, i)
				);
			}
		}
	}
	return m[d+shift];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> d >> n;
	for (int i = 0; i < n; i++)
		cin >> X[i] >> R[i] >> WR[i] >> WT[i] >> D[i];
	for (ll i = 0; i < maxd+2*shift; i++)
		m[i] = INF;
	m[shift] = 0;
	cout << linear_dp() << endl;
}

