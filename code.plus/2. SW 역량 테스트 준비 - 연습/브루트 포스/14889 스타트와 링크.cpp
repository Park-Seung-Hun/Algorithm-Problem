#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int MIN = 987654321;
vector<vector<int> > num;
vector<bool> check;

void team(int idx,int people) {
	if (people == n/2) {
		vector<int> start;
		vector<int> link;

		for (int i = 0; i < n;i++ ) {
			if (check[i] == true) start.push_back(i);
			else link.push_back(i);
		}

		int tot_start = 0;
		int tot_link = 0;
		for (int i = 0; i < n/2; i++) {
			for (int j = 0; j < n/2; j++) {
				if (i != j) {
					
					tot_start += num[start[i]][start[j]];
					tot_link += num[link[i]][link[j]];
				}
			}
		}

		int ans = abs(tot_start - tot_link);
	
		if (MIN > ans) MIN = ans;
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			team(i,people + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	num.assign(n, vector<int>(n, 0));
	check.assign(n,false);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> num[i][j];

	team(0,0);
	cout << MIN;
}
/*
	백준 14889번 스타트와 링크
*/
