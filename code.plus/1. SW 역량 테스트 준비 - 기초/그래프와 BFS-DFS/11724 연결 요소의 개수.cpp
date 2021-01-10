#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans;
bool check[1001];
vector<int> edge[1001];

void dfs(int idx) {
	check[idx] = true;

	for (int i = 0; i < edge[idx].size(); i++) {
		int next = edge[idx][i];

		if (check[next] == false) {
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			ans++;
			dfs(i);
		}
	}
	cout << ans;

}
/*
	백준 11724번 연결 요소의 개수
*/
