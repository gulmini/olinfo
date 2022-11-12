#include <iostream>
using namespace std;

char d[8] = "dispari";
char p[5] = "pari";

int main() {
	int_fast16_t n; cin >> n;
	cout << ((n & 1) ? d : p);
}
