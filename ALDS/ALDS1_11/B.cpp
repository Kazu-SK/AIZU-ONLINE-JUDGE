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

vector<vector<int>> Graph(101);
bool visited[101];
int D[101];
int F[101];

int dfs(int n, int d) {

	if (visited[n] == true)
		return d;

	visited[n] = true;

	D[n] = d;
	for (int v_itr = 0; v_itr < Graph[n].size(); v_itr++) {

		if (visited[Graph[n][v_itr]] == false) {
			d++;
			F[Graph[n][v_itr]] = dfs(Graph[n][v_itr], d);
			d = F[Graph[n][v_itr]];
		}
	}

	d++;

	return d;
}

int main()
{
	int N = 0;
	int K = 0;
	int V = 0;
	int n = 0;


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> n >> K;

		for (int k = 0; k < K; k++) {
			cin >> V;
			Graph[n].push_back(V);
		}
	}

	int timer = 0;

	for (int n = 1; n <= N; n++) {
		if (visited[n] == false) {
			timer++;
			//cout << "n = " << n << " " << "timer = " << timer << endl;
			F[n] = dfs(n, timer);
			timer = F[n];
		}
	}

	for (int n = 1; n <= N; n++) {
		cout << n << " " << D[n] << " " << F[n] << endl;
	}

	return 0;
}

