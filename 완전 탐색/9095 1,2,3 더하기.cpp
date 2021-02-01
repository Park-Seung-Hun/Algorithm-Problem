#include <iostream>
using namespace std;

int test_case,num,ans;

int main() {
	cin >> test_case;
	int ans[100];
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;

	for (int i = 0; i < test_case; i++) {
		cin >> num;
		for (int j = 4; j <= num; j++) ans[j] = ans[j - 1] + ans[j - 2] + ans[j - 3];
		cout << ans[num] << '\n';
	}
	return 0;
}

/*
	백준 9095번 1,2,3 더하기
*/
