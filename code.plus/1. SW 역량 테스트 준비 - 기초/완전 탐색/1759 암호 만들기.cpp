#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c, ja, mo;
vector<char> w;
vector<bool> check;
vector<int> save;

void back(int idx,int cnt) {
	if (cnt == l&&ja>=2&&mo>=1) {
		for (int i = 0; i < l; i++) cout << w[save[i]];
		cout << '\n';
		return;
	}

	for (int i = idx ; i < c; i++) {
		if (check[i] == false) {
			if (w[i] == 'a' || w[i] == 'e' || w[i] == 'i' || w[i] == 'o' || w[i] == 'u') mo++;
			else ja++;
			check[i] = true;
			save.push_back(i);
			
			back(i,cnt + 1);

			check[i] = false;
			save.pop_back();
			if (w[i] == 'a' || w[i] == 'e' || w[i] == 'i' || w[i] == 'o' || w[i] == 'u') mo--;
			else ja--;

		}
	}
	return;
}

int main() {
	cin >> l >> c;
	
	w.resize(c);
	check.resize(c);

	for (int i = 0; i < c; i++) cin >> w[i];
	sort(w.begin(), w.end());


	back(0,0);
}
/*
	백준 1759번 암호 만들기
*/
