#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k,ans;
vector<int> visit;

void bfs() {
	queue<int> q;
	q.push(n);
	visit[n] = 0;

	while (!q.empty()) {
		int subin = q.front();
		q.pop();

		if (subin == k) {
			ans = visit[k];
			return;
		}

		if (subin + 1 <= 100000 && visit[subin + 1] > visit[subin] + 1) {
			visit[subin + 1] = visit[subin] + 1;
			q.push(subin + 1);
		}
		
		if (subin - 1 >= 0 && visit[subin - 1] > visit[subin] + 1) {
			visit[subin - 1] = visit[subin] + 1;
			q.push(subin - 1);
		}

		if (subin * 2 <= 100000 && visit[subin * 2] > visit[subin]) {
			visit[subin * 2] = visit[subin];
			q.push(subin * 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	visit.assign(100001, 987654321);
	bfs();
	cout << ans;
}
/*
	백준 13549번 숨바꼭질 3
*/
