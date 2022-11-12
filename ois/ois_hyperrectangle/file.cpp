#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n;
vi v;

int main() {
	init();
	cin >> n;
	v.resize(2*n);
	for (int i = 0; i < 2*n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	dbg(v);

	ll res = 1;
	for (int i = 0; i < 2*n; i++) {
		cout << v[i] << ' ';
		if (i == n - 1) cout << '\n';
	}
}
 
