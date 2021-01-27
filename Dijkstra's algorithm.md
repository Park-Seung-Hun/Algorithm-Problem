Dijkstra's algorithm(다익스트라 알고리즘)
===========

- 다익스트라 알고리즘 이란?
> 그래프의 최단 경로를 찾는 알고리즘으로 모든 거리 값이 음수가 아닐 때만 사용한다. 

**그래프의 어떤 정점 하나를 시작점으로 선택하고, 나머지 정점들로의 최단거리를 모두 구하는 알고리즘.**
<br>

정점 개수 V, 간선 개수 E 일때 O(ElogV)의 시간복잡도를 가진다.
<br>
<br>

- 다익스트라의 동작 과정

> 동작과정은 너비 우선 탐색(BFS)과 굉장히 유사하다.

1. 해당 노드까지의 최단 거리를 저장할 dist 배열 선언 (이때 배열의 값을 무한대로 초기화 한다.)
2. 우선순위 큐를 선언하여 시작 정점과 해당 정점의 거리 값을 저장한다.
3. 우선순위 큐에 저장된 정점 중 비용이 작은 정점부터 시작해 인접한 정점 값을 산출한다.
4. 현재 노드의 비용과 다음 노드의 비용의 합이 해당 노드까지의 최소비용보다 작을 때 갱신한다. ( dist[Next]>Cost+nCost )
5. 갱신된 값을 다시 우선순의 큐에 저장한다.

<img src="https://media.vlpt.us/images/soulee__/post/1d48ffec-5d29-4c4e-9d75-db5e3988d2a3/img.gif" width="600">
<h6>사진 출처: https://velog.io/@soulee__/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98</h6>
<br>

##### Code

```c++
#define MAX 105
#define INF 0x7fffffff
int Dist[MAX];

void init() {
    for (int i = 1; i <=V; i++)
        Dist[i] = INF;
    // 처음 비용은 모두 무한대로 초기화 한다.
}

void Dijkstra_Using_Heap(int Start)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;
    //우선순위큐를 이용해 '비용'이 가장 작은 값을 선점한다.

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        // 우선순위큐에 아무런 조치를 하지 않으면 가장 위에 큰 수가 온다.
        // 따라서 해당 값에 -를 넣으면 가장 작은 값이 위로 온다

        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;
            
            // 현재 노드의 비용과 다음 노드의 비용의 합이 해당 노드까지의 최소비용보다 작을때 갱신
            if (Dist[Next] > Cost + nCost) { 
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
                // 최소 힙 즉, 가장 작은 값을 먼저 선점하기 위해 -를 넣는다
            }
        }
        // 현재 노드와 연결된 간선만큼 반복문
    }

    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }
}

```
