#include <algorithm>
#include <iostream>
using namespace std;
constexpr int maxn = 1000001;
const string quack = "quack";

int n;
short v[maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	short p = 0, e;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		e = (v[i] - p + 3) % 3;
		if (e == 2) e = -1;
		if (e) cnt++;
		sum += e;
		p = v[i];
	}

	cout << (cnt-sum)/2 + sum/3*2 + sum%3 << endl;
}

