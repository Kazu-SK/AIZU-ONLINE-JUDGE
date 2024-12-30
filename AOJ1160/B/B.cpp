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

//vector<vector<pair<int, int>>> Graph(101);
//bool visited[101][101];
//vector < vector<pair<int, int>> Map;
//map<pair<int, int>, bool> visited;
//vector<vector<int>> Map;
//vector<vector<bool>> visited;

int Map[51][51];
bool visited[51][51];

const int DIFF[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1 ,0}, {-1 ,1} };
int W, H;


void dfs(int h, int w) {

	visited[h][w] = true;

	for (int i = 0; i < 8; i++) {

		int search_h = h + DIFF[i][0];
		int search_w = w + DIFF[i][1];

		if (search_h < 1 || search_h > H)continue;
		if (search_w < 1 || search_w > W)continue;

		if (visited[search_h][search_w] == false && Map[search_h][search_w] == 1) {
			dfs(search_h, search_w);
		}
	}

	return;
}

void clear() {

	for (int h = 1; h <= 50; h++) {
		for (int w = 1; w <= 50; w++) {
			Map[h][w] = 0;
			visited[h][w] = false;
		}
	}
}

int main()
{

	while (true) {

		cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		clear();

		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {
				cin >> Map[h][w];
				visited[h][w] = false;
			}
		}

		int land_num = 0;

		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {

				if (visited[h][w] == false && Map[h][w] == 1) {
					land_num++;
					dfs(h, w);
				}
			}
		}

		cout << land_num << endl;

	}


	return 0;
}

