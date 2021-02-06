#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ice[300][300];
int save[300][300];
bool visited[300][300];

int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int n, m, check, year;


void dfs(int x, int y) {
	visited[x][y]=true;
	int nx = 0;
	int ny = 0;
	
	for (int i = 0; i < 4; i++) {
		nx = xx[i] + x;
		ny = yy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false) {
			if (ice[nx][ny] == 0) {
				save[x][y]++;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		nx = xx[i] + x;
		ny = yy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false && ice[nx][ny] != 0) {		
			dfs(nx, ny);
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}

	while (true) {
		check = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0 && visited[i][j] == false) {
					dfs(i, j);
					check++;
				}
			}
		}

		if (check == 0) { year = 0; break; }
		else if (check >= 2) { break; }
		year++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
				if ((ice[i][j] - save[i][j]) < 0) ice[i][j] = 0;
				else {
					ice[i][j] -= save[i][j];
				}

				save[i][j] = 0;
			}
		}
	}
	cout << year;
}
/*
    백준 2573번 빙산
*/
