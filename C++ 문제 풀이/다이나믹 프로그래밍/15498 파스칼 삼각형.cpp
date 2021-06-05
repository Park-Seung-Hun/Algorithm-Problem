#include <iostream>
using namespace std;
int arr[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 파스칼 삼각형 만들기
	arr[0][0] = arr[1][0] = arr[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		arr[i][0] = arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}



	int r, c, w;
	cin >> r >> c >> w;
	int ans = 0;
	for (int i = 0; i < w; i++) {
		for (int j = c-1; j < i+c; j++) {
			ans += arr[r - 1 + i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}
