#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string quack = "quack";

int N;
string s;

void convert(string &s) {
	for (int i = 0; i < s.size(); i++)
		s[i] = tolower(s[i]);
}

int main() {
	cin >> N;
	cin.ignore();

	int res = N;

	for (int i=0; i<N; i++) {
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
