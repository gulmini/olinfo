#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

bool test(string s);

string prepend(string s, int c) {
	return char(c + '0') + s;
}
string append(string s, int c) {
	return s + char(c + '0');
}
string prefix(string s, int len) {
	if (len > s.size()) return s;
	return string(s.begin(), s.begin() + len);
}
unordered_map<string, bool> cache;
bool _test(string s) {
	if (s == "") return 1;
	if (cache.find(s) == cache.end())
		cache[s] = test(s);
	return cache[s];
}

int n;
string s = "";
int streak = 0;
int max_block = 0;

string big_block() {
	while (s.size() < n) {
		if (streak > max_block or streak % 60 == 0 and not _test(s)) break;
		if (_test(append(s, 0))) {
			s = append(s, 0);
			streak = 0;
		}
		else {
			s = append(s, 1);
			streak++;
		}
	}

	if (streak > max_block or streak % 60 == 0 and not _test(s)) {
		s = prefix(s, s.size() - streak);
		while (_test(append(s, 1))) {
			s = append(s, 1);
		}
	}
	return s;
}

string small_block() {
	while (s.size() < n) {
		if (streak > max_block) break;
		if (_test(append(s, 0))) {
			s = append(s, 0);
			streak = 0;
		}
		else {
			s = append(s, 1);
			streak++;
		}
	}

	s = prefix(s, s.size() - streak);
	while (_test(append(s, 1)))
		s = append(s, 1);

	return s;
}

string analizza(int n) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	bool big = _test(string(128, '1'));
	for (int j = big ? 16 : 6; j >= 0; j--) {
		max_block |= 1 << j;
		if (not _test(string(max_block, '1')))
			max_block -= 1 << j;
	}
	
	s = string(max_block, '1');

	::n = n;
	s = max_block < 80
		? small_block()
		: big_block();

	while (s.size() < n) {
		if (_test(prepend(s, 0)))
			s = prepend(s, 0);
		else
			s = prepend(s, 1);
	}
	return s;
}