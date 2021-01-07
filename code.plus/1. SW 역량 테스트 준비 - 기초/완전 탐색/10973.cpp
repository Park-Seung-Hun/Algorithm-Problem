#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> num;

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	
	if (prev_permutation(num.begin(), num.end()))
		for (int i = 0; i < n; i++)
			cout << num[i]<<' ';
	else cout << -1;
}

/*
	백준 10973번 이전 순열 ( STL 사용 버전 )
*/
