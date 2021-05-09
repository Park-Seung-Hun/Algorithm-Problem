#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
bool ans;
vector<int> F[2000];
bool check[2000];

void DFS(int idx, int cnt) {
	check[idx] = true;

	if (cnt == 5) {
		ans = true;
		return;
	}
	
	for (int i = 0; i < F[idx].size(); i++) {
		int next = F[idx][i];

		if (check[next] == false) {
			DFS(next, cnt + 1);
		}
	}
	check[idx] = false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		F[x].push_back(y);
		F[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));
		DFS(i, 1);
		if (ans == true) break;
	}

	if (ans == true) cout << 1 << '\n';
	else cout << 0 << '\n';
}
/*
	백준 13023번 ABCDE
*/
