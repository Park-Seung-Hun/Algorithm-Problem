#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char s[10][10];
int num[10];

bool check(int idx) {
	int tot = 0;
	for (int i = idx; i >=0; i--) {
		tot += num[i];
		if (s[i][idx] == '+' && tot <= 0) return false;
		if (s[i][idx] == '-' && tot >= 0) return false;
		if (s[i][idx] == '0' && tot != 0) return false;
	}
	return true;
}
void back(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < cnt; i++) {
			cout << num[i]<<' ';
		}
		cout << '\n';
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		num[cnt] = i;
		if (check(cnt)) back(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> s[i][j];
	back(0);
}
/*
	백준 1248번 맞춰봐
*/
