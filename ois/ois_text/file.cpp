#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m, k, q;
vi a, b;
char c;

int main() {
	cin >> n;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c;
		a[i] = c < 'a';
		b[i] = c == 'i' or c == 'I';
	}
	ll res = 0;
	int p = 0;
	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i < n; i++) {
			if (a[i] and not p) res++;
			p = a[i];
		}
		swap(a, b);
		p = 0;
	}
	cout << res;
}

