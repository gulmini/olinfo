#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

bool visita(int n, int v[]) {
	vi a(n), b(n);
	a[0] = v[0], b[n-1] = v[n-1];

	for (int i = 1; i < n; i++) a[i] = a[i-1] + v[i];
	for (int i = n-2; i >= 0; i--) b[i] = b[i+1] + v[i];

	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			return true;

	return false;
}

