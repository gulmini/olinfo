#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

struct node {
   ll sum, n, marked;
   node(): sum(0), n(1), marked(false) {}
   node(ll sum, ll n, bool marked): sum(s), n(n), marked(marked) {}
   node operator+(node other) {
      return node(sum + other.sum, n + other.n, false);
   }
   void apply(bool mark) {
      if (not mark) return;
      marked = not marked;
      sum = n - sum;
   }
};

vector<node> tree;
ll n, q, a, b, type;

void push(int i) {
   if (not tree[i].marked) return;
   tree[2*i].marked = not tree[2*i].marked;
   tree[2*i+1].marked = not tree[2*i+1].marked;
   tree[2*i].sum = tree[2*i].n - tree[2*i].sum;
   tree[2*i+1].sum = tree[2*i+1].n - tree[2*i+1].sum;
   tree[i].marked = false;
}

void update(int i, int l, int r, int a, int b) {
   if (a <= l and r <= b) {
      tree[i].marked = not tree[i].marked;
      tree[i].sum = tree[i].n - tree[i].sum;
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
   if (a <= l and r <= b) return tree[i].sum;
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
   tree.assign(2*n, node(0, 1, false));

   for (int i = n-1; i >= 1; i--)
      tree[i] = tree[2*i] + tree[2*i+1];

   while (q--) {
      cin >> type >> a >> b;
      if (type == 0)
         update(1, 0, n-1, a, b);
      else
         cout << query(1, 0, n-1, a, b) << endl;
   }   
}