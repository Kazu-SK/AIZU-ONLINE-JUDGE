
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>

using namespace std;
//using LL = long long;

int main()
{
    int n = 0;
    int m = 0;
    

    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> M(m);
    vector<bool> ans(m);

    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    for (int num = 0; num < (1 << n); num++) {

        int sum_A = 0;

        for (int bit = 0; bit < n ; bit++) {
            if (num & (1 << bit)) {
                sum_A += A[bit];
            }
        }

        for (int i = 0; i < m; i++) {
            if (sum_A == M[i]) {
                ans[i] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}

