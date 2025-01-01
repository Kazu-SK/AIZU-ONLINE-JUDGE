
/***

与えられた有効グラフG = (V,E)について、頂点1から各頂点への最短距離dを求める。
頂点間の距離はDで共通とする。

***/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>

using namespace std;


int N;
const int RANGE_N = 100; // 入力される可能性のある頂点の数の最大値
const int D = 1;

vector<vector<int>> P(RANGE_N + 1);

int main()
{
	cin >> N;


	vector<int> dist(N + 1, -1);

	int n = 0;
	int k = 0;
	int v = 0;
	for (int i = 0; i < N; i++) {
		cin >> n;
		cin >> k;

		for (int j = 0; j < k; j++) {
			cin >> v;
			P[n].push_back(v);
		}
	}

	queue<int> Q;

	int start_P = 1;//頂点1からスタート
	Q.push(start_P);
	dist[start_P] = 0; //スタート位置の距離は0とする。

	while (!Q.empty()) {
		int pos = Q.front();

		Q.pop();

		for (int i = 0; i < P[pos].size(); i++) {
			int next_P = P[pos][i];

			if (dist[next_P] == -1) { //距離が確定していない場合
				dist[next_P] = dist[pos] + D; //next_Pまでの距離は、スタート位置からposまでの距離にDを足した値
				Q.push(next_P);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << i << " " << dist[i] << endl;
	}

	return 0;
}


