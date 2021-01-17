#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321;

int n, m, k, x;
int dist[300001];
vector<pair<int, int> > edge[300001];

void dijk(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));


	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i].first;
			int ncost = edge[here][i].second;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(make_pair(to, 1));
	}

	for (int i = 1; i <= n; i++) dist[i] = INF;

	dijk(x);
	vector<int> cnt;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k)	cnt.push_back(i);
	}

	if (!cnt.empty()) {
		sort(cnt.begin(), cnt.end());
		for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << '\n';
	}
	else cout << -1;

}
/*
	백준 18352번 특정 거리의 도시 찾기
*/
