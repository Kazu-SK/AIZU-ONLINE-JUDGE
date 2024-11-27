#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>

using namespace std;
//using long long = long long;

long long StoLLtime(string s_t) {

	long long l_t = 0;

	l_t += (long long)3600 * ((s_t[0] - '0') * 10 + (s_t[1] - '0'));
	l_t += (long long)60 * ((s_t[3] - '0') * 10 + (s_t[4] - '0'));
	l_t += (long long)1 * ((s_t[6] - '0') * 10 + (s_t[7] - '0'));

	return l_t;
}

int main()
{
	int n = 0;
	vector<long long> train_num(86400, 0); //23h59m59s = 86399s

	string s_dep_t, s_arr_t;
	long long l_dep_t, l_arr_t;
	long long max_train_num = 0;
	vector<long long> ans;

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> s_dep_t >> s_arr_t;

			l_dep_t = StoLLtime(s_dep_t);
			l_arr_t = StoLLtime(s_arr_t);

			train_num[l_dep_t] += 1;
			train_num[l_arr_t] -= 1;
		}

		for (int t = 1; t < 86400; t++) {
			train_num[t] += train_num[t - 1];
			max_train_num = max(max_train_num, train_num[t]);
		}

		ans.push_back(max_train_num);
		//cout << max_train_num << endl;

		fill(train_num.begin(), train_num.end(), 0);
		max_train_num = 0;
	}


	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}

