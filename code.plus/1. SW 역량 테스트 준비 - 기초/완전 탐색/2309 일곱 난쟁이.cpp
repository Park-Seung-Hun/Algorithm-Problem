#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int total;
vector<int> num;
vector<int> ans;
bool check[9];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	num.resize(9);
	
	for (int i = 0; i < 9; i++) { cin >> num[i]; total += num[i]; }
	
	bool flag = false;
	for (int i = 0; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			if (total - num[i] - num[j] == 100) {
				check[i] = check[j] = true;
				flag = true;
				break;
			}
		}
		if (flag == true) break;
	}

	for (int i = 0; i < 9; i++) if (check[i] == false) ans.push_back(num[i]);
	sort(ans.begin(),ans.end());
	for (int i = 0; i < 7; i++) cout << ans[i] << '\n';

}

/*
	백준 2309번 일곱 난쟁이
*/
