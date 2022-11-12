#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

struct node {
   ll div1, div2, div3, offset;
   node(ll d1, ll d2, ll d3, ll off): div1(d1), div2(d2), div3(d3), offset(off) {}
   node operator+(node other) {
      return node (
         div1 + other.div1,
         div2 + other.div2,
         div3 + other.div3,
         0
      );
   }
   void apply(int x) {
      if (x == 0) return;
      ll tmp;
      for (int i = 0; i < x % 3; i++) {
         tmp = div1;
         div1 = div3;
         div3 = div2;
         div2 = tmp;
      }
      offset += x % 3;
   }
};

vector<node> tree;
ll n, q, a, b, type;

void push(int i) {
   tree[2*i].apply(tree[i].offset);
   tree[2*i+1].apply(tree[i].offset);
   tree[i].offset = 0;
}

void update(int i, int l, int r, int a, int b) {
   if (a <= l and r <= b) {
      tree[i].apply(1);
      return;
   }
   if (r < a or l > b) return;
   push(i);
   int m = (l+r)/2;
   update(2*i, l, m, a, b);
   update(2*i+1, m+1, r, a, b);
   tree[i] = tree[2*i] + tree[2*i+1];
}

ll query(int i, int l, int r, int a, int b) {
   if (a <= l and r <= b) return tree[i].div3;
   if (r < a or l > b) return 0;
   push(i);
   int m = (l+r)/2;
   return (
      query(2*i, l, m, a, b) +
      query(2*i+1, m+1, r, a, b)
   );
}

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   cin >> n >> q;

   while (__builtin_popcount(n) != 1) n++;
   tree.assign(2*n, node(0, 0, 1, 0));

   for (int i = n-1; i >= 1; i--)
      tree[i] = tree[2*i] + tree[2*i+1];

   while (q--) {
      cin >> type >> a >> b;
      if (type == 0)
         update(1, 0, n-1, a, b);
      else
         cout << query(1, 0, n-1, a, b) << "\n";
   }
}