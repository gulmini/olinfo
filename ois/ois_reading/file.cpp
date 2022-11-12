#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n, t;
vector<pair<int, int>> v;
set<int> days;

int main() {
	cin >> n >> t;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].second == -1) v[i].second = t-1;
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < t; i++) days.insert(i);

	int res = 0;
	for (auto [val, d]: v) {
		auto low = days.upper_bound(d);
		if (low == days.begin()) continue;
		days.erase(--low);
		res += val;
	}

	cout << res << endl;
}

