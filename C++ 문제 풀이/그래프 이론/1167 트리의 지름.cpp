#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v,Max,Maxnode;
vector<vector<pair<int,int>>> edge;
vector<bool> check;

void dfs(int node, int dist) {
	if (check[node]) return;
	
	if (Max < dist) {
		Max = dist;
		Maxnode = node;
	}
	check[node] = true; 

	for (int i = 0; i < edge[node].size(); i++){
		dfs(edge[node][i].first, edge[node][i].second + dist);
	}
}
int main() {
	cin >> v;
	edge.resize(v + 1);
	

	for (int i = 0; i < v; i++) {
		int x,y,d;
		cin >> x;

		while (true) {
			cin >> y;
			if (y != -1) {
				cin >> d;
				edge[x].push_back(make_pair(y, d));
				edge[y].push_back(make_pair(x, d));
			}
			else break;
		}
	}
	check.assign(v + 1, false);
	dfs(1, 0);
	check.assign(v + 1, false);
	Max = 0;
	dfs(Maxnode, 0);

	cout << Max;
}
