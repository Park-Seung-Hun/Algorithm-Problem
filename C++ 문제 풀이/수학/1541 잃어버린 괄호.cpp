#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string text;
	int ans = 0;
	int num = 0;
	getline(cin, text);

	for (int i = 0; i <= text.size(); i++) {

		if (text[i] >= '0' && text[i] <= '9') {
			num = num * 10 + (text[i] - '0');
		}
		else if (text[i] == '+' || text[i] == NULL) {
			ans += num;
			num = 0;
		}
		else if (text[i] == '-') {
			ans += num;
			num = 0;
			for (int j = i + 1; j <= text.size(); j++) {
				if (text[j] >= '0' && text[j] <= '9') {
					num = num * 10 + (text[j] - '0');
				}
				else if (text[j] == '+' || text[j] == '-' || text[j] == NULL) {
					ans -= num;
					num = 0;
				}
			}
			break;
		}
	}

	cout << ans;
}
/*
	백준 1541번 잃어버린 괄호
*/
