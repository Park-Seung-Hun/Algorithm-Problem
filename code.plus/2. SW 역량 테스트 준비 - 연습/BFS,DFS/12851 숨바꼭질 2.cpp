#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, k;
int ans_t = 987654321;
int ans_c;
bool check[100001];
map<int, int> m;

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	check[n] = true;

	while (!q.empty()) {
		int line = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if (ans_t < time) continue;
		check[line] = true;

		if (line == k) {
			ans_t = min(ans_t, time);
			ans_c++;
			continue;
		}

		if (line + 1 <= 100000 && check[line + 1] == false) q.push(make_pair(line + 1, time + 1));
		if (line - 1 >= 0 && check[line - 1] == false) q.push(make_pair(line - 1, time + 1));
		if (line * 2 <= 100000 && check[line * 2] == false) q.push(make_pair(line * 2, time + 1));
	}

	cout << ans_t << '\n' << ans_c;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	bfs();
}

/*
	백준 12851번 숨바꼭질 2
*/
