#include <iostream>
#include <map>
using namespace std;

char num[5][5];
int ans;
map<string, int> m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y,string s) {
	s += num[x][y];

	if (s.size() == 6) {
		if(m[s]==0){
			m[s] = 1;
			ans++;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			dfs(nx, ny, s);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> num[i][j];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, "");
		}
	}

	cout << ans << '\n';
}

/*
	백준 2210번 숫자판 점프
*/
