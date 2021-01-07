#include <iostream>
#include <vector>
using namespace std;

int n, a, b, c, d;
int num[11];
bool check[11];
vector<char> kiho;
vector<int> v;
int m1 = 1000000001;
int m2 = -1000000001;


void back(int cnt, int ref) {
	if (cnt == ref) {
		int ans = num[0];
		for (int i = 0; i < ref; i++) {
			if (kiho[v[i]] == '+') { ans = ans + num[i + 1]; }
			else if (kiho[v[i]] == '-') { ans = ans - num[i + 1]; }
			else if (kiho[v[i]] == '*') { ans = ans * num[i + 1]; }
			else if (kiho[v[i]] == '/') { ans = ans / num[i + 1]; }
		}
		if (m1 > ans) m1 = ans;
		if (m2 < ans) m2 = ans;
		return;
	}

	for (int i = 0; i < ref; i++) {
		if (check[i] == false) {
			check[i] = true;
			v.push_back(i);
			back(cnt + 1, ref);
			v.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> a >> b >> c >> d;

	int test = a + b + c + d;

	for (int i = 0; i < test; i++) {
		if (a != 0) { kiho.push_back('+'); a--; }
		else if (b != 0) { kiho.push_back('-'); b--; }
		else if (c != 0) { kiho.push_back('*'); c--; }
		else if (d != 0) { kiho.push_back('/'); d--; }
	}
	back(0, test);
	cout << m2 << '\n' << m1;
	return 0;
}
/*
	백준 14888번 연산자 끼워넣기
*/
