#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> plus;
	priority_queue<int> minus;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) minus.push(x);
		else if(x > 0)plus.push(-x);

		if (x == 0) {
			if (plus.size() == 0 && minus.size() != 0) {
				cout << minus.top() << '\n';
				minus.pop();
			}
			else if (minus.size() == 0 && plus.size() != 0) {
				cout << -1 * plus.top() << '\n';
				plus.pop();
			}
			else if (minus.size() == 0 && plus.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				if (plus.top() <= minus.top()) {
					cout << minus.top() << '\n';
					minus.pop();
				}
				else {
					cout << -1 * plus.top() << '\n';
					plus.pop();
				}
			}
		}
	}

}

/*
	백준 11286번 절댓값 힙
*/
