

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int T,n;
vector<int> student;
vector<int> visit;
vector<int> cycle;
vector<int> now;

int dfs(int num) {
	if (now[num]) return num;
	if (visit[num]) return 0; 

	now[num] = 1; visit[num] = 1;
	int next = dfs(student[num]);
	now[num] = 0;

	if (next > 0) {
		cycle[num] = 1;
		if (next != num) return next; 
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test = 0; test < T; test++) {
		cin >> n;
		student.assign(n + 1,0);
		visit.assign(n + 1, 0);
		cycle.assign(n + 1, 0);
		now.assign(n + 1, 0);

		for (int i = 1; i <= n; i++) cin >> student[i];

		for (int i = 1; i <= n; i++) {
			if(cycle[i]==0) dfs(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cycle[i] == 0) cnt++;
		}

		cout << cnt << '\n';
	}
}
/*
	백준 9466번 텀 프로젝트
*/
