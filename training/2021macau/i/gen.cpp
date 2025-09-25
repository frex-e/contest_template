#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2000000;

int main() {
    cout << MAX_N << "\n";
    for(int i = 0; i < MAX_N; i++) {
        cout << "abcdefghijklmnopqrstuvwxyz"[i % 26] << "\n";
    }
}