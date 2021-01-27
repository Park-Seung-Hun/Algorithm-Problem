#include <iostream>
using namespace std;

int n, m,MAX,ans;
int box[500][500];

void make() {
	if (MAX < ans)MAX = ans;
	ans = 0;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> box[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (j + 3 < m) {
				for (int k = 0; k < 4; k++) ans += box[i][j + k];
				make();
			}
			if (i + 3 < n) {
				for (int k = 0; k < 4; k++)ans += box[i + k][j];
				make();
			}
			// 일자 (방향이 2개)
 
			if (i + 1 < n && j + 1 < n) {
				ans += box[i + 1][j] + box[i][j + 1] + box[i + 1][j + 1] + box[i][j];
				make();
			}
			//네모 (방향이 1개)
			

			if (i + 2 < n && j + 1 < m) {
				for (int k = 0; k < 3; k++) ans += box[i + k][j];
				ans += box[i + 2][j + 1];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + k][j + 1];
				ans += box[i + 2][j];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + k][j + 1];
				ans += box[i][j];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + k][j];
				ans += box[i][j + 1];
				make();
				// 기억자

				for (int k = 0; k < 2; k++) ans += box[i + k][j] + box[i + 1 + k][j + 1];
				make();

				for (int k = 0; k < 2; k++) ans += box[i + k][j + 1] + box[i + 1 + k][j];
				make();
				//오리 모양

				for (int k = 0; k < 3; k++) ans += box[i + k][j + 1];
				ans += box[i + 1][j];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + k][j];
				ans += box[i + 1][j + 1];
				make();
				//ㅓ ㅏ모양
			}

			if (j + 2 < m && i + 1 < n) {
				for (int k = 0; k < 3; k++) ans += box[i][j + k];
				ans += box[i + 1][j];
				make();

				for (int k = 0; k < 3; k++) ans += box[i][j + k];
				ans += box[i + 1][j + 2];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + 1][j + k];
				ans += box[i][j + 2];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + 1][j + k];
				ans += box[i][j];
				make();
				//기억자

				for (int k = 0; k < 2; k++) ans += box[i][j + 1 + k] + box[i + 1][j + k];
				make();

				for (int k = 0; k < 2; k++) ans += box[i][j + k] + box[i + 1][j + 1 + k];
				make();
				//오리모양 

				for (int k = 0; k < 3; k++) ans += box[i][j + k];
				ans += box[i + 1][j + 1];
				make();

				for (int k = 0; k < 3; k++) ans += box[i + 1][j + k];
				ans += box[i][j + 1];
				make();
				//ㅗ ㅜ모양
			}
			// 기억자 오리모양 ㅗㅜㅏㅓ 모양은 방향이 4개 
		}
	}

	cout << MAX;
	return 0;
}

/*
	백준 14500번 테트로미노
*/
