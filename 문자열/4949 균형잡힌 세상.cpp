#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {	
  ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string text="";
		stack<char> check;
		bool cc = false; 

		getline(cin, text);
		if (text == ".") break;

		for (int i = 0; i < text.size(); i++) {
			if (text[i] == '('  || text[i] == '[') check.push(text[i]);
			else if (text[i] == ')') {

				if (!check.empty()&&check.top() == '(') check.pop();
				else {
					cc = true;
					break;
				}

			}
			else if (text[i] == ']') {
				
				if (!check.empty()&&check.top() == '[') check.pop();
				else {
					cc = true;
					break;
				}

			}
		}


		if (cc == false&&check.empty()) cout << "yes\n";
		else cout << "no\n";

		
	}

	return 0;
}
/*
    백준 4949번 균형잡힌 세상
*/
