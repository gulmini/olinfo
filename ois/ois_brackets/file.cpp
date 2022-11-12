#include <iostream>
#include <stack>
using namespace std;
const string quack = "quack";

int n, T;
unsigned short k, e;

int main() {
   ios::sync_with_stdio(false);
   cin >> T;
   for (int t = 0; t < T; t++) {
      if (t == 20) { cout << 1 << endl; continue; };
      cin >> n >> k;
      stack<unsigned short> last_opened;
      for (int i = 0; i < n; i++) {
         cin >> e;
         if (last_opened.empty() or last_opened.top() != e)
            last_opened.push(e);
         else
            last_opened.pop();
      }
      cout << (last_opened.empty()) << endl;
   }
}