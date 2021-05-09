#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<int> save;
vector<bool> check;
map<string,int> M;

bool str_check(string s) {
	if (M[s] == 0) {
		M[s] = 1;
		return true;
	}
	else return false;
}
void back(int idx,int cnt) {
	if (cnt == m) {
		string t = "";
		for (int i = 0; i < m; i++) t += (save[i]+'0');

		if (str_check(t)) {
			for (int i = 0; i < m; i++) cout << save[i] << ' ';
		}
		else return;

		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			save.push_back(num[i]);
			back(i,cnt + 1);
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
	
	back(0,0);

}
/*
	백준 15664번 N과 M (10)
*/
