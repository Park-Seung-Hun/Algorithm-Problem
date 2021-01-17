#include <iostream>
#include <vector>
using namespace std;
#define INF 9887654321

int n, del, ans, root;
vector<bool> check;
vector<vector<int>> node;
vector<int> parent;

void dfs(int dot) {
	check[dot] = true;
	if (dot == del) {
		if (parent[dot]==-1) {
			return;
		}
		else {
			if (node[parent[dot]].size() == 1) {

				
				ans++;
			}
			return;
		}
	}
	int size = node[dot].size();

	if (size != 0) {
		for (int i = 0; i < node[dot].size(); i++) {
			int next = node[dot][i];
			if (check[next] == true) continue;
			dfs(next);
		}
	}
	else {
		ans++;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	node.resize(n);
	parent.resize(n);
	check.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != -1) node[x].push_back(i);
		else root = i;
		parent[i] = x;
	}
	cin >> del;

	dfs(root);
	cout << ans;
}
/*
	백준 1068번 트리
*/
