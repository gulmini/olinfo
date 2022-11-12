#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<int, 30> i30;
const string quack = "quack";

ll n, t;
vi v;
ll maxn = 100003;
vector<i30> m;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		i30 bits;
		for (int i = 0; i < 30; i++) bits[i] = 0;
		for (int i = (n / 4) * 4; i <= n; i++) {
			for (int j = 0; j < 30; j++)
				bits[j] ^= (bool) (i & (1 << j));
		} 
		ll maxpow = 0;
		ll res = 0;
		for (int i = 1; i <= n; i <<= 1)
			maxpow++;

		for (int i = 0; i < maxpow; i++) {
			if (bits[i]) res += (1 << i);
			else res += (2 << i);
		}
		cout << res << '\n';
	}
}

