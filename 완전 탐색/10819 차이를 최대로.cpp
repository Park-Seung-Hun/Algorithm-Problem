#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, MAX;
vector<bool> check;
vector<int> num;
vector<int> ans;

void back(int ref, int cnt) {
	if (ref == cnt) {
		int tot = 0;
		for (int i = 0; i < n - 1; i++) tot += abs(ans[i] - ans[i + 1]);

		if (MAX < tot) MAX = tot;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {

			check[i] = true;
			ans.push_back(num[i]);

			back(ref, cnt + 1);

			ans.pop_back();
			check[i] = false;

		}
	}
}

int main() {

	cin >> n;
	check.resize(n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}

	back(n, 0);
	cout << MAX;
}

/*
	백준 10819번 차이를 최대로
*/
