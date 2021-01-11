#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int dan[1001][1001];
int check[1001][1001];
int dist[1001][1001];
int N, M, tomato;
int dot[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
queue<pair<int, int> > q;

void bfs(int x, int y) {
	cout << "BFS" << '\n';



	cout << "X : " << x << " Y : " << y << '\n';

}//넓이 우선 탐색


int main() {

	cin >> N >> M;

	for (int a = 1; a <= M; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			cin >> tomato;
			dan[a][b] = tomato;
			if (dan[a][b] == 1)
			{
				dist[a][b] = 0;
				check[a][b] = 1;
				q.push(make_pair(a, b));
			}
				
		}
	}// N x M크기의 사각형 제작

	// 1 익은 토마토 , 0 안익은 토마토 , -1 토마토 없음

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			int nx = x + dot[a][0];
			int ny = y + dot[a][1];
			if (ny <= N && nx <= M && nx >= 1 && ny >= 1) {
				if (dan[nx][ny] == 0 && check[nx][ny] == 0)
				{
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}

		}
	}

	int ans = 0;
	for (int a = 1; a <= M; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			if (ans < dist[a][b])
			{
				ans = dist[a][b];
			}
		}
	}
	for (int a = 1; a <= M; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			if (dan[a][b]==0&&check[a][b]==0)
			{
				ans = -1;
			}
		}
	}

	cout << ans;
}
