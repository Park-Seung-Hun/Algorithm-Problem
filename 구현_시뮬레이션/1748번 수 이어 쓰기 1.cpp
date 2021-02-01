#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int len = s.length();

	if (len == 1) cout << s << '\n';
	else {
		long long answer = 0;

		for (long long i = 1; i < len; i++) {
			answer += i * (9 * pow(10, i - 1));
		}
		answer += len * (stoi(s) - pow(10, len - 1) + 1);
		cout << answer << '\n';
	}
}

/*
	백준 1748번 수 이어 쓰기 1
*/
