#include <iostream>
#include <deque>
#include <string>
using namespace std;

int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	
	for (int test = 0; test < t; test++) {

		string p, num; 
		int n;
		deque<int> q;
		string ref = "";
		bool flag = false;
		int reverse = 1;
		
		cin >> p >> n >> num;
		
		for (int i = 0; i < num.size(); i++) {
			if (num[i] == ',' || num[i] == '[' || num[i] == ']') {
				if (ref == "") continue;
				int copy = stoi(ref);
				q.push_back(copy);
				ref = "";
			}
			else ref += num[i];
			
		}
		
		for (int i = 0; i < p.size(); i++) {

			if (p[i] == 'D') { 
				if (q.size() == 0) {
					flag = true;
					cout << "error\n";
					break;
				}

				if (reverse == 1) q.pop_front();
				else q.pop_back();
			}
			else if (p[i] == 'R') {
				if (reverse == 1) reverse = -1;
				else reverse = 1;
			}
		}

		if (!flag) {
			int size = q.size();
			cout << '[';
			if (reverse == 1) {
				for (int i = 0; i < size; i++) {
					cout << q.front();
					q.pop_front();
					if (i != size - 1) cout << ',';
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << q.back();
					q.pop_back();
					if (i != size - 1) cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}

/*
	백준 5430번 AC
*/
