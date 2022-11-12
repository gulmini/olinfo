#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

template <typename T> void dbg(vector<T> x) { for (auto e: x) cout << e << ' '; cout << endl; }
template <typename T> void dbg(T x) { cout << "-> " << x << '\n'; }

ll n;
vector<vector<bool>> g;
constexpr array<ll, 26> primes = {
	0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
	43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};
vector<vi> res;

int main() {
	// freopen("out", "w", stdout);
	n = 3;
	int k = n*n+n+1;

	g.resize(k, vector<bool>(k));
	for (int i = 0; i < k-1; i += n) {
		for (int j = 0; j < k; j++) {
			g[(i+j)%k][j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cout << (g[i][j] ? 'X' : '.');
		}
		cout << endl;
	}

	// res.resize(k);
	// for (int i = 0; i < k; i++) {
	// 	for (int j = 0; j < k; j++) {
	// 		if (g[i][j]) res[i].push_back(j);
	// 	}
	// }
	// for (auto v: res) dbg(v);
}
