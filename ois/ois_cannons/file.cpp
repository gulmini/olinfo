#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k;
vi v, d;
bitset<1000000> vis = 0;
priority_queue<pi, vector<pi>, greater<pi>> q;

int main() {
	cin >> n;
	v.resize(n); d.resize(n, 1e9);
	for (int i = 0; i < n; i++) cin >> v[i];
	q.push({0, 0}); d[0] = 0;
	while (not q.empty()) {
		auto [f, a] = q.top(); q.pop();
		if (a == n-1) {
			cout << f; return 0;
		}
		if (d[v[a]] > d[a]) {
			d[v[a]] = d[a];
			q.push({d[v[a]], v[a]});
		}
		if (a+1 < n and d[a+1] > d[a]+1) {
			d[a+1] = d[a]+1;
			q.push({d[a+1], a+1});
		}
		if (a-1 >= 0 and d[a-1] > d[a]+1) {
			d[a-1] = d[a]+1;
			q.push({d[a-1], a-1});
		}
	}
}

