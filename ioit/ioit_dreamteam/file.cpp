#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

vi f, p, q;

int main() {
   ll n, k, e;
   cin >> n >> k;
   f.resize(n);
   p.resize(n);
   q.resize(n);
   vi indexes(n);
   for (int i = 0; i < n; i++) {
      cin >> e; f[i] = e;
      cin >> e; p[i] = e;
      cin >> e; q[i] = e;
      indexes[i] = i;
   }
   sort(indexes.begin(), indexes.end(), [&](int a, int b) { return p[a] > p[b]; });

   set<pi> team_score;
   set<ll> team_members;

   for (auto i: indexes) {
      if (team_members.find(f[i]) != team_members.end()) p[i] = q[i] + q[f[i]] - p[f[i]];

      if (team_members.size() < k) {
         team_members.insert(i);
         team_score.insert(pi(p[i], i));

      }
      else if (p[i] > (*(team_score.begin())).first) {

         team_members.erase((*(team_score.begin())).second);
         team_score.erase(team_score.begin());

         team_members.insert(i);
         team_score.insert(pi(p[i], i));
      }
   }
   ll res = 0;
   for (auto i: team_members) res += p[i];
   cout << res << endl;
}