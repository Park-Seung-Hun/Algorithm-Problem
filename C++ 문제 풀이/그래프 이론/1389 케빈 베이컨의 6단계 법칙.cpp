#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000 // 절대 나올 수 없는 경로값

bool cmp(pair<int, int> a, pair<int, int> b) {
	
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int dist[101][101];
	vector<pair<int, int> > ans;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)dist[i][j] = INF;
			else dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a]=1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int save = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) save += dist[i][j];
		}
		ans.push_back(make_pair(save, i));
	}

	sort(ans.begin(), ans.end(), cmp);
	cout << ans[0].second;
}

/*
	백준 1389번 케빈 베이컨의 6단계 법칙
*/
