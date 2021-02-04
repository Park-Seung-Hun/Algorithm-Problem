/*
	백준 1956번 운동
	https://www.acmicpc.net/problem/1956

	조건 1. 유향그래프
	조건 2. 사이클 찾기
	조건 3. road[i][j], 도로 i->j로 가는 길이가 최소가 되는 값
	요구하는 답: 사이클을 이루는 도로의 길이의 합이 최소가 되는 값

	풀이:
	우선, 도로의 길이를 플로이드-와샬 알고리즘을 통해 전부 구해준다.
	이때 사이클을 형성해야하므로, road[i][j],road[j][i]의 값이 둘다 INF가 아니어야한다.
*/

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<int>> road;
int v, e;

void solve() {
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (road[i][k] == INF || road[k][j] == INF) continue;

				if (road[i][j] > road[i][k] + road[k][j])
					road[i][j] = road[i][k] + road[k][j];
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (road[i][j] != INF && road[j][i] != INF) {
				if (ans > road[i][j] + road[j][i]) ans = road[i][j] + road[j][i];
			}
		}
	}
	if (ans != INF) cout << ans << '\n';
	else cout << -1 << '\n';
}
int main() {
	cin >> v >> e;
	road.assign(v + 1, vector<int> (v+1,INF));

	for (int i = 0; i < e; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		road[start][end] = cost;
	}

	solve();
}
