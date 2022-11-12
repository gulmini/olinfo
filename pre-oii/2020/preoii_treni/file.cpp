#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;
const string quack = "quack";

ll n;
vi v;
vector<array<int, 3>> memo;

int tempo_massimo(int n, int a[], int b[]) {
	memo.resize(n);
	memo[0] = {0, a[0], b[0]};

	for (int i = 1; i < n; i++) {
		memo[i][0] = max(memo[i-1][0], max(memo[i-1][1], memo[i-1][2]));
		memo[i][1] = memo[i][0] + a[i];
		memo[i][2] = memo[i-1][0] + b[i];
	}

	return max(memo[n-1][1], memo[n-1][2]);
}

