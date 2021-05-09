#include <iostream>
#include <string>
using namespace std;

bool row[9][10];
bool col[9][10];
bool box[9][10];

int sudo[9][9];

void dfs(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;

	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sudo[i][j] << ' ';
			cout << '\n';
		}
		exit(NULL);
	}

	if (sudo[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && box[(x / 3) * 3 + (y / 3)][i] == false) {
				row[x][i] = true;
				col[y][i] = true;
				box[(x / 3) * 3 + (y / 3)][i] = true;
				sudo[x][y] = i;

				dfs(cnt + 1);

				row[x][i] = false;
				col[y][i] = false;
				box[(x / 3) * 3 + (y / 3)][i] = false;
				sudo[x][y] = 0;
			}
		}
	}
	else dfs(cnt + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudo[i][j];
			
			row[i][sudo[i][j]] = true;
			col[j][sudo[i][j]] = true;
			box[(i / 3) * 3 + (j / 3)][sudo[i][j]] = true;
		}
	}

	dfs(0);
}

/*
	백준 2580번 스도쿠
*/
