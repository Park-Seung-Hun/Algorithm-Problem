#include <iostream>
#include <string>
using namespace std;
int lcs[101][101][101];
string a, b, c;

int main() {
	cin >> a >> b>>c;
	int la = a.size();
	int lb = b.size();
	int lc = c.size();

	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			for (int k = 1; k <= lc; k++) {
				if (a[i - 1] == b[j - 1]&&a[i-1]==c[k-1]) {
					lcs[i][j][k] = lcs[i - 1][j - 1][k-1] + 1;
				}

				else {
					if (lcs[i - 1][j][k] < lcs[i][j - 1][k]) {
						if (lcs[i][j - 1][k] < lcs[i][j][k - 1]) {
							lcs[i][j][k] = lcs[i][j][k-1];
						}
						else {
							lcs[i][j][k] = lcs[i][j - 1][k];
						}
					}
					else {
						if (lcs[i-1][j][k] < lcs[i][j][k - 1]) {
							lcs[i][j][k] = lcs[i][j][k - 1];
						}
						else {
							lcs[i][j][k] = lcs[i - 1][j][k];
						}
					}
				}
			}
		}
	}

	cout << lcs[la][lb][lc];
	return 0;
}

/*
    백준 1958번 LCS3
*/
