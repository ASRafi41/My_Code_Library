#include <bits/stdc++.h>
using namespace std;

void mergeThem(int *a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) M[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) a[k] = L[i], ++i;
        else a[k] = M[j], ++j;
        k++;
    }
    for(; i < n1; i++) a[k] = L[i], ++k;
    for (; j < n2; j++) a[k] = M[j], ++k;
    return;
}

void mergeSort(int *a, int l, int r) {
    if (l < r) {
        int m = (l + r) >> 1;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeThem(a, l, m, r);
    }
    return;
}

int main() {
    auto st = clock(); // Current Time
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cerr << "Time = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}
