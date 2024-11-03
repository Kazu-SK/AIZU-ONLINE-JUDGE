
#include <iostream>
#include <vector>

using namespace std;
//using LL = long long;


long long Pow(int x, int y) { //ans = x^y

    long long ans = 1;

    for (int i = 0; i < y; i++) {
        ans *= x;
    }

    return ans;
}

int main()
{
    int x = 0;
    long long ans = 0;


    cin >> x;

    ans = Pow(x, 3);

    cout << ans << endl;

    return 0;
}

