
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    int x = 0;
    int ans = 0;


    while (true) {
        cin >> n >> x;

        if (n == 0 && x == 0) {
            break;
        }

        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int z = j + 1; z <= n; z++) {
                    if (i + j + z == x) {
                        ans++;
                    }
                }
            }
        }

		cout << ans << endl;

        ans = 0;
    }


    return 0;
}

