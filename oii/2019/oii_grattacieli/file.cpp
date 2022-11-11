#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr int inf= 1e9;
const string quack = "quack";

priority_queue<pi, vector<pi>, greater<pi>> q;
vector<vector<pi>> adj;

long long costruisci(int n, int m, vector<long long>& d, vector<int>& a, vector<int>& b, vector<int>& w) {
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        adj[a[i]].push_back({ b[i], w[i] });
    }
    for (int i = 0; i < n; i++) {
        if (not adj[i].empty()) q.push({ d[i], i });
    }
    while (not q.empty()) {
        auto [f, a] = q.top(); q.pop();
        if (f > d[a]) continue;
        for (auto [b, w]: adj[a]) {
            if (d[b] > d[a] + w) {
                d[b] = d[a] + w;
                q.push({ d[b], b });
            }
        }
    }
    return accumulate(d.begin(), d.end(), 0ll);
}
