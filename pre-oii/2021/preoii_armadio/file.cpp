#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
const string quack = "quack";

int maxn = 4000002;
vi phi, lp, pr, divs;
int res;
vector<pi> fact;

void get_divisors() {
	stack<pi> s;
	int c, k = fact.size();
	s.push(pi{1, 0});

	while (not s.empty()) {
		auto [n, i] = s.top(); s.pop();

		if (i == k) {
			if (n >= 3) res += phi[n-1];
			continue;
		}

		auto [base, esp] = fact[i];
		c = 1;

		for (int e = 0; e <= esp; e++) {
			s.push(pi{n * c, i + 1});
			c *= base;
		}
	}
}

void linear_sieve(int n) {
	lp.resize(n+1);

	for (int i = 2; i < n; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}

		for (int j = 0; j < (int)pr.size() and pr[j] <= lp[i] and i*pr[j] <= n; j++)
			lp[i * pr[j]] = pr[j];
	}
}

void totient(int n) {
	phi.resize(n+1);
	iota(phi.begin(), phi.end(), 0);

	for (int i = 2; i <= n; i++) {
		if (phi[i] != i) continue;

		for (int j = i; j <= n; j += i)
			phi[j] -= phi[j] / i;
	}
}

void factorization(int n) {
	int base, esp;
	while (n != 1) {
		esp = 0;
		base = lp[n];

		while (lp[n] == base) {
			esp++;
			n /= lp[n];
		}

		fact.push_back(pi{base, esp});
	}
}

void evadi(int q, vi& v) {
	totient(maxn);
	linear_sieve(maxn);

	for (int i = 0; i < q; i++) {
		fact.clear(); divs.clear();
		res = 0;
		factorization(v[i]);
		get_divisors();
		v[i] = res;
	}
}

