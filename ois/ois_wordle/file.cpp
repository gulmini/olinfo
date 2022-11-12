#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
const string quack = "quack";

ll n;
vi v;
string s;

int main() {
	cin >> n;
	char c;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == '_') count++;
	}
	ll res = 1;
	for (int i = 0; i < count; i++) {
		res *= (26 - (n-count) - i);
	}
	cout << res;
}

