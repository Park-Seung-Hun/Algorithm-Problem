#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int init = 100;
int n, m;
bool check[10];

bool sol(int x) {

	string s = to_string(x);
	for (int i = 0; i < s.length(); i++) {
		if (check[s[i] - '0']) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		check[x] = true;
	}

	int MIN = abs(n - 100);
	for (int i = 0; i <= 1000001; i++) {
		if (sol(i)) {
			int tmp = abs(n - i) + to_string(i).length();
			MIN = min(MIN, tmp);
		}
	}

	cout << MIN << '\n';
}
/*
	백준 1107번 리모콘
*/
