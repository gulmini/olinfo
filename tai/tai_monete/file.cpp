#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<bool> vb;
const string quack = "quack";
constexpr int maxn = 5000001;

int n, k, m;
vi v;
int memo[maxn];
int p[maxn];
deque<pi> q;

int best_score(int n, int k, vector<int> &v) {
	::n = n; ::k = k;
	p[0] = v[0];

	for (int i = 1; i < n; i++)
		p[i] += p[i-1] + v[i];

	for (int i = 0; i < k; i++)
		q.emplace_front(memo[i] = p[i], i);

	for (int i = k; i < n; i++) {
		if (q.back().second < i-k) q.pop_back();
		m = p[i] - q.back().first;
		while (m < q.front().first) q.pop_front();
		q.emplace_front(memo[i] = m, i);
	}

	return memo[n-1];
}
