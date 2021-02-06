#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int box[20][20];
int check[20][20];
// 거리가 가까운 물고기 여러마리일때 가장위
// 가장 위에 거리가 가까운 물고기가 여러마리 일때 왼쪽

int n,sx,sy,eat;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int bfs(int x,int y,int size) {
	queue<pair<int, int > > q;
	q.push(make_pair(x, y));

	int xx[4] = { 0,0,1,-1 };
	int yy[4] = { 1,-1,0,0 };

	vector<pair<int, int> > ans;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + xx[i];
			int ny = cy + yy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == 0&&box[nx][ny]<=size) {
				if (box[nx][ny] < size&&box[nx][ny]!=0) {
					ans.push_back(make_pair(nx, ny));
				}
				check[nx][ny] = check[cx][cy]+1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (!ans.empty()) {
		sort(ans.begin(), ans.end(), cmp);
		int min = 1000;

		int rx = 0; int ry = 0;

		for (int i = 0; i < ans.size(); i++) {
			int ax = ans[i].first;
			int ay = ans[i].second;
			if (check[ax][ay] < min) { 
				min = check[ax][ay]; 
				rx = ax;
				ry = ay;
			}
		}

		box[sx][sy] = 0; box[rx][ry] = 0;
		sx = rx; sy = ry;

		eat++;
		return min;

	}
	else {
		return 0;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i][j];
			if (box[i][j] == 9) {
				sx = i;
				sy = j;
			}
		}
	}

	int s = 2;
	int answer = 0;
	while (true) {
		int t = bfs(sx, sy, s);

		if (eat == s) {
			s++;
			eat = 0;
		}

		if (t == 0) {
			cout << answer << '\n';
			break;
		}
		else {
			answer += t;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = 0;
			}
		}
		
	}
	
	return 0;
}
/*
    백준 16236번 아기 상어
*/
