#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num;
vector<bool> check;

void back(int idx,int cnt) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			num.push_back(i);
			back(i,cnt + 1);
			num.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	check.resize(n + 1);
	back(1,0);

}
/*
	백준 15650번 N과 M (2)
*/
