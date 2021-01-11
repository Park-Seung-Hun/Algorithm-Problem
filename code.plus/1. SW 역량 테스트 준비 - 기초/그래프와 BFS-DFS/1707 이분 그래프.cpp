#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, v, e;
vector<vector<int> > edge;
vector<int> color;

void dfs(int idx,int Color) {
	color[idx] = Color;

	for (int i = 0; i < edge[idx].size(); i++) {
		int next = edge[idx][i];
		
		if (color[next] == 0) { 
			dfs(next, -Color); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	for (int x = 0; x < k; x++) {
		bool flag = true;;

		cin >> v >> e;

		edge.assign(v + 1, vector<int>(0, 0));
		color.assign(v + 1, 0);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		for (int i = 0; i < color.size();i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (color[i] == color[edge[i][j]]) flag = false;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	
}
/*
	백준 1707번 이분 그래프
*/
