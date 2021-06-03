/*
http://blog.naver.com/PostView.nhn?blogId=jinhan814&logNo=222250306294

세그먼트 트리의 노드 인덱스를 생각하면서 x번 정점의 왼쪽, 오른쪽 자식이 2 * x, 2 * x + 1임을 이용하면 풀 수 있는 문제입니다.
이진 트리의 성질을 이용하면서 풀이도 깔끔해서 좋네요. 바로 트리 문제집에 추가 갑니다.
[출처] [BOJ] 11203번 - Numbers On a Tree|작성자 박진한
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
	fastio;
	int n, x = 1; string s; cin >> n >> s;
	for (auto i : s) x = x << 1 | (i == 'R');
	cout << (1 << n + 1) - x << '\n';
}


/*
내 풀이 -> 트리를 구현한 다음 명령에 따라 찾기
length_error가 자꾸 뜨네..
s가 입력되지 않는 경우 처리를 하는 방법 찾기!
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h; string s;

	cin >> h;

	int rootNum = pow(2, h + 1) - 1;
	node.resize(rootNum + 1);

	int idx = rootNum;
	for (int i = rootNum-1; i >= 1; i--) {
		node[idx].push_back(i);
		if (node[idx].size() == 2) {
			idx--;
		}
	}
  cin>> s;
	int ans = rootNum;
	for (auto i : s) {
		if (i == 'L') {
			ans = node[rootNum][0];
			rootNum = ans;
		}
		else {
			ans = node[rootNum][1];
			rootNum = ans;
		}
	}
	cout << ans << '\n';

	return 0;
}
