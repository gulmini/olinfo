#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int direziona(int n, vector<int> a, vector<int> b) {
	int pb = 0, minres = n, maxres = 0;

	for (int i = 0; i < n; i++) {
		while (pb < n and a[i] > b[pb]) pb++;
		if (pb < n) maxres++;
		pb++;
	}

	pb = n-1;
	for (int i = n-1; i >= 0; i--) {
		while (pb >= 0 and a[i] < b[pb]) pb--;
		if (pb >= 0) minres--;
		pb--;
	}

	return maxres - minres + 1;
}

