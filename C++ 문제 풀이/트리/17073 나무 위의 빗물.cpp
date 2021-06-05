/*
  leaf 노드의 개수를 구하는 문제이다.
  소수점 자리 숫자는 cout.precision(숫자) 로 조절한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int n, water, a, b;
int leaf;
vector<vector<int>> node;
vector<bool> check;

void dfs(int n) {
	check[n] = true;

	int cnt = 0;

	for (int i = 0; i < node[n].size(); i++) {
		int next = node[n][i];
		if (check[next]) continue;
		cnt++;
		dfs(next);
	}

	if (!cnt) leaf++;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(11);

	cin >> n >> water;
	node.resize(n + 1);
	check.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	dfs(1);
	cout << (double)water/leaf;


	return 0;
}
