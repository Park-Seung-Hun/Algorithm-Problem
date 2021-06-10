/*
2078 무한 이진트리 (https://lastknight00.tistory.com/121)
Sol. 수학
a == 1 인 경우 (오른쪽으로만 이동) => right += b-1;
b == 1인 경우 (왼쪽으로만 이동) => left +=a-1;

a>b인 경우 left+=a/b, a%=b;
		right+=b/a,b%=a;
*/

#include <iostream>
#include <vector>
using namespace std;
int A, B,L,R;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	while (true) {
		if (A == 1) { R += B - 1; break; }
		else if (B == 1) { L += A - 1; break; }

		if (A > B) {
			L += A / B;
			A %= B;
		}
		else {
			R += B / A;
			B %= A;
		}
	}

	cout << L << ' ' << R;
	return 0;
}
