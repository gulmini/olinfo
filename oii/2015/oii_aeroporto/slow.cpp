#pragma GCC optimize("Ofast", "unroll-loops")

inline int max(int a, int b) { return a > b ? a : b; }

int t = 0, k = 0, p = 0;
void pianifica(int n, int a[], int b[], int res[]) {
	res[0] = a[0];
	for (int j = 13; j >= 0; j--) {
		k |= 1 << j;
		for (int i = 1; i < n; i++) {
			res[i] = max(a[i], res[i-1]+k);
			if (res[i] > b[i]) {
				k ^= 1 << j;
				break;
			}
		}
	}
	for (int i = 1; i < n; i++)
		res[i] = max(a[i], res[i-1]+k);
}

