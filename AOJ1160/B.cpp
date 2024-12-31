
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>

using namespace std;
//using LL = long long;

const int EREA_RANGE = 50; //h, wの最大値
int world_Map[EREA_RANGE + 1][EREA_RANGE + 1]; //0:海 1:地
int num_Map[EREA_RANGE + 1][EREA_RANGE + 1]; //エリア[h][w]を数値で定義する。

/*
[1][1]	[1][2]	[1][3]	[1][4]
[2][1]	[2][2]	[2][3]	[2][4]
[3][1]	[3][2]	[3][3]	[3][4]

1	2	3	4
5	6	7	8
9	10	11	12
*/

bool visited[EREA_RANGE * EREA_RANGE + 1]; //訪問済みのエリア
const int MOVE_NUM = 8;
const int DIFF[MOVE_NUM][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} }; //現在のエリアから移動可能のエリアの方向

int H, W;
int ans;
vector<vector<int>> Graph(EREA_RANGE * EREA_RANGE + 1); //接続されている各頂点


void dfs(int num) {

	visited[num] = true;

	for (int itr = 0; itr < Graph[num].size(); itr++) {

		if (visited[Graph[num][itr]] == false)
			dfs(Graph[num][itr]);
	}

	return;
}

void clear() {

	for (int h = 1; h <= EREA_RANGE; h++) {
		for (int w = 1; w <= EREA_RANGE; w++) {
			world_Map[h][w] = 0;
			num_Map[h][w] = 0;
		}
	}

	for (int i = 1; i <= EREA_RANGE * EREA_RANGE; i++) {
		visited[i] = false;
		Graph[i].clear();
	}
}

int main()
{

	while (true) {
		cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		clear();

		int num = 1;
		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {
				cin >> world_Map[h][w];
				num_Map[h][w] = num;
				num++;
			}
		}

		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {

				if (world_Map[h][w] == 1) {
					for (int i = 0; i < 8; i++) {
						int search_h = h + DIFF[i][0];
						int search_w = w + DIFF[i][1];

						if (search_h < 1 || search_h > H)continue;
						if (search_w < 1 || search_w > W)continue;

						if (world_Map[search_h][search_w] == 1)
							Graph[num_Map[h][w]].push_back(num_Map[search_h][search_w]);
					}
				}
			}
		}

		ans = 0;

		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {
				
				if (visited[num_Map[h][w]] == false && world_Map[h][w] == 1) {
					ans++;
					dfs(num_Map[h][w]);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}

