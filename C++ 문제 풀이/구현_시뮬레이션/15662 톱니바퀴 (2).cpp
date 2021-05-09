#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a;
vector<int> check;
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
	int T;
	cin >> T;
	a.assign(T+1, vector<int>(8, 0));

	for (int i = 1; i <= T; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			a[i][j] = (s[j] - '0');
		}
	}


	int k;
	cin >> k;

	for (int test = 0; test < k; test++) {
		int num, d;
		check.assign(T + 1, 0);
		cin >> num >> d;
		check[num] = d;

		if (num == 1) {
			for (int i = 1; i <= T-1; i++) {
				if (a[i][2] != a[i + 1][6]) check[i + 1] = -check[i];
				else break;
			}
		}
		else if (num == T) {
			for (int i = T; i >= 2; i--) {
				if (a[i][6] != a[i - 1][2]) check[i - 1] = -check[i];
				else break;
			}
		}
		else {
			for (int i = num; i >= 2; i--) {
				if (a[i][6] != a[i - 1][2]) check[i - 1] = -check[i];
				else break;
			}
			for (int i = num; i <= T - 1; i++) {
				if (a[i][2] != a[i + 1][6]) check[i + 1] = -check[i];
				else break;
			}
		}

		for (int i = 1; i <= T; i++) if (check[i] != 0) cycle(i, check[i]);
	
	}
	int tot = 0;

	for (int i = 1; i <= T; i++) if (a[i][0] == 1) tot++;

	cout << tot;
}

/*
	백준 15662번 톱니바퀴 (2)
*/
