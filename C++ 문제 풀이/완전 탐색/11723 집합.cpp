#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string text;
int m, x;
vector<int> num;
vector<int> one;
vector<int> zero;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	num.resize(21);
	one.resize(21);
	zero.resize(21);
	for (int i = 1; i <= 20; i++) {
		one[i] = 1;
		zero[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> text;

		if (text == "add") {
			cin >> x;
			num[x] = 1;
		}
		else if (text == "remove") {
			cin >> x;
			num[x] = 0;
		}
		else if (text == "check") {
			cin >> x;
			if (num[x] == 0) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if (text == "toggle") {
			cin >> x;
			if (num[x] == 0) num[x] = 1;
			else num[x] = 0;
		}
		else if (text == "all") {
			num = one;
		}
		else if (text == "empty") {
			num = zero;
		}
	}
}
/*
	백준 11723번 집합
*/
