#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t;

bool check(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n, m;
		queue<pair<int, int> > num;
		vector<int> tmp;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
		
			if(m!=i)num.push(make_pair(x,0));
			else num.push(make_pair(x, 1));
		
			tmp.push_back(x);
		}
		sort(tmp.begin(), tmp.end(), check);

		int size = 0;
		int cnt = 0;
		while (true) {
			int ref = tmp[size];
			if (ref == num.front().first) {
				cnt++;
				if (num.front().second == 1) break;
				else size++;
				num.pop();
			}
			else {
				num.push(make_pair(num.front().first, num.front().second));

				num.pop();
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}
/*
    백준 1966번 프린터 큐
*/
