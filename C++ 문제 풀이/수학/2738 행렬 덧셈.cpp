#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>a;
vector<vector<int>>b;

int main() {
	cin >> n >> m;
	a.assign(n, vector<int>(m,0));
	b.assign(n, vector<int>(m,0));
	
	for (int k = 0; k < 2; k++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(k==0)cin >> a[i][j];
				else cin >> b[i][j];
			}
		}
	}
		
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< a[i][j] + b[i][j]<<' ';
		}
		cout << '\n';
	}

}
/*
	백준 2738번 행렬 덧셈
*/
