#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<bool> check;
vector<int> save;

void back(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << save[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			save.push_back(num[i]);
			back(cnt + 1);
			save.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	num.resize(n);
	check.resize(n);

	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num.begin(), num.end());
	
	back(0);

}
/*
	백준 15654번 N과 M (5)
*/
