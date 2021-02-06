#include <iostream>
#include <string>
using namespace std;
int lcs[1001][1001];
string a, b;

int main() {
	cin >> a >> b;
	int la = a.size();
	int lb = b.size();
	
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i - 1] == b[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				if (lcs[i][j - 1] < lcs[i - 1][j]) {
					lcs[i][j] = lcs[i - 1][j];
				}
				else {
					lcs[i][j] = lcs[i][j - 1];
				}
			}
		}
	}

	cout << lcs[la][lb];
	return 0;
}
/*
    백준 9251번 LCS
*/
