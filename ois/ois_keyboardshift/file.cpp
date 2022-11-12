#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

int main() {
   ll n;
	cin >> n;
	unordered_map<char, char> m;
   m['q'] = 'w';
   m['w'] = 'e';
   m['e'] = 'r';
   m['r'] = 't';
   m['t'] = 'y';
   m['y'] = 'u';
   m['u'] = 'i';
   m['i'] = 'o';
   m['o'] = 'p';
   m['a'] = 's';
   m['s'] = 'd';
   m['d'] = 'f';
   m['f'] = 'g';
   m['g'] = 'h';
   m['h'] = 'j';
   m['j'] = 'k';
   m['k'] = 'l';
   m['z'] = 'x';
   m['x'] = 'c';
   m['c'] = 'v';
   m['v'] = 'b';
   m['b'] = 'n';
   m['n'] = 'm';
   string s;
   string res;
   cin >> s;

   for (auto c: s)
      res += m[c];

   cout << res;
}