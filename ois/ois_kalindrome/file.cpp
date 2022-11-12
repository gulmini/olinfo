#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

int n;
string s;
vi v, divs;

bool check(int k) {
	for (int off = 0; off <= ((n/k) >> 1) * k; off += k)
		for (int i = 0; i < k; i++)
			if (s[off+i] != s[n-k-off+i]) return false;
	return true;
}

int main() {
	divs.reserve(n);
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] != s[n-1-i]) {
			flag[0] = true;
			break;
		}
	}

	if (not flag[0]) {
		cout << 1; return 0;
	}

	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			divs.push_back(i);
			divs.push_back(n/i);
		}
	}
	
	sort(divs.begin(), divs.end());
	for (auto i: divs) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
	cout << n;
}

