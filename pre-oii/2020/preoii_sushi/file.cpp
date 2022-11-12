#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;

void debug_out() { cout << "\n"; }

template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
	for (auto e: v) cout << e << " ";
	cout << endl;
	return o;
}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define init(filename) freopen("in", "r", stdin)
#else
#define dbg(...)
#define init()
#endif

array<vi, 2> memo;
ll flag[10];

int sushi(int n, int c, vector<int> A) {
	memo[0].resize(c+1); memo[1].resize(c+1);
	bool b = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			if (0) {}
		}
	}
	return 42;
}

