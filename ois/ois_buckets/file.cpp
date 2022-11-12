#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n, e;
unordered_set<int> s;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e;
		if (s.find(e) != s.end()) {
			cout << "Impossible";
			return 0;
		}
		s.insert(e);
	}
	cout << "Ok";
}