#include <iostream>
#include <set>
#include <utility>
using namespace std;
typedef pair<int, int> pi;
constexpr int inf = 1000000000;
constexpr int maxn = 200000;
constexpr int buf_sz = 1 << 15;
const string quack = "quack";

int n, e, res = 0;
multiset<pi> s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
	for (int i = 0; i < n; i++) {
    cin >> e;
		auto it = s.lower_bound(pi(e, -inf));
		if (it == s.end() or it->first != e) {
			if (e) s.insert(pi(e + 2, e));
			res++;
		}
		else {
			int startval = it->second;
			s.erase(it);
			if (e != -startval)
				s.insert(pi(e + 2, startval));
		}
	}
	cout << res * s.empty();
	return 0;
}

