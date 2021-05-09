#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int H, W;
	
	cin >> H >> W;
	int box[500] = { -1 };
	int Max = 0;
	int Mt = 0;

	for (int i = 0; i < W; i++) {
		cin >> box[i];
	\
	}
	
	int sum = 0;
	int left, right;
	for (int i = 1; i < W-1; i++) {
		
			left = right = box[i];

			for (int j = 0; j < i; j++) left = max(left, box[j]);
			for (int j = i + 1; j < W; j++)right = max(right, box[j]);

			sum += (min(right,left)-box[i]);
		
	}
	cout << sum;
	return 0;
}
/*
    백준 14719번 빗물
*/
