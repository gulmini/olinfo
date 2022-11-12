#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";
constexpr ll maxn = 200003;

ll n, x, y, res = 0;
vi cc(maxn);
vector<vi> r(maxn);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cc[x]++;
		r[y].push_back(x);
	}

	for (int y = 0; y < maxn; y++)
		for (auto x: r[y])
			res += (r[y].size() - 1) * (cc[x] - 1);

	cout << res << endl;
}

