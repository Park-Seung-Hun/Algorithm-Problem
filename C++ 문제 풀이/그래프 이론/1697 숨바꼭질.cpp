#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
bool check[100001];

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, 0));

	while (!q.empty()) {
		int line = q.front().first;
		int time = q.front().second;
		q.pop();

		if (line == y) {
			cout << time;
			return;
		}

		if (line + 1 <= 100000 && check[line + 1] == false) {
			q.push(make_pair(line + 1, time + 1));
			check[line + 1] = true;
		}
		if (line - 1 >= 0 && check[line - 1] == false) {
			q.push(make_pair(line - 1, time + 1));
			check[line - 1] = true;
		}
		if (2 * line <= 100000 && check[2 * line] == false) {
			q.push(make_pair(2 * line, time + 1));
			check[2 * line] = true;
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	bfs(n, k);

}
/*
	백준 1697번 숨바꼭질
*/
