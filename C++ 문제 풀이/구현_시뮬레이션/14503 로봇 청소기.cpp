#include <iostream>
using namespace std;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
	int box[52][52] = { 1 }; 
	
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			box[i][j] = 1;

	int col, row;
	cin >> row >> col;
	int r, c,t;
	cin >> r >> c >> t;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> box[i][j];
		}
	}//빈칸 0, 벽 1

	int cnt = 0;
	r += 1;
	c += 1;
	while (true) {

		if (box[r][c] == 0) {
			box[r][c] = 2;
			cnt++;
		}
		int check = 0;

		for (int i = 0; i < 4; i++) {
			if (box[r + x[i]][c + y[i]] == 1 || box[r + x[i]][c + y[i]] == 2) check++;
		}

		if (check != 4) {
			if (t == 0) {
				if (box[r][c - 1] == 1 || box[r][c - 1] == 2) {
					t = 3;
				}//청소할 공간 x
				else {
					t = 3;
					c--;
				}//청소할 공간 o
			}
			else if (t == 1) {
				if (box[r - 1][c] == 1 || box[r - 1][c] == 2) {
					t = 0;
				}//청소할 공간 x
				else {
					t = 0;
					r--;
				}//청소할 공간 o

			}
			else if (t == 2) {
				if (box[r][c + 1] == 1 || box[r][c + 1] == 2) {
					t = 1;
				}//청소할 공간 x
				else {
					t = 1;
					c++;
				}//청소할 공간 o
			}
			else if (t == 3) {
				if (box[r + 1][c] == 1 || box[r + 1][c] == 2) {
					t = 2;
				}//청소할 공간 x
				else {
					t = 2;
					r++;
				}//청소할 공간 o
			}
		}
		else {
			if (t == 0) {
				if (box[r + 1][c] != 1) r++;
				else break;
			}
			else if (t == 1) {
				if (box[r][c - 1] != 1)c--;
				else break;
			}
			else if (t == 2) {
				if (box[r - 1][c] != 1)r--;
				else break;
			}
			else if (t == 3) {
				if (box[r][c + 1] != 1)c++;
				else break;
			}
		}


	}
	//0 1 2 3 북 동 남 서

	cout << cnt;
	return 0;
}
/*
    백준 14503번 로봇 청소기
*/
