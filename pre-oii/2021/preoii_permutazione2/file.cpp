#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef bitset<1024> vb;
const string quack = "quack";

void sposta();
void stato();
bool chiedi(int);

ll flag[10];
vb found;

void subtask7(ll n, int res[]) {
	array<vi, 40> p;
	ll b = 0; while (b * b <= n) b++;
	for (ll j = 0; j < b; j++) {
		for (ll i = max(b*j, (ll)1); i < min(b*(j+1), n); i++)
			sposta();

		for (ll i = 0; i < n; i++) {
			if (not found[i] and chiedi(i)) {
				found[i] = true;
				p[j].push_back(i);
			}
		}
	}

	stato();
	found = 0;

	for (ll i = n-1; i > 0; i--) {
		sposta();
		ll j = i / b;

		for (auto e: p[j]) {
			if (not found[e] and not chiedi(e)) {
				res[i] = e;
				found[e] = true;
				break;
			}
		}
	}

	ll i = 0;
	while (found[i]) i++;
	res[0] = i;
}

vi ord;
ll x = 0;

inline void mark(ll i, ll j) {
	if ((i+1) % (1 << j) == 0 and not found[i]) {
		found[i] = true;
		ord.push_back(i);
	}
}

void generate_path(ll n) {
	for (ll j = 9; j >= 0; j--) {
		if (not (j % 2))
			for (ll i = 0; i < n; i++) mark(i, j);
		else
			for (ll i = n-1; i >= 0; i--) mark(i, j);
	}
}

void go_to(ll b) {
	if ((x > b) ^ flag[0]) {
		stato();
		flag[0] = not flag[0];
	}

	for (int i = 0; i < abs(x - b); i++)
		sposta();
	x = b;
}

array<ll, 1024> low;
array<vi, 1024> p;

void general(ll n, int res[]) {
	generate_path(n);
	ll maxpow = 1; while (maxpow < n) maxpow <<= 1;
	for (ll i = 0; i < 1024; i++) low[i] = maxpow-1;
	for (ll i = 0; i < n; i++)
		p[maxpow-1].push_back(i);

	for (auto e: ord) {
		go_to(e);
		ll k = (e | (e+1));
		if (k >= n) k = maxpow-1;
		for (auto i: p[k]) {
			if (not (low[i] < e) and chiedi(i)) {
				low[i] = e;
				p[e].push_back(i);
			}
		}
	}

	for (ll i = 0; i < n; i++)
		res[low[i]] = i;
}

void indovina(int n, int A, int B, int C, int res[]) {
	if (B == 1) subtask7(n, res);
	else general(n, res);
}
