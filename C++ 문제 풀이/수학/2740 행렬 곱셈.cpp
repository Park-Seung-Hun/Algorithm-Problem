#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int a[100][100];
int b[100][100];
int c[100][100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> b[i][j];


		
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			c[i][j] = 0;
			for (int h = 0; h < m; h++)
				c[i][j] += (a[i][h] * b[h][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << c[i][j]<<' ';
		}
		cout << '\n';
	}

}
/*
	백준 2740번 행렬 곱셈
*/
