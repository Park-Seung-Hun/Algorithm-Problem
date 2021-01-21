#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string basic;
	int check = 0;
	while (true) {
		string ref;
		cin >> ref;
		check++;
		
		if (check == 1) basic = ref;
		else {
			string ans = basic;
			string name = "";
			string add = "";
			int size = ref.length();
			
			for (int i = 0; i <size; i++) {
				if (ref[i] >= 'a' && ref[i] <= 'z')name += ref[i];
				else if(ref[i] >= 'A' && ref[i] <= 'Z') name += ref[i];
				else {
					if (ref[i] == '[') add += ']';
					else if (ref[i] == ']') add += '[';
					else if(ref[i]!=','&&ref[i]!=';') add += ref[i];
				}
			}
			cout << basic;
			for (int i = add.length() - 1; i >= 0; i--) cout << add[i];
			cout << ' ' << name << ";\n";
			
		}
		if (ref[ref.length() - 1] == ';') break;
		
		
	}
}

/*
	백준 3568번 iSharp
*/
