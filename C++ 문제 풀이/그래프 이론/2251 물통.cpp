#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int A, B, C;
bool check[201][201][201];

void bfs() {
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(0, 0), C));
	vector<int> ans;
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		
		if (check[a][b][c] == false) {
			check[a][b][c] = true;

			if (a == 0) ans.push_back(c);
			if (a + b > B)
				q.push(make_pair(make_pair(a + b - B, B), c));
			else
				q.push(make_pair(make_pair(0, a + b), c));
			if (a + c > C)
				q.push(make_pair(make_pair(a + c - C, b), C));
			else 
				q.push(make_pair(make_pair(0, b), a + c));

			if (b + a > A)
				q.push(make_pair(make_pair(A, b + a - A), c));
			else
				q.push(make_pair(make_pair(b + a, 0), c));
			if (b + c > C)
				q.push(make_pair(make_pair(a, b + c - C), C));
			else 
				q.push(make_pair(make_pair(a, 0), b + c));

			if (c + a > A)
				q.push(make_pair(make_pair(A, b), c + a - A));
			else 
				q.push(make_pair(make_pair(c + a, b), 0));
			if (c + b > B)
				q.push(make_pair(make_pair(a, B), c + b - B));
			else 
				q.push(make_pair(make_pair(a, c + b), 0));

		}

	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	bfs();

}
/*
	백준 2251번 물통
*/
