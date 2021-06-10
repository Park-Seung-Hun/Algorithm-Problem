/*
13237 이진트리
Sol.
1. root 노드 구하기 (부모노드 -1)
2. child 벡터만들기 idx 부모 , value 자식
3. 순회 depth 찾기
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> child;
vector<int> ans;
int N,node,root;

void findDepth(int n, int d) {
	ans[n] = d;

	for (int i = 0; i < child[n].size(); i++) {
		findDepth(child[n][i], d + 1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	child.resize(N);
	ans.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> node;
		if (node == -1) {
			root = i;
			continue;
		}

		child[node - 1].push_back(i);
	}
	findDepth(root, 0);

	for (int i = 0; i < N; i++){
		cout << ans[i] << '\n';;
	}

	return 0;
}
