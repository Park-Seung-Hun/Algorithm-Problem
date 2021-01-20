#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> num;
int check[8001];
int n;
double sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

    int max = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
		sum += x;

		check[x + 4000]++;
		if (max < check[x + 4000]) max = check[x + 4000];
	}
	vector<int> tt;

	for (int i = 0; i <= 8000; i++) {
		if (max == check[i]) tt.push_back(i - 4000);
	}
	sort(num.begin(), num.end());
	sort(tt.begin(), tt.end());
	
	cout << (int)round(sum / n) << '\n';
	cout << num[n / 2] << '\n';
	if (tt.size() > 1)cout << tt[1] << '\n';
	else cout << tt[0] << '\n';
	cout << num[n - 1] - num[0];
}

/*
    백준 2108번 통계학
*/
