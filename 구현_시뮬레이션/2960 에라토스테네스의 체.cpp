#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool c[1000];

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	int cnt = 0;
	bool check = false;
	int ans = 0;

	c[1]=true;
	for (int i = 2; i <= n; i++) {
		if (c[i] == false) {
			for (int j = 1; j <= n; j ++) {
				if (j * i > n) break;
			
				if (c[j * i] == false) {
					c[j * i] = true;
					cnt++;
					if (cnt == m) {
						ans = j * i;
						check = true;
						break;
					}
				}
				
			}
		}
		if (check == true) break;
	}

	cout << ans << '\n';
	return 0;
}

/*
    백준 2960번 에라토스테네스의 체
*/
