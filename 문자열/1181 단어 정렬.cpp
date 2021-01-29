#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> tt;
int n;

bool compare(string a, string b) {
	if (a.size() == b.size()) return a < b; // 사전순 
	return a.size() < b.size(); // 길이가 짧은순
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		tt.push_back(t);
	}

	sort(tt.begin(), tt.end(), compare);

	for (int i = 0; i < tt.size(); i++) {
		if (i < tt.size() - 1 && tt[i].compare(tt[i + 1]) == 0) continue;
		else cout << tt[i] << '\n';
	}
}
/*
    백준 1181번 단어 정렬
*/
