#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000000

vector<int> num;
vector<bool> check;
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	cin >> n;
	check.assign(n + 1, false);
	if (n > 1) {
		check[0] = true;
		check[1] = true;
		
		for (long long i = 2; i <= n; i++) {
			if (check[i] == false) {
				num.push_back(i);

				for (long long j = i * i; j <= n; j += i) check[j] = true;
			}
		}

		int start = 0;
		int end = 0;
		int sum = num[start];
		while (start<num.size()&&start<=end) {

			if (sum <= n) {
				if (sum == n) ans++;
				end++;
				if (end >= num.size()) break;
				sum += num[end];
			}
			else if (sum > n) {
				sum -= num[start];
				start++;
				if (start > end) {
					end = start;
					if (start < num.size()) sum = num[start];
				}
			}
		}

	}

	cout << ans;
}

/*
	백준 1644번 소수의 연속합
*/
