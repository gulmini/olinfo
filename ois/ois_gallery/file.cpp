#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, q, x, y;
vector<pi> v;
vector<vi> g;
vi tmp;

int check(vi v) {
	int n = v.size();
	tmp.clear();
	for (int i = 1; i < n; i++) {
		tmp.push_back(v[i]-v[i-1]);
	}
	for (int i = 0; i < n-1; i++) {
		if (tmp[i] != tmp[n-i-2]) return -1;
	}
	if (n%2) return v[n/2];
	return accumulate(v.begin(), v.end(), 0)/2;
}

void no() {
	cout << "NO";
	exit(0);
}

int main() {
	cin >> n;
	v.resize(n);
	g.resize(100002);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		g[y].push_back(2*x);
	}
	for (auto &v: g) sort(v.begin(), v.end());
	int p = -1;
	for (int i = 0; i <= 100000; i++) {
		if (g[i].empty()) continue;
		int new_axis = check(g[i]);
		dbg(new_axis);
		if (new_axis == -1) no();
		if (p != -1 and new_axis != p) no();
		p = new_axis;
	}
	cout << "YES";
}

