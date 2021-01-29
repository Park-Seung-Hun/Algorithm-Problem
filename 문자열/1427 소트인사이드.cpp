#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> num;
string text;

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> text;
	for (int i = 0; i < text.size(); i++) {
		num.push_back(text[i]);
	}

	sort(num.begin(), num.end());

	for (int i = num.size() - 1; i >= 0; i--) {
		cout << num[i];
	}
}
/*
    백준 1427번 소트인사이드
*/
