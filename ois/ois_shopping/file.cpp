#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, k, a, b;
vi v, take, non_take;

int main() {
	cin >> n >> k;
	v.resize(n);
	take.resize(n, -1e17);
	non_take.resize(n, -1e17);

	for (int i = 0; i < n; i++) cin >> v[i];

	if (k > v[0]) take[0] = k-v[0];
	non_take[0] = min(k, v[0]-1);

	for (int i = 1; i < n; i++) {
		take[i] = max(take[i-1], non_take[i-1]) - v[i];
		non_take[i] = (
			take[i] < 0
			? max(take[i-1], non_take[i-1])
			: max(take[i-1], v[i]-1)
		);
	}
	cout << max(non_take[n-1], take[n-1]);
}

