#include <iostream>
#include <vector>
using namespace std;

int ans = 987654321;
int people[20][20];
bool check[20];
int n;

int cal(vector<int> num) {
	int size = num.size();
	int ref = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j) {
				ref += people[num[i]][num[j]];
			}
		}
	}
	return ref;
}
void sol(int cnt,int idx) {
	if (cnt == n/2) {

		vector<int> start;
		vector<int> link;
	
		for (int i = 0; i < n; i++) {
			if (check[i] == true) start.push_back(i);
			else link.push_back(i);
		}

		int ans_start = cal(start);
		int ans_link = cal(link);
		if (ans > abs(ans_start - ans_link)) ans = abs(ans_start - ans_link);
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			sol(cnt + 1,i);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> people[i][j];
	sol(0,0);

	cout << ans << '\n';
}

/*
	백준 15661번 링크와 스타트
*/
