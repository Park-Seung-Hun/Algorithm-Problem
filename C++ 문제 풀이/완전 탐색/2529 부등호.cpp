#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> num;
vector<char> op;
vector<bool> check;
string MAX = "0";
string MIN = "987654322";

void sol(int idx) {
	if (idx == n) {
		string s = "";
		for (int i = 0; i <= idx; i++) s += num[i]+'0';
		
		if (MAX < s) MAX = s;
		if (MIN > s) MIN = s;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (op[idx] == '<') {
			if (check[i] == false && num[idx] < i) {
				
				check[i] = true;
				num.push_back(i);
				sol(idx + 1);
				num.pop_back();
				check[i] = false;
			}
		}
		else {
			if (check[i] == false && num[idx] > i) {
				check[i] = true;
				num.push_back(i);
				sol(idx + 1);
				num.pop_back();
				check[i] = false;
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	op.resize(n);
	check.resize(10);
	for (int i = 0; i < n; i++) cin >> op[i];

	for (int i = 0; i <= 9; i++) {
		check[i] = true;
		num.push_back(i);
		sol(0);
		num.pop_back();
		check[i] = false;
	}

	cout << MAX << '\n' << MIN;
}
/*
	백준 2529번 부등호
*/
