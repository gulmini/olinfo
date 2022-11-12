#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

int presta(int n, int k, vector<int> v) {
	sort(v.begin(), v.end());
	ll res = 0;
	while (k > 0) {
		k-=v.back();
		res++;
	}
	return res;
}

