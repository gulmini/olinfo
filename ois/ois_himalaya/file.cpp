#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, s;
vi v;
priority_queue<pi, vector<pi>, greater<pi>> q;

int main() {
	cin >> n >> m >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int maxh = s*s/20;

	q.emplace(v[0], 0);

	for (int i = 0; i < n; i++) {
		while (not q.empty() and q.top().first + maxh < v[i]) {
			v[q.top().second] = i-1;
			q.pop();
		}
		q.emplace(v[i], i);
	}
	while (not q.empty()) {
		v[q.top().second] = n-1;
		q.pop();
	}
	for (auto e: v) cout << e << ' ';
}

