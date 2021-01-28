#include <iostream>
#include <queue>
using namespace std;

int a, b, c, sum;
bool check[1501][1501];
bool ans;

void bfs(int A, int B) {
	queue<pair<int, int>> q;
	q.push(make_pair(A, B));
	check[A][B] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		int tmp = sum / 3;
		int num[3] = { x,y,sum - x - y };
		if (x == tmp && y == tmp && sum - x - y == tmp) {
			ans = true;
			return;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (num[i] < num[j]) {
					int refx = num[i] + num[i];
					int refy = num[j] - num[i];

					if (check[refx][refy] == false) {
						check[refx][refy] = true;
						q.push(make_pair(refx, refy));
					}
				}
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;
	sum = a + b + c;

	if (sum % 3 != 0) cout << 0 << '\n';
	else {
		bfs(a, b);

		if (ans) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

}
/*
	백준 12886번 돌 그룹
*/
