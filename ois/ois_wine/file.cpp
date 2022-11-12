#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll n, m, l, r, k;
vi v, p;

ll counts(ll x) {
   // conta tutte le sequenze di valore <= x
   ll res = 0;
   for (int i = 0; i <= n; i++) {
      // d e' il primo elemento da cui parte una sequenza <= x che finisce in i
      int d = lower_bound(p.begin(), p.end(), p[i]-x) - p.begin();
      // aggiungi al risultato tutte le sequenze che finiscono in i
      res += i - d;
   }
   return res;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
   cin >> n >> k;
   v.resize(n+1); p.resize(n+1);
   for (int i = 1; i <= n; i++) cin >> v[i];
   // p e' un semplice prefix sum array
   for (int i = 1; i <= n; i++) p[i] = p[i-1] + v[i];

   // assumendo v[i] <= 1e9 e n <= 2*1e5, la somma non eccede (1 << 48)
   l = 0; r = (1LL << 48); m = 14;

   // binary search sul risultato di counts
   // m essendo il termine di mezzo finisce per rappresentare il risultato della ricerca
   while (l < r) {
      m = (l+r) / 2;
      if (counts(m) < k) l = m+1;
      else r = m;
   }
   if (counts(m) < k) m++;

   // riduco il problema alla k-esima sequenza di lunghezza m
   k -= counts(m-1);
   
   for (int i = 0; i <= n; i++) {
      // per ogni elemento i cerco se esiste una sequenza di quella stessa lunghezza
      // essendo ogni v[i] > 0 puo' esistere una sola sequenza per ogni iterazione
      auto low = lower_bound(p.begin(), p.end(), m+p[i]);
      // se l'elemento va oltre l'array oppure non esiste nell'array si salta
      if (low == p.end() or *low != m+p[i]) continue;
      if (k == 1) {
         cout << i << " " << (low - p.begin() - 1) << endl;
         return 0;
      }
      k--;
   }
   cout << k;
}