#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, ans;
vector<int> num;
vector<int> flag;

void back(int cnt) {

	if (cnt == n) {
		int tot = 0;
		bool check = false;
		
		for (int i = 0; i < n; i++) {
			if (flag[i] == 1) { 
				tot += num[i]; 
				check = true;
			}
		}
		if (check == true && tot == s) ans++;
		return;
	}

	flag[cnt] = 1;
	back(cnt + 1);
	flag[cnt] = 0;
	back(cnt + 1);

	return;
}
int main() {
	cin >> n >> s;
	
	num.resize(n);
	flag.resize(n);

	for (int i = 0; i < n; i++) cin >> num[i];
	back(0);
	cout << ans;

}
/*
	백준 1182번 부분수열의 합
*/
