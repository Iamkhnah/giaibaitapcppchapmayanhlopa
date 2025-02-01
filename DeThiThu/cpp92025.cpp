#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

using namespace std;
int noname(vector<int> ar, int n, int tar) {
    vector<int> result;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (ar[i] != ar[k]) {
                count ++;
            }
        }
        result.push_back(count);
    }
    int min = INT32_MAX;
    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] < min) {
            min = result[i];
        }
    }
    return abs(min - tar + 1);
}

int main() {
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    long long n, c;
    int q;
    cin >> n >> q >> c;
    if (c < 1) return 0;
    if (c > n) return 0;
    if (n > pow(10, 5)) return 0;
    if (q < 1) return 0;
    if (q > 400) return 0;
    
    vector<int> gg(n);
    for (int i = 0; i < n; i++) {
        cin >> gg[i];
        if (gg[i] < 1) {
            return 0;
        }
    }
    for (int v = 0; v < q; v++) {
        int k, x;
        cin >> k >> x;
        if (k < 1) return 0;
        if (k > n) return 0;
        if (x < 1) return 0;
        if (x > c) return 0;
        int n1 = n / k + 1;

        vector<vector<int>> ar(n1, vector<int>(k, 0));

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < k && (i * k + j) < n; j++) {
                ar[i][j] = gg[i * k + j];
            }
        }
       int noideaname = noname(ar[v], n1, x);
        cout << noideaname << endl;
    }
    return 0; // ko dung chat gpt nen code se hoi ngu
}
