#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<pair<int, char>> num;
int alpha[26];
bool cmp(int a, int b) {
	if (a > b) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int Pow = 1;
		
		for (int j = s.length()-1; j >=0; j--) {
			alpha[s[j] - 'A'] += Pow;
			Pow *= 10;
		}	
	}
	sort(alpha,alpha+26,cmp);
	int ref = 9;
	int tot = 0;
	for (int i = 0; i < 26;i++) {
		if (alpha[i] == 0) break;
		tot += (alpha[i] * ref);
		ref--;
	}
	cout << tot << '\n';

}
/*
	백준 1339번 단어 수학
*/
