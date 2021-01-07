#include <iostream>
#include <vector>
using namespace std;
int n;
vector<bool> check;
vector<int> num;

void back(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			num.push_back(i);
			back(cnt + 1);
			check[i] = false;
			num.pop_back();
		}
	}
	return;
}
int main() {
	cin >> n;
	check.resize(n+1);

	back(0);
}

/*
	백준 10974번 모든 순열
*/
