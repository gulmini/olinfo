#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;

void Accendi(int n, int start[], int res[]) {
   // for (int i = 0; i < n; i++) cout << start[i] << " "; cout << endl;
   for (int i = n; i > 0; i--) {
      for (int j = 2*i; j <= n; j += i) {
         // cout << i << " calling " << j << endl;
         start[i] = start[i] ^ res[j];
      }
      res[i] = (not start[i]);
   }
   // for (int i = 0; i < n; i++) cout << res[i] << " ";
}

// int main() {
//    int n;
//    cin >> n;
//    vi v(n);
//    vi res(n);
//    for (int i = 0; i < n; i++) cin >> v[i];
//    Accendi(n, v, res);
//    for (int i = 0; i < n; i++) cout << res[i] << " ";
//    cout << endl;
// }