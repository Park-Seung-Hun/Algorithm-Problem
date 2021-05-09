#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int num = 0;
	int check = 0;
	int j = 0;
	cin >> num;

	for (int i = 1; i <= num; i++){
		
		if (i % 5 == 0) {
			j = i;
			while (1) {
				check++;
				j /= 5;
				if (j % 5 != 0) break;
			}
		}
	}
	cout << check;
}
/*
	백준 1676번 팩토리얼 0의 개수
*/
