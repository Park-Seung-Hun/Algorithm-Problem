#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > node;
vector<bool> visited;
int n;
int parent[100001];

void dfs(int dot) {
	visited[dot] = true;

	for (int i = 0; i < node[dot].size(); i++) {
		int there = node[dot][i];

		if (visited[there] == false) {
			parent[there] = dot;
			dfs(there);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;
	node.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n-1; i++) {
		int x,y;
		cin >> x >> y;

		node[x].push_back(y);
		node[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) cout << parent[i]<<'\n';
}

/*
	백준 11725번 트리의 부모 찾기
*/
