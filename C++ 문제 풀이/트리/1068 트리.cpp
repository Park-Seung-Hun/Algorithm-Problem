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
		if (parent[dot] == -1) { // root노드가 삭제 노드인 경우
			return;
		}
		else { // root노드가 삭제 노드가 아닌 경우
			if (node[parent[dot]].size() == 1) { // 삭제된 노드의 부모노드가 노드를 하나 더 가질 경우(leaf노드가 됨)
				ans++;
			}
			return;
		}
	}
	int size = node[dot].size();

	if (size != 0) { // 리프노드가 아닌 경우
		for (int i = 0; i < node[dot].size(); i++) {
			int next = node[dot][i];
			if (check[next] == true) continue;
			dfs(next);
		}
	}
	else { // 리프노드인 경우
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

	// 노드 연결
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
