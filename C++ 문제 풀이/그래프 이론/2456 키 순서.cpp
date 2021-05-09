/*
	백준 2456번 키 순서
	https://www.acmicpc.net/problem/2458

	조건 1. 유향그래프
	조건 2. 학생들(n)의 키를 비교
	요구하는 답: 자기 키 순서를 아는 학생의 숫자 구하기

	풀이:
	플로이드 와샬 알고리즘을 사용하여 모든 학생들 사이의 키를 알고있는 사람의 수를 구한다.
	ex) student[i][j]는 i에서부터 시작해서 j의 키를 알고있는 사람의 수
	student[i][j]가 INF가 아닐때 즉, 연결되어 있는 경우 cnt[i],cnt[j]의 값을 1씩 증가시킨다.
	자신을 제외한 모든 사람들이 자신의 키 순서를 알 때 (cnt[i]==n-1)의 경우를 세준다.
*/

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<int>> student;
vector<int> cnt;
int n, m, ans;

void solve() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (student[i][k] == INF || student[k][j] == INF) continue;

				if (student[i][j] > student[i][k] + student[k][j])
					student[i][j] = student[i][k] + student[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (student[i][j] == INF || i == j) continue;
			cnt[i]++; cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << student[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	cin >> n >> m;
	student.assign(n + 1, vector<int>(n + 1, INF));
	cnt.assign(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int s1, s2;
		cin >> s1 >> s2;
		student[s1][s2] = 1;
	}

	solve();

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == n - 1) ans++;
	}
	cout << ans << '\n';
}
