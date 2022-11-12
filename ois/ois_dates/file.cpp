#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

string s;

bool validate(string sd, string sm, string sy) {
	if (sd.length() > 2) return false;
	if (sm.length() > 2) return false;
	if (sy.length() < 2 or sy.length() > 4) return false;
	int d = stoi(sd), m = stoi(sm), y = stoi(sy);
	if (sy.length() == 3 and y / 100 != 9) return false;
	if (sy.length() == 4 and y / 100 != 19) return false;
	if (m > 12 or m == 0) return false;
	if (d > 31 or d == 0) return false;
	if (m == 4 or m == 6 or m == 9 or m == 11)
		if (d > 30) return false;
	if (m == 2 and d > 28) return false;
	return true;
}

int main() {
	cin >> s;
	int res = 0;
	for (int i = 1; i <= 2; i++) {
		for (int j = i+1; j <= i+2; j++) {
			string sd = s.substr(0, i);
			string sm = s.substr(i, j-i);
			string sy = s.substr(j);
			res += validate(sd, sm, sy);
		}
	}
	cout << res;
}

