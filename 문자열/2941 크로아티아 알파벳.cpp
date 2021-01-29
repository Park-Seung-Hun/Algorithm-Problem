#include <iostream>
#include <string>
using namespace std;

string tt;
int check, sum;

int main() {	
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> tt;
	int size = tt.size();

	while (true) {
		if (check == tt.size()) break;

		if (( tt[check] == 's' || tt[check] == 'z') && check < tt.size() - 1) {
			if (tt[check + 1] == '=') {
				check+=2;
				sum++;
				continue;
			}
		}
		else if ((tt[check] == 'l' || tt[check] == 'n') && check < tt.size() - 1) {
			if (tt[check + 1] == 'j') {
				check+=2;
				sum++;
				continue;
			}
		}
		else if (tt[check] == 'd') {
			if (check < tt.size() - 2) {
				if (tt[check + 1] == 'z' && tt[check + 2] == '=') {
					check += 3;
					sum++;
					continue;
				}
				else if (tt[check + 1] == '-') {
					check += 2;
					sum++;
					continue;
				}
			}
			else if (check == tt.size() - 2) {
				if (tt[check + 1] == '-') {
					check += 2;
					sum++;
					continue;
				}
			}
		}
		else if (tt[check] == 'c' && check < tt.size() - 1) {
			if (tt[check + 1] == '='|| tt[check + 1] == '-') {
				check += 2;
				sum++;
				continue;
			}
		}
		sum++;
		check++;
	}

	cout << sum;
}
/*
    백준 2941번 크로아티아 알파벳
*/
