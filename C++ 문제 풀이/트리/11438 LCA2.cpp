#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100111

int n, m;
int p[MAX][18];
int parent[MAX];
int depth[MAX];
bool visited[MAX];
vector<int> edge[MAX];
queue<int> q;

int LCA(int u, int v) {

	// depth[u]>=depth[v]로 swap
	if (depth[u] < depth[v]) swap(u, v);

	if (depth[u] != depth[v]) {
		for (int j = 18; j >= 0; --j)
			if (depth[u] - (1 << j) >= depth[v])
				u = p[u][j];
	}



	if (u != v) {
		for (int i = 18; i >= 0; --i) {
			if (depth[u] - (1 << i) >= 0 && p[u][i]!=p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return p[u][0];
	}
	else return u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1. edge 만들기
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int to, from;
		cin >> to >> from;
		edge[to].push_back(from);
		edge[from].push_back(to);
	}

	// 2. 정보 저장	
	depth[1] = 0; visited[1] = true; q.push(1); parent[1] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i];

			if (visited[next] == true) continue;
			visited[next] = true;
			parent[next] = here;
			depth[next] = depth[here] + 1;
			q.push(next);
		}
	}

	// p[i][j] = 노드 i의 2^j번째 조상 초기화
	for (int i = 1; i <= n; i++) p[i][0] = parent[i];

	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			// 2^j-1번째 조상 노드가 존재할 때
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';;
	}
	return 0;
}
