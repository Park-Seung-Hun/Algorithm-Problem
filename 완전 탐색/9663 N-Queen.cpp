#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
bool check[15][15];

bool block(int x, int y) {

	for (int i = 0; i < n; i++) {
		if (i != x) {
			if (check[i][y])return false;
		}
	}

	int ref_x = x - 1;
	int ref_y = y - 1;
	while (ref_x >= 0 && ref_y >= 0) {
		if (check[ref_x][ref_y] == true) return false;
		ref_x--;
		ref_y--;
	}

	ref_x = x - 1;
	ref_y = y + 1;
	while (ref_x >= 0 && ref_y < n) {
		if (check[ref_x][ref_y] == true) return false;
		ref_x--;
		ref_y++;
	}

	return true;
}
void n_queen(int x) {
	if (x == n) {
		ans++;
	}
	else {
		for (int y = 0; y < n; y++) {
			check[x][y] = true;
			if (block(x, y)) n_queen(x + 1);
			check[x][y] = false;
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	n_queen(0);
	cout << ans;
}
/*
	백준 9663번 N-Queen
*/
