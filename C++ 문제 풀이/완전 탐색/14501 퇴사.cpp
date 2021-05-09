#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, MAX, ans;
vector<int> t;
vector<int> p;

void back(int day) {
	if (day > n) return;
	
	if (day == n) {
		if (ans > MAX) MAX = ans;
		return;
	}

	ans += p[day];
	back(day + t[day]);
	ans -= p[day];
	back(day + 1);
}

int main() {
	cin >> n;
	t.resize(n);
	p.resize(n);

	for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
	
	back(0);
	cout << MAX;
}
/*
	백준 14501번 퇴사
*/
