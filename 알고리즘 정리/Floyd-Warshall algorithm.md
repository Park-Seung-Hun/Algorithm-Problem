Floyd-Warshall algorithm(플로이드-워샬 알고리즘)
===========

- 플로이드-워샬 알고리즘 이란?
> 그래프의 최단 경로를 찾는 알고리즘으로 모든 거리 값에 상관없이 사용한다. 

**그래프에서 모든 정점 사이의 최단거리를 모두 구하는 알고리즘.**
<br>

정점 개수 V, 간선 개수 E 일때 O(V^3)의 시간복잡도를 가진다.
<br>
<br>
- 플로이드-워샬의 동작 과정

> 동작과정은 다익스트라 알고리즘을 모든 정점에서 동작시킨것과 같다.

1. 노드 i에서 j까지 가는 간선의 가중치 배열 d[i][j]을 선언한다. (이때 연결되지 않은 간선은 가중치 무한대) 
2. 3중 for문을 이용하여 모든 정점쌍 (i,j)에 대해 k라는 경유지를 거쳤을 때를 확인한다.
3. 정점쌍 (i,j)가 k라는 경유지를 거치지 않은 경우는 제외한다. (d[i][k]==INF && d[k][j]==INF)
4. 모든 정점쌍 (i,j)에 대하여 k라는 경유지를 거쳤을 때, 기존의 정점쌍의 거리보다 짧아진다면, 정점쌍의 최단거리를 갱신시켜줍니다. (d[i][j] > d[i][k] + d[k][j])
> 이때 모든 최단거리는 음수 사이클이 없다면, 그 경로의 길이는 당연히 N이하가 되고(그래프의 크기) 이를 이용해 동적계획법으로 해결 가능합니다.

##### Code

```c++
#include <iostream>
#define MAX 105
#define INT_MAX 0x7fffffff
using namespace std;

int n, d[MAX][MAX];

void floyd_warwhall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue; // 정점쌍 (i,j)가 k라는 경유지를 거치지 않은 경우는 제외
        
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];  
          /*
            모든 정점쌍 (i,j)에 대하여 k라는 경유지를 거쳤을 때, 기존의 정점쌍의 거리보다 짧아진다면, 정점쌍의 최단거리를 갱신
          */ 
			}
}

int main() {
	cin >> n; // 그래프 크기 선언

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			if (d[i][j] == 0) d[i][j] = INT_MAX; // 연결되지 않은 간선은 가중치 INF
		}

	floyd_warwhall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << d[i][j] << " ";
		cout << endl;
	}
}


```
