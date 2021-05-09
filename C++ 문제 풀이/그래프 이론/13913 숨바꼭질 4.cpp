#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, k;
bool check[100001];
int save[100001];
void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	check[n] = true;
	
	while (!q.empty()) {
		int line = q.front().first;
		int time = q.front().second;
		q.pop();
		
	
		if (line == k) {
			cout << time << '\n';

			stack<int> ans;
			int now = k;
			int pre = 0;

			while (now!=n) {
				ans.push(now);
				pre = save[now];
				now = pre;
			}
			cout << n << '\n';
			while (!ans.empty()) {
				cout << ans.top() << ' ';
				ans.pop();
			}
			return;
		}

		if (line + 1 <= 100000 && check[line + 1] == false) { 
			q.push(make_pair(line + 1, time + 1)); 
			check[line + 1] = true;
			save[line + 1] = line;
		}
		if (line - 1 >= 0 && check[line - 1] == false) { 
			q.push(make_pair(line - 1, time + 1)); 
			check[line - 1] = true;
			save[line - 1] = line;
		}
		if (line * 2 <= 100000 && check[line * 2] == false) { 
			q.push(make_pair(line * 2, time + 1)); 
			check[line * 2] = true;
			save[line * 2] = line;
		}
	}

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
	백준 13913번 숨바꼭질 4
*/
