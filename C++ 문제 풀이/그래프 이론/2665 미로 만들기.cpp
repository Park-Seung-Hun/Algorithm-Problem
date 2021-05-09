/*
	백준 2665번 미로만들기
	https://www.acmicpc.net/problem/2665

  조건 1. 검은방 0, 흰방 1으로 저장
	조건 2. 검은방->흰방으로 바꿀때 cnt 1씩 증가
	요구하는 답: cnt의 값을 최소로하여 목적지인 맨 오른쪽 아래로 도착하기.

	풀이:
	BFS 알고리즘을 사용하여 미로의 끝으로 향한다.
	이때 현재 있는 미로의 좌표에서 다음 좌표로 넘어갈 때 2가지 경우로 나누는데,
	경우 1) 다음 좌표가 흰방이고, 다음 좌표에서의 cnt 값 > 현재 cnt 값
	경우 2) 다음 좌표가 검은방이고, 다음 좌표에서의 cnt값 >  현재 cnt 값 + 1
	위의 두가지 경우에만 다음 좌표의 cnt 값을 갱신시켜준다.
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<vector<int>> miro;
vector<vector<int>> ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;

void solve() {
	queue<pair<int, pair<int,int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	ans[0][0] = 0;

	while (!q.empty()) {
		int cnt = q.front().first;
		int curx = q.front().second.first;
		int cury = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (miro[nx][ny] == 1&&ans[nx][ny]>cnt) {
					ans[nx][ny] = cnt;
					q.push(make_pair(cnt, make_pair(nx, ny)));
				}
				else if(miro[nx][ny] == 0 && ans[nx][ny] > cnt+1){
					ans[nx][ny] = cnt+1;
					q.push(make_pair(cnt+1, make_pair(nx, ny)));
				}
			}
		}
	}

	cout << ans[n - 1][n - 1];
}
int main() {
	cin >> n;
	miro.assign(n, vector<int>(n, 0));
	ans.assign(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			miro[i][j] = s[j] - '0';
		}
	}

	solve();
}
