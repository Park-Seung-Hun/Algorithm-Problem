/*
	입력받은 노드들을 이용해 간선을 만들고 (edges)
	간선의 길이+1이 노드의 개수와 같거나 간선이 0인경우 => Tree
	아닌 경우 => Tree가 아니다.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int a, b, idx = 1;
vector<pair<int, int>> edge;
set<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> a >> b;

		if (a == -1 && b == -1) break;
		if (a == 0 && b == 0) {
			/*
				트리인지 아닌지 판단
			*/
			if (edge.size() + 1 == s.size() || edge.size() == 0) {
				cout << "Case " << idx << " is a tree.\n";
			}
			else {
				cout << "Case " << idx << " is not a tree.\n";
			}
			idx++;
			s.clear();
			edge.clear();
		}
		else {
			// 노드들의 집합 s
			s.insert(a);
			s.insert(b);

			// 간선
			edge.push_back({ a,b });
		}
	}
}
