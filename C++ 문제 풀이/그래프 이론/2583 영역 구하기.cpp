#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int box[100][100];
int visited[100][100];

int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };

int n, m, k;
int ans;

void dfs(int cx, int cy) {
	visited[cx][cy] = true;
	ans++;
	for (int i = 0; i < 4; i++) {
		int nx = xx[i] + cx;
		int ny = yy[i] + cy;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m &&visited[nx][ny]==false&&box[nx][ny]==1) {
			
			dfs(nx, ny);
			
		}
	}
}
int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			box[i][j] = 1;
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				box[j][k] = 0;
			}
		}
	}

	int cnt = 0;
	vector<int> aa;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (box[i][j] == 1 && visited[i][j] == false) { 
				ans = 0;
				dfs(i, j); 
				cnt++;
				aa.push_back(ans);
			}
		}
	}

	sort(aa.begin(), aa.end());
	cout << cnt << '\n';
	for (int i = 0; i < aa.size(); i++) {
		cout << aa[i] << ' ';
	}
}
/*
	백준 2583번 영역 구하기
*/	
