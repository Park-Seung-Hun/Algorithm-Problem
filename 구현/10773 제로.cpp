#include<iostream>
#include<stack>
using namespace std;

int n;
long long sum;
stack<long long> ss;

int main() {
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (x == 0 && !ss.empty()) ss.pop();
		else ss.push(x);
	}

	while (!ss.empty()) {
		sum += ss.top();
		ss.pop();
	}

	cout << sum;
	return 0;
}
/*
    백준 10773번 제로
*/
