#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num;

void back(int idx,int cnt) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (idx<=i) {
			num.push_back(i);
			back(i,cnt + 1);
			num.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	back(1,0);

}
/*
	백준 15652번 N과 M (4)
*/
