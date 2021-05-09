#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
bool visited[101];
int p[101][101];
int cnt;

void dfs(int start, int end,int depth) {
	visited[start] = true;
	if (b ==start) {

		cnt = depth;
	}
	depth++;
	for (int i = 1; i <= n; i++) {
		if (p[start][i] == 1 && visited[i] == false) {
			dfs(i, end,depth);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;

		p[q][w] = p[w][q] = 1;
	}
	dfs(a, b, 0);
	if (cnt != 0) cout << cnt;
	else cout << -1;
}
/*
	백준 2644번 촌수계산
*/
