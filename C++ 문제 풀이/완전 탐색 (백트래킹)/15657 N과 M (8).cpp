#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<int> save;

void back(int idx,int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << save[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		if (i >= idx) {
			save.push_back(num[i]);
			back(i, cnt + 1);
			save.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	num.resize(n);

	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num.begin(), num.end());
	
	back(0,0);

}
/*
	백준 15657번 N과 M (8)
*/
