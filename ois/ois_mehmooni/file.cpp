#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, a, b;
vector<pi> v;
int cnt = 0;
ll res = 0;

int main() {
	cin >> n;
	v.reserve(2*n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, +1});
		v.push_back({b, -1});
	}
	sort(v.begin(), v.end());
	for (auto [_, w]: v) {
		if (w == +1) cnt++;
		res += cnt;
		if (w == -1) cnt--;
	}
	cout << res;
}

