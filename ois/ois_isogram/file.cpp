#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string quack = "quack";

int n;
string s;

void convert(string &s) {
	for (int i = 0; i < s.size(); i++)
		s[i] = tolower(s[i]);
}

int main() {
	cin >> n;
	cin.ignore();

	int res = n;

	for (int i=0; i<n; i++) {
		getline(cin, s);
		convert(s);
		for (char c = 'a'; c <= 'z'; c++) {
			if (count(s.begin(), s.end(), c) > 2) {
				res--;
				break;
			}
		}
	}
	cout << res;
}
