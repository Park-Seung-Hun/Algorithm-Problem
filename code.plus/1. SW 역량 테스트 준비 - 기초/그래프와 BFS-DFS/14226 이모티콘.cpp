#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int emo;
queue<pair<int, pair<int, int> > > q;
bool check[1001][1001];

void bfs() {
	q.push(make_pair(1,make_pair(0, 0)));
	check[1][0] = true;

	while (!q.empty()) {
		int e = q.front().first;
		int copy = q.front().second.first;
		int s = q.front().second.second;
		q.pop();

		if (e == emo) {
			cout << s;
			return;
		}

		if (e > 0 && copy <= 1000) {

			//1. 화면의 이모티콘 복사
			if (check[e][e] == false) {
				check[e][e] = true;
				q.push(make_pair(e, make_pair(e, s + 1)));
			}

			//3. 화면의 이모티콘 삭제
			if (check[e - 1][copy] == false) {
				check[e - 1][copy] = true;
				q.push(make_pair(e - 1, make_pair(copy, s + 1)));
			}
		}

		if (copy > 0 && e + copy <= 1000) {
			//2. 클립보드에 있는 모든 이모티콘 붙여넣기
			if (check[e + copy][copy] == false) {
				check[e + copy][copy] = true;
				q.push(make_pair(e + copy, make_pair(copy, s + 1)));
			}
		}
	}
}
	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> emo;
	bfs();

}
/*
	백준 14226번 이모티콘
*/
