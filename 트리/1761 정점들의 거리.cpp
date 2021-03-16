#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int parent[40001];
int depth[40001];
bool visited[40001];
vector<pair<int,int>> edge[40001];
queue<int> q;

// LCA를 이용한 트리 정점들의 거리 구하기
int LCA(int u, int v) {
	int u_dist = 0; int v_dist = 0;
	int v_parent, u_parent;

	// LCA 과정 중 깊이를 같게 할 때 거리 값도 갱신해준다. 
	if (depth[u] < depth[v]) {
		while (depth[u] != depth[v]) { 
			v_parent = parent[v];

			// 부모정점과 연결된 정점에서 거리 찾기
			for (int i = 0; i < edge[v_parent].size(); i++) {
				if (edge[v_parent][i].first == v) {
					v_dist += edge[v_parent][i].second;
					break;
				}
			}
			v = v_parent;
		}
	}
	else {
		while (depth[u] != depth[v]) {
			u_parent = parent[u];
			// 부모 정점과 연결된 저엄에서 거리찾기
			for (int i = 0; i < edge[u_parent].size(); i++) {
				if (edge[u_parent][i].first == u) {
					u_dist += edge[u_parent][i].second;
					break;
				}
			}
			u = u_parent;
		}
	}


	while (u != v) {
		u_parent = parent[u];
		for (int i = 0; i < edge[u_parent].size(); i++) {
			if (edge[u_parent][i].first == u) {
				u_dist += edge[u_parent][i].second;
				break;
			}
		}
		u = u_parent;

		v_parent = parent[v];
		for (int i = 0; i < edge[v_parent].size(); i++) {
			if (edge[v_parent][i].first == v) {
				v_dist += edge[v_parent][i].second;
				break;
			}
		}
		v = v_parent;
	}
	int answer = u_dist + v_dist;
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 1. edge 정보
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back(make_pair(y,z));
		edge[y].push_back(make_pair(x, z));
	}
	q.push(1);
	visited[1] = true;

	// 2. parent,depth 구하기
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i].first; 

			if (visited[next] == true) continue;

			visited[next] = true;
			depth[next] = depth[here] + 1;
			parent[next] = here;
			q.push(next);
		}
	}

	// 3. LCA
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}
