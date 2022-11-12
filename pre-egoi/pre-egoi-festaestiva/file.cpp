#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int maxn = 200001;
const string quack = "quack";

ll n;
unordered_map<ll, ll> idx;
vi v, days;
ll d[maxn];

int organizza(int n, int x, int y, vector<int> a, vector<int> b) {
	::n = n;
	days.push_back(x); days.push_back(y);
	for (int i = 0; i < n; i++) days.push_back(a[i]);
	for (int i = 0; i < n; i++) days.push_back(b[i]+1);
	for (int i = 0; i < maxn; i++) d[i] = 0;

	sort(days.begin(), days.end());

	int p = -1; int j = 0;
	for (int i = 0; i < 2*n+2; i++) {
		if (days[i] != p) {
			p = days[i];
			idx[days[i]] = j++;
		}
	}

	for (int i = 0; i < n; i++) {
		d[idx[a[i]]]--;
		d[idx[b[i]+1]]++;
	}

	ll res = 0;
	ll cnt = n;

	for (int i = 0; i <= idx[y]; i++) {
		cnt += d[i];
		if (i >= idx[x]) res = max(res, cnt);
	}

	return res;
}

