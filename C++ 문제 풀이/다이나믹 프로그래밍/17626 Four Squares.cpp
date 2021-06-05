/*
	풀이 : i를 1~n 까지의 숫자까지 올라가면서 찾는다.
	1. i가 루트 i인 경우
		- arr[i] = 1
	2. i가 루트 i가 아닌 경우
		- 루트i부터 시작해서 1까지 가면서 최소한의 값으로 만들어지는 값을 찾는다.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	arr.assign(n + 1, 99999);
	for (int i = 1; i <= n; i++) {

		if ((int)sqrt(i) * sqrt(i) == i) { // 제곱근인 경우
			arr[i] = 1;
			continue;
		}

		for (int j = sqrt(i); j >= 1; j--) {
			arr[i] = min(arr[i],arr[i - j * j] + 1); // 찾으려는 숫자 i에서 j의 제곱을 뺀만큼 +1 한 값
		}

	}
	cout << arr[n];
	return 0;
}
