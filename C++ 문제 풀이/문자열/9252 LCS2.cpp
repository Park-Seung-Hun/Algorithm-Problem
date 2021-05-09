#include <iostream>
#include <string>
using namespace std;
int lcs[1001][1001];
string text[1001][1001];
string a, b;

int main() {
	cin >> a >> b;
	int la = a.size();
	int lb = b.size();
	int len = 0;

	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i - 1] == b[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				text[i][j] += text[i - 1][j - 1] + a[i - 1];
			}
			else {
				if (lcs[i - 1][j] < lcs[i][j - 1]) {
					lcs[i][j] = lcs[i][j - 1];
					text[i][j] = text[i][j - 1];
				}
				else {
					lcs[i][j] = lcs[i - 1][j];
					text[i][j] = text[i-1][j];
				}
			}

		}
	}

	if (lcs[la][lb] != 0) cout << lcs[la][lb] << '\n' << text[la][lb] << '\n';
	else cout << 0;
	return 0;
}
/*
    백준 9252번 LCS2
*/
