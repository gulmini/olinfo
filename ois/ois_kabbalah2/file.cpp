#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m;
vector<vi> g;
vi freq;
char c;

inline int inv(int x) {
	return 1000*(x%10) + 100*(x%100/10) + 10*(x%1000/100) + 1*(x/1000);
}

void vert_swap() {
	for (int i = 0; i < n/2; i++)
		swap(g[i], g[n-i-1]);
}

void horiz_scan() {
	int curr;
	for (int i = 0; i < n; i++) {
		curr = 10*g[i][0] + 100*g[i][1] + 1000*g[i][2];
		for (int j = 3; j < m; j++) {
			curr /= 10;
			curr += 1000*g[i][j];
			freq[curr]++,	freq[inv(curr)]++;
		}
	}
}

void vert_scan() {
	int curr;
	for (int j = 0; j < m; j++) {
		curr = 10*g[0][j] + 100*g[1][j] + 1000*g[2][j];
		for (int i = 3; i < n; i++) {
			curr /= 10;
			curr += 1000*g[i][j];
			freq[curr]++,	freq[inv(curr)]++;
		}
	}
}

void diag_scan() {
	int curr;
	for (int i = 0; i < n-3; i++) {
		curr = 10*g[i][0] + 100*g[i+1][1] + 1000*g[i+2][2];
		for (int j = 3; i+j < n and j < m; j++) {
			curr /= 10;
			curr += 1000*g[i+j][j];
			freq[curr]++,	freq[inv(curr)]++;
		}
	}
	for (int j = 1; j < m-3; j++) {
		curr = 10*g[0][j] + 100*g[1][j+1] + 1000*g[2][j+2];
		for (int i = 3; i+j < m and i < n; i++) {
			curr /= 10;
			curr += 1000*g[i][i+j];
			freq[curr]++, freq[inv(curr)]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	g.resize(n, vi(m));
	freq.resize(10000);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c, g[i][j] = c - '0';

	horiz_scan(); 
	vert_scan();
	diag_scan();
	vert_swap();
	diag_scan();

	auto res = max_element(freq.begin()+1000, freq.end());
	cout << res - freq.begin() << ' ' << *res;
}

