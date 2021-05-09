/*
	백준 1719번 택배
  https://www.acmicpc.net/problem/1719

  조건 1. 무향그래프
  조건 2. 가중치=이용시간
  조건 3. 경로표=한 집하장에서 다른 집하장으로 최단경로로 화물을 이동시키기 위해 가장 먼저 거쳐야하는 집하장을 나타낸 것.
  요구하는 답: 경로표 구하기

  풀이:
  다익스트라 알고리즘을 사용하여 각 집하장에 대해 최단경로를 구한다.
  최단 경로를 갱신할 때 "check"라는 변수를 사용해서 방문 집하장이 첫번쨰 집하장인지 아닌지 구분하고, 경로표를 갱신한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<pair<int,int>>> edge;
vector<vector<int>> ans;
vector<int> dist;
int n, m;

void solve(int start) {
	priority_queue<pair<int, pair<int,int>>> pq;
	pq.push(make_pair(0, make_pair(start, 0)));
	dist[start] = 0;
	int check = 0; // 첫번째 방문 집하장인지 확인하는 변수

  while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		int first = pq.top().second.second;
		check++;
		pq.pop();

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int ncost = edge[cur][i].second;

			if (dist[next] > ncost + cost) {
				if (check == 1) { // 다음에 방문하는 집하장이 처음 방문하는 집하장일때
					dist[next] = ncost + cost;
					ans[start][next] = next; // 경로표 갱신
					pq.push(make_pair(-dist[next],make_pair(next,next))); // 처음 집하장 저장
				}
				else { // 다음에 방문하는 집하장이 처음 방문하는 집하장이 아닐 때
					dist[next] = ncost + cost;
					ans[start][next] = first; // 경로표 갱신(우선순위 큐에 저장된 처음 집하장)
					pq.push(make_pair(-dist[next], make_pair(next, first)));
				}
			}

		}
	}
}

int main() {
	cin >> n >> m;
	edge.resize(n + 1);
	ans.assign(n + 1, vector<int>(n + 1,0));

	// 초기값 입력
	for (int i = 0; i < m; i++) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		edge[node1].push_back(make_pair(node2, cost));
		edge[node2].push_back(make_pair(node1, cost));
	}

	for (int i = 1; i <= n; i++) {
		dist.assign(n + 1, INF);
		solve(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}
