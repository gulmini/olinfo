#include <iostream>
#include <iomanip>
using namespace std;
constexpr int maxn = 3000;
const string quack = "quack"

double c[maxn][maxn], v[maxn][maxn], memo[maxn][maxn];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;

	if (n == 1) { cout << 1 << endl; return 0; }

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> c[i][j] >> v[i][j];

	double pb = 1;

	for (int j = 0; j < k; j++) {
		memo[n-1][j] = v[n-1][j];
		pb = max(pb, v[n-1][j] / c[n-2][j]);
	}

	for (int i = n-2; i > 0; i--) {

		for (int j = 0; j < k; j++)
			memo[i][j] = max(memo[i+1][j], v[i][j] * pb);

		for (int j = 0; j < k; j++)
			pb = max(pb, memo[i][j] / c[i-1][j]);

	}

	cout << fixed << setprecision(9) << pb << endl;
}

