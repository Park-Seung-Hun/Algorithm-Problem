#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> input;
vector<string> ans;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string text;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> text;
		input.push_back(text);
	}

	for (int i = 0; i < m; i++) {
		cin >> text;
		input.push_back(text);
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < n + m; i++) {
		if (i < n + m - 1) {
			if (input[i] == input[i + 1]) {
				ans.push_back(input[i]);
			}
		}
	}

	sort(ans.begin(), ans.end());


	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
/*
    백준 1764번 듣보잡
*/
