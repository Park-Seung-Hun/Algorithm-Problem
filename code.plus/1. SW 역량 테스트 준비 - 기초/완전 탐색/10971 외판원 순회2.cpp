#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MIN = 987654321;
int n;
int cost[10][10];
bool check[10];
vector<int> city;

void back(int cnt) {
	if (cnt == n) {
		int ans = 0;
		
		for (int i = 0; i < n-1; i++) {
			if (cost[city[i]][city[i + 1]] == 0) return;
			ans += cost[city[i]][city[i + 1]];
		}

		if (cost[city[n - 1]][city[0]] == 0) return;
		ans += cost[city[n - 1]][city[0]];

		if (MIN > ans) MIN = ans;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			city.push_back(i);

			back(cnt + 1);

			check[i] = false;
			city.pop_back();
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	
	back(0);

	cout << MIN;
}

/*
	백준 10971번 외판원 순회2
*/
