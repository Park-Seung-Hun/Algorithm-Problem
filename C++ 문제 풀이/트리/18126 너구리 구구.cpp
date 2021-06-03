#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, a, b;
long long c;
vector<vector<pair<int,long long>>> node;
vector<bool> check;
long long answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1. node 정보를 받아 edge를 만들어 준다
	cin >> n;
	node.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		node[a].push_back(make_pair(b,c));
		node[b].push_back(make_pair(a, c));
	}

	// 2. 방을 타고 내려가면서 cost를 갱신한다
	queue<pair<int, long long>> q;
	q.push(make_pair(1, 0));
	check[1] = true;

	while (!q.empty()) {
		int Node = q.front().first;
		long long cost = q.front().second;
		q.pop();

		for (int i = 0; i < node[Node].size(); i++) {
			int nextNode = node[Node][i].first;
			long long nextCost = node[Node][i].second;
			if (check[nextNode]) continue;

      // 최대 값을 만들어준다.
			if (nextCost + cost > answer) answer = nextCost + cost;
			q.push(make_pair(nextNode, nextCost + cost));
			check[nextNode] = true;
		}
	}

	cout << answer << '\n';
	return 0;
}
