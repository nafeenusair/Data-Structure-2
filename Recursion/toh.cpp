/*
    Problem: Tower of Hanoi
  Rules:
    1. Three pegs: A, B, C.
    2. n disks of different sizes, initially on A (largest at bottom).
    3. Goal: Move all disks from A to C.
    4. Constraints:
        - Move only one disk at a time.
        - Never place a larger disk on top of a smaller disk.
    Task: Print the steps to solve the puzzle efficiently.
    Note: Minimum moves required is 2^n - 1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> B;
vector<int> C;
int N, M;
int cnt = 0;

void printTowers() {
    cout << "A=>";
    if (!A.empty()) cout << "   ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i < A.size() - 1) cout << " ";
    }
    cout << endl;

    cout << "B=>";
    if (!B.empty()) cout << "   ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i];
        if (i < B.size() - 1) cout << " ";
    }
    cout << endl;

    cout << "C=>";
    if (!C.empty()) cout << "   ";
    for (int i = 0; i < C.size(); i++) {
        cout << C[i];
        if (i < C.size() - 1) cout << " ";
    }
    cout << endl << endl;
}

void toh(vector<int> &A, vector<int> &B, vector<int> &C, int n) {
    if (cnt >= M) return;
    //base
    if (n == 1) {
        int x = A.back();
        A.pop_back();
        C.push_back(x);
        cnt++;
        printTowers();
        return;
    }
    else {
        toh(A, C, B, n - 1);

        if (cnt >= M) return;

        int x = A.back();
        A.pop_back();
        C.push_back(x);
        cnt++;
        printTowers();

        if (cnt >= M) return;

        toh(B, A, C, n - 1);
    }
}

int main() {
    int caseNum = 1;

    while (cin >> N >> M && (N != 0 or M != 0)) {
        A.clear();
        B.clear();
        C.clear();
        cnt = 0;

        for (int i = N; i >= 1; i--) {
            A.push_back(i);
        }

        cout << "Problem #" << caseNum++ << endl << endl;

        printTowers();
        toh(A, B, C, N);
    }

    return 0;
}