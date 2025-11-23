/*
    Mc Carthy isa famous theorician of computer science. In his work, he defined a recursive function,
    called f91, that takes as input a positive integer N and returns a positive integer defined as follows:
    • IfN≤100, then f91(N)=f91(f91(N+11));
    • IfN≥101, then f91(N)=N−10.
    Write a program, that computes Mc Carthy’s f91.
 */

#include <bits/stdc++.h>
using namespace std;

int f91(int N) {
    if (N >= 101) return N-10;
    return f91(f91(N+11));
}

int main() {
    int N;

    while (cin >> N && N != 0) {
        cout << "f91(" << N << ") = " << f91(N) << endl;
    }

    return 0;
}