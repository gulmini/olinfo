#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

int main() {
   ios::sync_with_stdio(false);
   ll n, l, m;
   string s;
   unordered_map<string, ll> words_map;
   unordered_set<string> words_set;
   unordered_set<string> tmp;
   vector<string> words = {};
   cin >> n >> l;
   cin >> m;
   for (int j = 0; j < m; j++) {
      cin >> s;
      words_map[s] = 0;
      words_set.insert(s);
      words.push_back(s);
   }
   for (int i = 1; i < n; i++) {
      cin >> m;
      tmp.clear();
      for (int j = 0; j < m; j++) {
         cin >> s;
         if ((words_set.find(s) != words_set.end()) and (tmp.find(s) == tmp.end())) {
            words_map[s]++;
         }
         tmp.insert(s);
      }
   }
   for (auto e: words) {
      cout << words_map[e] << " ";
   }
   cout << endl;
}