#include <iostream>
#include <map>
using namespace std;

int r, c;
int MAX = 0;
int tot = 0;
char alpha[20][20];
bool check[20][20];
map<char, int> m;
int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

void back(int x,int y) {
	tot++;
	if (tot > MAX) MAX = tot;
	m[alpha[x][y]]++;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + movex[i];
		int ny = y + movey[i];

		if (nx >= 0 && ny >= 0 && nx < r && ny < c && check[nx][ny] == false && m[alpha[nx][ny]] == 0) {
			back(nx, ny);
		}
	}			
	tot--;
	m[alpha[x][y]]--;
	check[x][y] = false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) alpha[i][j] = s[j];
	}
	back(0, 0);

	cout << MAX;

}
/*
	백준 1987번 알파벳
*/
