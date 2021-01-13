#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int MAX = -9876545321;
int MIN = 987654321;
vector<int> num;
int op[4];

void sol(int idx,int tot) {
	if (idx == n) {
		if (tot > MAX) MAX = tot;
		if (tot < MIN)MIN = tot;
		return;
	}
	int tmp = tot;
	if (op[0] != 0) {
		tot += num[idx];
		op[0]--;
		sol(idx + 1, tot);
		op[0]++;
		tot = tmp;

	}
	if (op[1] != 0) {
		tot -= num[idx];
		op[1]--;
		sol(idx + 1, tot);
		op[1]++;
		tot = tmp;
	}
	if (op[2] != 0) {
		tot *= num[idx];
		op[2]--;
		sol(idx + 1, tot);
		op[2]++;
		tot = tmp;
	}
	if (op[3] != 0) {
		if (tot < 0) {
			tot = abs(tot);
			tot = -(tot / num[idx]);
		}
		else {
			tot /= num[idx];
		}
		op[3]--;
		sol(idx + 1, tot);
		op[3]++;
		tot = tmp;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	sol(1, num[0]);
	cout << MAX << '\n' << MIN;


}
/*
	백준 15658번 연산자 끼워넣기 (2)
*/
