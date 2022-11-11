#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack"

#define init() freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

ll n, m;
int res = 0;
vector<vi> g;

bool safe(int x) {
	int i = x / m;
	int j = x % m;
	if (i >= 2 and g[i][j] and g[i-1][j] and g[i-2][j]) return false;
	if (j >= 2 and g[i][j] and g[i][j-1] and g[i][j-2]) return false;
	if (i >= 2 and j >= 2 and g[i][j] and g[i-1][j-1] and g[i-2][j-2]) return false;
	if (i >= 2 and j < m-2 and g[i][j] and g[i-1][j+1] and g[i-2][j+2]) return false;
	return true;
}

void bnb(int x, int r) {
	res = max(res, r);
	if (x == n*m) return;
	if (n*m - x + r <= res) return;
	int i = x / m;
	int j = x % m;
	g[i][j] = 1;
	if (safe(x)) {
		bnb(x+1, r+1);
	}
	g[i][j] = 0;
	bnb(x+1, r);
}

int main() {
	init();
	cin >> n >> m;
	g.resize(n, vi(m));
	bnb(0, 0);
	cout << res << endl;
}

