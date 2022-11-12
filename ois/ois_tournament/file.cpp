#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n;
vi v;

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll res = 0;
	vi w(n);

	for (int i = 0; i < n; i++) w[i] = v[i] - i;
	res = max(
		res,
		*max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end()
	));

	for (int i = 0; i < n; i++) w[i] = v[i] + i;
	res = max(
		res,
		*max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end()
	));

	cout << res;

}

