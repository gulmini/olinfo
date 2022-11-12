#include <bits/stdc++.h>
using namespace std;

int chiedi(int p);

int f(int n, int r, int l, int cycle, vector<int> & asked) {

    cerr << "l = " << l << " r = " << r << endl; 
    if (cycle == 25) {
        int res = 0;
        int val = INT32_MAX;
        int i;
        for (i = 0; i < n; i++) {
            if (asked[i] < val) {
                val = asked[i];
                res = i;
            }
        }
        // cerr << "res = " << res << endl;
        return res; 
    }
    int li = (r + l) / 2;
    int ri = li + 1;

    cerr << "   li " << li << " ri " << ri << endl;
    if (asked[li] == INT32_MAX) asked[li] = chiedi(li);
    if (asked[ri] == INT32_MAX) asked[ri] = chiedi(ri);

    for (int i = 0; i < n; i++) cerr << asked[i] << " ";
    cerr << endl;

    if (asked[li] < asked[ri])
        return f (n, l, ri, cycle + 1, asked);
    else
        return f(n, li, r, cycle + 1, asked);
}

int trova(int n) {
    vector<int> asked(n, INT32_MAX);
    if (n == 1) return 0;
    if (n == 2) return bool(chiedi(1) < chiedi(0));

    return f(n, 0, n, 0, asked);
}