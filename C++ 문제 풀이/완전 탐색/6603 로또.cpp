#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> num;
vector<int> save;
vector<bool> check;

void  back(int idx,int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) cout << num[save[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < k; i++) {
		if (check[i] == false) {
			check[i] = true;
			save.push_back(i);
			
			back(i, cnt + 1);

			save.pop_back();
			check[i] = false;
		}
	}
	return;
}
int main() {
	
	while (true) {
		cin >> k;
		if (k == 0) break;
		
		num.resize(k);
		check.resize(k);

		for (int i = 0; i < k; i++)
			cin >> num[i];

		back(0, 0);
		cout << '\n';
	}
}

/*
	백준 6603번 로또
*/
