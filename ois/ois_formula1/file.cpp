#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const string quack = "quack";
constexpr int maxn = 2000;

ll t, n, q, p;

struct node {
	ll a, b, c, i, val;

	inline void calc(ll t) {
		val = (t*t) * a + t * b + c;
	}

	inline bool operator<(node& o) {
		if (val == o.val) return i < o.i;
		return val > o.val;
	} 
};

node v[maxn];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i].a >> v[i].b >> v[i].c;
		v[i].i = i+1;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> p >> t; p--;
	
		for (int j = 0; j < n; j++)
			v[j].calc(t);
	
		nth_element(v, v+p, v+n);
		cout << v[p].i << '\n';
	}
}

