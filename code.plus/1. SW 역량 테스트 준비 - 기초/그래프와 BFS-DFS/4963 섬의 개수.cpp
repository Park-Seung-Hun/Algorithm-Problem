#include <iostream>
#include <queue>
using namespace std;

int dan[50][50];
int check[50][50];
int w, h,land,C=0,num=0;
int check_num;

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	C++;
	check[x][y] = C;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (dan[x + 1][y] == 1 && check[x + 1][y] == 0 && x < h)
		{
			check[x + 1][y] = C;
			q.push(make_pair(x + 1, y));
		}//아래
		if (dan[x - 1][y] == 1 && check[x - 1][y] == 0 && x > 1)
		{
			check[x - 1][y] = C;
			q.push(make_pair(x - 1, y));
		}//위
		 if (dan[x][y + 1] == 1 && check[x][y + 1] == 0 && y < w)
		{
			check[x][y + 1] = C;
			q.push(make_pair(x, y + 1));
		}//오른쪽
		if (dan[x][y - 1] == 1 && check[x][y - 1] == 0 && y >1)
		{
			check[x][y - 1] = C;
			q.push(make_pair(x, y - 1));
		}//왼쪽
		
		if (dan[x-1][y - 1] == 1 && check[x -1 ][y - 1] == 0 && y > 1 && x > 1)
		{
			check[x-1][y - 1] = C;
			q.push(make_pair(x-1, y - 1));
		}//왼쪽 위
		if (dan[x+1][y - 1] == 1 && check[x + 1][y - 1] == 0 && y > 1 && x < h )
		{
			check[x + 1][y - 1] = C;
			q.push(make_pair(x+1, y - 1));
		}//왼쪽 아래
		if (dan[x - 1][y + 1] == 1 && check[x - 1][y +1] == 0 && y <w &&x>1)
		{
			check[x-1][y + 1] = C;
			q.push(make_pair(x-1, y + 1));
		}//오른쪽 위
		if (dan[x + 1][y + 1] == 1 && check[x + 1][y +1] == 0 && y < w && x < h)
		{
			check[x + 1][y + 1] = C;
			q.push(make_pair(x+1, y +1 ));
		}// 오른쪽 아래
	}
	num++;
}//넓이 우선 탐색


int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h가 0 0 일때 중지

		for (int a = 1;a <= h;a++)
		{
			for (int b = 1;b <= w;b++)
			{
				cin >> land;
				dan[a][b] = land;
			}
		}// w h 크기의 사각형 제작


		for (int a = 1;a <= h;a++)
		{
			for (int b = 1;b <= w;b++) 
			{
				if (dan[a][b] == 1 && check[a][b] == 0)
				{
					bfs(a, b);
				}
			}
		}
		for (int a = 1;a <= h;a++)
		{
			for (int b = 1;b <= w;b++)
			{
				check[a][b] = 0;
			}
		}
		cout <<num<<'\n' ;
		num = 0; //섬의 개수 0
		check_num = 0;
		
	}
	

}
