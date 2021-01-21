#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a;
void cycle(int circle, int direct) {
	vector<int> ref;
	ref.assign(8, 0);

	if (direct == -1) {
		for (int i = 0; i < 7; i++) ref[i] = a[circle][i + 1];
		ref[7] = a[circle][0];
	}
	else {
		for (int i = 1; i < 8; i++) ref[i] = a[circle][i - 1];
		ref[0] = a[circle][7];
	}

	for (int i = 0; i < 8; i++) a[circle][i] = ref[i];

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	a.assign(5, vector<int>(8, 0));

	for (int i = 1; i <= 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			a[i][j]=(s[j] - '0');
		}
	}
	

	int k;
	cin >> k;

	for (int test = 0; test < k; test++) {
		int num, d;
		int check[5] = { 0, };
		
		cin >> num >> d;
		check[num] = d;

		if (num == 1) {
			for (int i = 1; i <= 3; i++) {
				if (a[i][2] != a[i + 1][6]) check[i + 1] = -check[i];
				else break;
			}
		}
		else if (num == 2) {
			if (a[num - 1][2] != a[num][6]) check[num - 1] = -check[num];
			for (int i = 2; i <= 3; i++) {
				if (a[i][2] != a[i + 1][6]) check[i + 1] = -check[i];
				else break;
			}
		}
		else if (num == 3) {
			if (a[num + 1][6] != a[num][2]) check[num + 1] = -check[num];
			for (int i = 3; i >= 2; i--) {
				if (a[i][6] != a[i - 1][2]) check[i - 1] = -check[i];
				else break;
			}
		}
		else if (num == 4) {
			for (int i = 4; i >= 2; i--) {
				if (a[i][6] != a[i - 1][2]) check[i - 1] = -check[i];
				else break;
			}
		}

		for (int i = 1; i <= 4; i++) if (check[i] != 0) cycle(i, check[i]);
		
	}
	int tot = 0;

	if (a[1][0] == 1)tot += 1;
	if (a[2][0] == 1)tot += 2;
	if (a[3][0] == 1)tot += 4;
	if (a[4][0] == 1)tot += 8;

	cout << tot;
}

/*
	백준 14819번 톱니바퀴
*/
