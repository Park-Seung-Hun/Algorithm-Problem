#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector<bool> prime;
vector<bool> visit;
int A, B;

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(A, 0));
	visit[A] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == B) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string num = to_string(cur);
				num[i] = (j + '0');
				int next = stoi(num);

				if (prime[next] == false && visit[next] == false) {
					if (next >= 1000 && next <= 9999) {
						visit[next] = true;
						q.push(make_pair(next, cnt + 1));
					}
				}
			}
		}
	}
	cout << "Impossible\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime.resize(10000);
	prime[0] = prime[1] = true;
	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 9999; j += i) prime[j] = true;
		}		
	}


	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		visit.assign(10000, false);
		cin >> A >> B;
		bfs();

	}
}
/*
	백준 1963번 소수 경로
*/
