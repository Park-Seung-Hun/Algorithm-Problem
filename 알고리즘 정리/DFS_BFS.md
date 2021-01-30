Depth-First Search algorithm(깊이 우선 탐색 알고리즘)
===========

- 깊이 우선 탐색 알고리즘 이란?
> 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘

**현재 정점과 인접한 간선들을 검사해 방문하지 않은 정점 발견하면 해당 정점으로 이동한다.
이동하는 과정을 반복하여 더 이상 방문할 정점이 없으면, 지나온 간선을 통해 뒤로 돌아가 지나온 정점들로부터 방문 가능한 정점을 탐색하여 이동한다.**
<br>

정점 개수 V, 간선 개수 E 일때 O(V+E)의 시간복잡도를 가진다.
<br>
<br>
- DFS의 동작 과정

1. 방문 정점들을 표시하기 위한 배열 visited[]를 선언하고, 간선을 통해 연결된 정점들을 방문하기 위해 재귀 함수를 이용한다. (재귀함수의 매개변수=현재 정점)
2. 현재 정점의 방문 여부를 체크한다.
3. 현재 정점과 인접한 간선을 검사해 연결된 정점들을 찾는다. 이때, 방문한 적이 있는 정점이면 skip하고 방문하지 않은 정점이면 해당 정점으로 다시 반복한다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fba7LU5%2FbtqEjDNlnmq%2FXOo122GKWgP62W3dAtGYtK%2Fimg.gif" width="600">
<h6>사진출처: https://haningya.tistory.com/102?category=893241</h6>

##### Code
> 스택 or 재귀함수를 통해 구현한다.

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edge;
vector<bool> visited;
int V, E;
int u, v;

void dfs(int cur) {
    visited[cur] = true;
    // 해당 노드 방문 여부 체크
    cout << cur << ' ';

    for (int i = 0; i < edge[cur].size(); i++) {
        int there = edge[cur][i];
        // 해당 노드와 연결된 노드 

        if (visited[there]) continue;
        // 방문한 적이 있는 노드면 skip

        dfs(there);
        // 연결되있던 노드로 다시 dfs
    }
// 현재 노드와 연결된 간선만큼 반복문

}

int main() {
    cin >> V >> E;

    edge.resize(V + 1);
    visited.resize(V + 1);

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
    }
    dfs(1);
}
// 1번 정점에 연결된 정점들을 순서대로 순회하는 code
/*
input:
7 11
1 2
1 3
1 7
2 3
2 4
3 5
4 3
5 7
6 5
7 6
6 4

output:
1 2 3 5 7 6 4
*/
```
---------------
Breadth-First Search algorithm(넓이 우선 탐색 알고리즘)
===========

- 넓이 우선 탐색 알고리즘 이란?
> 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘

**현재 정점과 인접한 간선들을 검사해 방문하지 않은 정점을 발견하면 자료구조 queue에 넣는다. 해당 과정을 통해 현재 정점과 연결된 모든 정점들을 queue에 넣고 queue의 front에 있는 다음 정점으로 이동해 검사를 반복한다.**
<br>

정점 개수 V, 간선 개수 E 일때 O(V+E)의 시간복잡도를 가진다.
<br>
<br>
- BFS의 동작 과정

1. 방문 정점들을 표시하기 위한 배열 visited[]를 선언하고, 간선을 통해 연결된 정점들을 방문하기 위해 자료구조 queue를 이용한다. (자료구조 queue의 front=현재 정점)
2. 현재 정점의 방문 여부를 체크한다.
3. queue의 front를 pop하여 현재 정점으로 선언하고, 인접한 모든 간선을 검사하여 연결된 다음 정점을 찾아 다시 queue에 저장한다.
4. queue가 빌 때까지 3의 과정을 반복한다.  


<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fba7LU5%2FbtqEjDNlnmq%2FXOo122GKWgP62W3dAtGYtK%2Fimg.gif" width="600">
<h6>사진출처: https://haningya.tistory.com/102?category=893241</h6>

##### Code
> queue를 통해 구현한다.

```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > edge;
vector<bool> visited;
int V, E;
int u, v;

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    // 현재 노드를 저장할 큐 생성

    visited[cur] = true;
    // 현재 노드 방문 체크    
    

    while (!q.empty()) {
        int here = q.front();
        // 큐에 저장된 노드
        q.pop();

        cout << here << ' ';
        for (int i = 0; i < edge[here].size(); i++) {
            int there = edge[here][i];
            if (visited[there]) continue;
            visited[there] = true;
            q.push(there);
            // 방문하지 않고 현재 노드와 간선으로 연결된 경우
            // 큐에 다음 노드를 삽입한다.
        }
        // 현재 노드와 연결된 간선 만큼 반복문
    }
}

int main() {
    cin >> V >> E;
    edge.resize(V + 1);
    visited.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
    }
    bfs(1);
}
// 1번 정점에 연결된 정점들을 순서대로 순회하는 code
/*
input:
7 11
1 2
1 3
1 7
2 3
2 4
3 5
4 3
5 7
6 5
7 6
6 4

output:
1 2 3 7 4 5 6
*/
```
