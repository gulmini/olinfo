#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

ll n, b;
int res = 0;
string s;

int main() {
	cin >> s >> b;
	n = s.size();
	for (int c = 0; c < 26; c++) {
		int l = 0;
		ll k = 0;
		deque<ll> q;
		q.push_back(0);
		for (int r = 0; r < n; r++) {
			if (s[r] == c + 'a') q.push_back(0);
			else {
				k -= q.back() ? 1ll << q.back() : 0;
				q.back()++;
				k += (1ll << q.back());
			}
			while (k > b) {
				if (q.front()) {
					k -= 1 << q.front();
					q.front()--;
					k += q.front() ? 1 << q.front() : 0;
				}
				else q.pop_front();
				l++;
			}
			res = max(res, r-l+1);
		}
	}
	cout << res;
}

