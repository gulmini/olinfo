#include <iostream>
using namespace std;
typedef pair<int, int> pi;

constexpr int maxn = 1e7+5;

struct static_stack {
	static_stack() {}
	pi _s[maxn];
	int p = -1;
	inline pi& top() { return _s[p]; }
	inline void push(pi x) { _s[++p] = x; }
	inline void pop() { --p; }
};

int n, low, part = 0, res = 0;
static_stack s;
int v[maxn];

int main() {
	cin >> n;
	v[0] = 1e9+2, v[n+1] = 1e9+1;
	for (int i = 1; i <= n; i++) cin >> v[i];

	s.push({0, 0});
	for (int i = 0; i < n+2; i++) {
		while (v[s.top().first] < v[i]) {
			auto [l, r] = s.top(); s.pop();
			if (l == r) continue;
			low = s.top().second+1;
			part = (l-low < i-1-r ? r-low : i-1-l)<<1;
			if (part > i-low) part = i-low;
			if (res < part) res = part;
		}

		if (v[s.top().first] == v[i]) s.top().second = i; 
		else s.push({i, i});
	}
	cout << res;
}

