Bellman-Ford Algorithm(벨만 포드 알고리즘)
===========

- 벨만 포드 알고리즘 이란?
> 그래프의 최단 경로를 찾는 알고리즘으로 다익스트라 알고리즘과 달리 거리 값이 음수일 때도 사용한다. 

**그래프의 어떤 정점 하나를 시작점으로 선택하고, 나머지 정점들로의 최단거리를 모두 구하는 알고리즘.**
<br>

정점 개수 V, 간선 개수 E 일때 O(VE)의 시간복잡도를 가진다.
<br>
<br>

- 벨만 포드의 동작 과정

> 기본적인 아이디어는 다익스트라와 비슷하다.

1. 해당 노드까지의 최단 거리를 저장할 dist 배열 선언 (이때 배열의 값을 무한대로 초기화 한다. 시작 정점은 0)
2. 모든 간선을 확인하여 최단거리를 갱신한다. (간선 u->v 일때, dist[v]와 dist[u]+w[e](간선의 가중치)를 비교)
3. 2의 과정을 v번 반복한다. 
> v번 반복하는 이유: 음수 사이클이 있을 경우 무한하게 갱신되는데 v번째 갱신되는 경우 음수 사이클임을 이용해 음수 사이클을 판별하기 위해.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fcqs85e%2FbtqEtuQAKUi%2Fk4KpMiYQbqmEHFBJ8qemYk%2Fimg.gif" width="600">
<h6>사진 출처: https://haningya.tistory.com/116</h6>
<br>

##### Code

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int V, E, S;
int u, v, d;
vector < vector<pair<int, int> > > edge;

vector<int> bellmanFord(int start) {
    vector<int> upper(V + 1, INF);
    upper[start] = 0; // 시작 정점의 거리 값
    bool updated; // 음수 사이클이 존재하는지 판단하는 변수 ( v번째 갱신되어 True로 나오면 음수사이클 존재. )

    for (int iter = 0; iter < V; iter++) {
        updated = false;
        for (int here = 1; here <= V; here++) { // 모든 간선 확인
            for (int i = 0; i < edge[here].size(); i++) { 
                int there = edge[here][i].first;
                int	nextcost = upper[here] + edge[here][i].second;

                if (upper[there] > nextcost) {
                    upper[there] = nextcost;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }
    if (updated) upper.clear(); 
    return upper;
}


int main() {
    cin >> V >> E >> S;
    edge.resize(V + 1);

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> d;
        edge[u].push_back(make_pair(v, d));
    }
    vector<int> dist = bellmanFord(S);
    
    if (dist.empty())
        cout << -1 << endl;
    else {
        for (int i = 1; i <= V; i++) {
            cout << dist[i] << endl;
        }
    }
    return 0;
}

/*
input:
정점의 개수, 간선의 개수, 시작정점 (음수 사이클 발견시 -1)
7  11  1
1  2  10
1  3  3
1  7  20
2  3  4
2  4  3
3  5  7
4  3  11
5  7  -1
6  5  -2
7  6  -3
6  4  2
output:
-1
*/
```
참고 사이트 : [코드그라운드](https://www.codeground.org/common/popCodegroundNote), [Rise 마법의 슈퍼미라오 블로그](https://m.blog.naver.com/kks227/220796963742)
