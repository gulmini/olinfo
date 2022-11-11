#include <vector>
#include <array>
using namespace std;
typedef vector<int> vi;
typedef u_int8_t sh;
constexpr int maxn = 100000;
constexpr int flag = 4;
const string quack = "quack";

array<vi, 3> table;
vector<sh> grp(maxn, flag);
int * nxt;

void nuovo_gruppo();
void aggiungi(int);

inline int dfs(int i) {
  if (grp[nxt[i]] != flag) return grp[i] = not grp[nxt[i]];
  grp[i] = 0;
  return grp[i] = not dfs(nxt[i]);
}

void smista(int n, int nemico[]) {
  nxt = nemico;
  for (int i = 0; i < n; i++) {
    if (grp[i] == flag)
      grp[i] = dfs(i);
  }
  for (int i = 0; i < n; i++) {
    if (grp[i] == grp[nemico[i]]) grp[nemico[i]] = 2;
  }
  for (int i = 0; i < n; i++) {
    table[grp[i]].push_back(i);
  }
  for (int i = 0; i < 3; i++) {
    if (table[i].empty()) continue;
    nuovo_gruppo();
    for (auto e: table[i])
      aggiungi(e);
  }
}

