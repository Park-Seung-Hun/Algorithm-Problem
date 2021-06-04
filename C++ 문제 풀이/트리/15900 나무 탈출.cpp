/*
15900번 나무 탈출
depth의 길이가 전부 짝수인 경우 => No
depth의 길이가 홀수이고 홀수가 짝수개 있는 경우 => No
depth의 길이가 홀수이고 홀수가 홀수개 있는 경우 => Yes
*/

#include <iostream>
#include <vector>
using namespace std;
int n, a ,b;
int leaf;
vector<vector<int>> node;
vector<bool> check;


/*
leaf 노드 구하는 방법을 터득!
*/
void dfs(int n,int depth) {
    check[n] = true;

    int cnt = 0;

    for (int i = 0; i < node[n].size(); i++) {
        if (check[node[n][i]])continue;
        cnt++;
        dfs(node[n][i],depth+1);
    }

    if (!cnt) {
        if (depth % 2 == 1) {
            leaf++;
        }
    }
    return;
}

int main() {
    cin >> n;

    // 1. 노드의 간선을 전부 연결한다,
    node.resize(n + 1);
    check.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }


    // 2. 루트를 타고 내려가 Leaf노드를 구한다.(DFS)
    dfs(1,0);


    if (leaf % 2 == 0) cout << "No";
    else cout << "Yes";
    return 0;
}
