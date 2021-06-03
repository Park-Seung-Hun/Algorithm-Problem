/*
트리의 탐색
거꾸로 거슬러 올라가는 경우를 생각해서 문제를 풀었다.
이때, 제일 마지막에 방문한 점유 땅을 설정하기 위해 check[t]=true 일떄마다
cmp를 갱신해준다.


*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> ans;
vector<bool> check;
int n, q, cmp;

void dfs(int start, int t) {
	//cout << start << ' ' << t << '\n';
	if (t!=-1&&check[t]) {
		cmp = t;
	}

	if (t == -1) {
		ans.push_back(cmp);
		check[start] = true;
		return;
	}


	dfs(start, parent[t]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	parent.resize(n + 1);
	check.resize(n + 1);
	parent[1] = -1;
	for (int i = n; i > 1; i--) {
		parent[i] = i / 2;
	}


	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		cmp = 0;
		dfs(t, t);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
