#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool check[501];
int s[501][501];
vector<int> save;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		if (x == 1 && check[y] == false) {
			save.push_back(y);
			cnt++;
			check[y] = true;
		}
		else if (y == 1 && check[x] == false) {
			save.push_back(x);
			cnt++;
			check[x] = true;
		}
		s[x][y] = s[y][x] = 1;
	}
	
	check[1] = true;

	for (int i = 0; i < save.size(); i++) {
		int ref = save[i];
		
		for (int j = 1; j <= 500; j++) {
			if (s[ref][j] == 1 && check[j] == false) {
				cnt++;
				check[j] = true;
	
			}
		}

	}

	cout << cnt;
	return 0;
}
/*
	백준 5567번 결혼식
*/
