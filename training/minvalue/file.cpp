#include <iostream>
#include <vector>
#include <map>
#include "minvalue.cpp"

using namespace std;

const int MAX_A = 1e9;

int N;
vector<int> A;
int calls;

int chiedi(int p) {
    ++calls;
    return A[p];
}

int main() {
    cin >> N;
    
    A.resize(N);
    calls = 0;
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int ans = trova(N);
    
    cout << ans << endl << calls << endl;
    
    return 0;
}