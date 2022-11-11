#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

#define init() freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

ll n, m, k, q;
vi v;

int main() {
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; v[i]++;
	}
	int pos = 0;
	while (not vis[pos]) {
		vis[pos] = 1;
		pos += v[pos]; pos %= n;
	}
	cout << count(vis.begin(), vis.end(), 0) << endl;
	for (int i = 0; i < n; i++) {
		if (not vis[i]) cout << i+1 << ' ';
	}
}

