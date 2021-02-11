
/*
	백준 1111번 IQ Test

*/

#include <iostream>
using namespace std;

int n,cnt;
int num[50];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	int a = 0;
	int b = 0;

	if (n > 2) {
		if (num[0] == num[1]) a = 0;
		else a = (num[2] - num[1]) / (num[1] - num[0]);
		b = num[1] - num[0] * a;
	
		bool flag = false;
		for (int i = 1; i < n; i++) {
			if ((num[i - 1] * a + b) != num[i]) { 
				flag = true; 
				break;
			}
		}

		if (flag) cout << "B\n";
		else cout << num[n - 1] * a + b;

	}
	else if(n==1){
		cout << "A\n";
	}
	else if (n == 2) {
		if (num[0] == num[1]) cout << num[0] << '\n';
		else cout << "A\n";
	}


	return 0;
}
