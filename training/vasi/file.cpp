#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int bs = 450;
const string quack = "quack";

ll n, q, ix, a, b;
char type;
vi v;
vector<deque<int>> tree;

int main() {
	cin >> n >> q;
	tree.resize(n/bs+1);

	for (int i = 0; i < n; i++)
		tree[i/bs].push_back(i);
	
	while (q--) {
		cin >> type;
		if (type == 'c') {
			cin >> ix;
			cout << tree[ix/bs][ix%bs] << ' ';
		}
		else {
			cin >> ix >> b;
			int e = tree[ix/bs][ix%bs];
			tree[ix/bs].erase(tree[ix/bs].begin() + (ix%bs));

			for (int i = ix/bs; i < b/bs; i++) {
				tree[i].push_back(tree[i+1].front());
				tree[i+1].pop_front();
			}

			for (int i = ix/bs; i > b/bs; i--) {
				tree[i].push_front(tree[i-1].back());
				tree[i-1].pop_back();
			}

			tree[b/bs].insert(tree[b/bs].begin() + (b%bs), e);
		}
	}
}

