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

constexpr int b = 3;
ll n, x, y;
vi v;
ll flag[10];
vector<pi> q;

int main() {
	init();
	cin >> n;
	q.resize(n*n);
	for (int i = 0; i < n*n; i++) {
		cin >> q[i].second >> q[i].first;
	}
	for (int i = 0; i < n*n; i++) {
		
	}
}

