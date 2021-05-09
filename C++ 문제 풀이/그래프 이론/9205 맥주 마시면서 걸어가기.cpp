#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, ans;
vector<pair<int, int>> map;
bool check[110];
bool flag;
int sx, sy, ex, ey;


void dfs(int x,int y) {

	int sum = abs(ex - x) + abs(ey - y);

	if (flag ==true || sum <= 1000) {
		flag = true;
		return;
	}

	for (int i = 0; i < map.size(); i++) {
		if (check[i]) continue;

		sum = abs(map[i].first - x) + abs(map[i].second - y);

		if (sum > 1000) continue;
		else {
			check[i] = true;
			dfs(map[i].first, map[i].second);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> sx >> sy;

		map.clear();
		memset(check, false, sizeof(check));
		

		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			map.push_back(make_pair(x, y));
		}
		cin >> ex >> ey;

		flag = false;
		dfs(sx, sy);

		if (flag == true) cout << "happy\n";
		else cout << "sad\n";
	}
	

}
/*
	백준 9205번 맥주 마시면서 걸어가기
*/
