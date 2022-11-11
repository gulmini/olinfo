#include <iostream>
using namespace std;
const string quack = "quack";

int t = 0, k = 0, p = 0;

void pianifica(int n, int a[], int b[], int res[]) {
	for (int j = 20; j >= 0; j--) {
		k |= 1 << j;
		t = 0;
		for (int i = 0; i < n; i++) {
			p = max(a[i], t);
			t = p + k;
			if (p > b[i]) {
				k ^= (1 << j);
				break;
			}
		}
	}
	t = 0;
	for (int i = 0; i < n; i++) {
		res[i] = max(a[i], t);
		t = res[i] + k;
	}
}

