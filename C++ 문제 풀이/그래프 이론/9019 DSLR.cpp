#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, A, B;
vector<bool> check;

void bfs(int start,int end) {
	queue<pair<int, string>>q;
	q.push(make_pair(start, ""));
	int ref = 0;

	while (!q.empty()) {
		int num = q.front().first;
		string ans = q.front().second;
		q.pop();

		if (num == end) {
			cout << ans << '\n';
			return;
		}

		ref = (num * 2) % 10000;
		if (check[ref] == false) {
			check[ref] = true;
			q.push(make_pair(ref, ans + 'D'));
		}

		ref = num - 1;
		if (ref == -1) ref = 9999;
		if (check[ref] == false) {
			check[ref] = true;
			q.push(make_pair(ref, ans + 'S'));
		}

		ref = (num % 1000) * 10 + num / 1000; 
		if (check[ref] == false) {
			check[ref] = true;
			q.push(make_pair(ref, ans + 'L'));
		}

		ref = (num / 10) + (num % 10) * 1000;
		if (check[ref] == false) {
			check[ref] = true;
			q.push(make_pair(ref, ans + 'R'));
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> A >> B;
		check.assign(10000, false);
		bfs(A, B);
	}

}
/*
	백준 9019번 DSLR
*/
