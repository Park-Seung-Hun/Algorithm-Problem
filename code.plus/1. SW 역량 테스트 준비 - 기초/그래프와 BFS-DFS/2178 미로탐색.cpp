#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int dan[100][100];
int check[100][100];
int dist[100][100];
int N, M, miro;
int dot[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };


void bfs(int x, int y) {
	queue<pair<int, int> > q;
	check[x][y] = 1;
	dist[x][y] = 1;
	q.push(make_pair(x, y));


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			int nx = x + dot[a][0];
			int ny = y + dot[a][1];
			if(ny <= M && nx <= N && nx > 0 && ny > 0){
				if (dan[nx][ny] == 1 && check[nx][ny] == 0)
				{
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		
		}
	}
}//넓이 우선 탐색


int main() {

	cin >> N >> M;

	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= M; b++)
		{
			scanf("%1d", &dan[a][b]);
		}
	}// w h 크기의 사각형 제작


	bfs(1, 1);

	cout << dist[N][M] << ' ';
	


}
