/*
	단절점과 단절선
	주어진 노드를 이용해 간선을 만든다. edge


	1. 단절점이 주어진 경우 말단 node인지 확인
	2. 단절선이 주어진 경우 모두 단절선이 될수 있으므로 yes
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, q;
vector<vector<int>> edge;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;

	// 초기화
	cin >> n;
	edge.resize(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}


	// 쿼리
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (a == 1) { // 단절점
			if (edge[b - 1].size() >= 2) cout << "yes\n";
			else cout << "no\n";
		}
		else cout << "yes\n";

	}
	return 0;
}
