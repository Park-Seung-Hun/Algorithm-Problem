#include <iostream>
#include <string>
using namespace std;
string text;

int c;
int sum,t;
int main() {
	cin >> t;
    
	for (int i = 0; i < t; i++) {
		cin >> text;
		int check[26] = { 0 };
        
		for (int j = 0; j < text.size(); j++) {
			int a=text[j]-97;
			if (check[a] == 0) check[a] = j + 1;
			else {
				if ((j + 1) - check[a] == 1) check[a] = j + 1;
				else { 
					c = 1; 
					break;
				}
			}
		}
		if (c == 0) sum++;
		c = 0;
	}
    
	cout << sum;
}
/*
    백준 1316번 그룹 단어 체커
*/
