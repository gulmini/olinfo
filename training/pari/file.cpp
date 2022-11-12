#include <iostream>
using namespace std;
const string quack = "quack";

char d[8] = "dispari";
char p[5] = "pari";

int n;
int main() {
	cin >> n;
	cout << ((n & 1) ? "dispari" : "pari") << endl;
}
