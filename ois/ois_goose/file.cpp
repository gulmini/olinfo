#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, pos = 0;
vi v, res(7);

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int j = 1; j <= 6; j++) {
		for (int pos = 0; pos < n; pos += j) {
			while (pos < n and v[pos] != 0)
				pos += v[pos];
			if (pos >= n) break;
			res[j]++;
		}
	}

	for (int i = 1; i <= 6; i++)
		cout << res[i] << ' ';
}

