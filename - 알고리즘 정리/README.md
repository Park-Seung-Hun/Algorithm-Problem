## 📖코딩 테스트 알고리즘 정리

## 수학
### <a href="./수학/GCD와LCM.md" target="_blank">GCD와 LCM</a>
   - 최대공약수 및 최소공배수 구하기


### <a href="./수학/진법변환.md" target="_blank">진법 변환</a>
   - 10진법 수를 N진법 수로 변환


### <a href="./수학/순열과조합.md" target="_blank">순열과 조합</a>
   - next_permutation을 이용한 순열
   - next_permutation을 이용한 조합 (오름차순)
   - prev_permutation을 이용한 조합 (내림차순)

### <a href="./수학/소수.md" target="_blank">소수</a>
   - 일반적인 방법(루트N)
   - 에라토스테네스의 체(N*루트N)


### <a href="./수학/소인수분해와팩토리얼.md" target="_blank">소인수분해와 팩토리얼</a>
   - 소인수분해 : 정수 N을 소수의 곱으로 분해 (소수를 구하지 않고도 해결 가능)
   - 팩토리얼 : N!=1*2*3*....*N


### <a href="./수학/a의b제곱.md" target="_blank">a의 b제곱</a>
   - 시간복잡도 O(b)
   - 분할정복 ( O(logb) )
   - 이진수 응용 ( O(logb) )


### <a href="./수학/피보나치수.md" target="_blank">피보나치 수</a>
   - DP를 이용한 피보나치 수
   - 피사노 주기 : 피보나치 수를 K로 나눈 나머지는 주기를 가진다.


### <a href="./수학/이항계수.md" target="_blank">이항 계수</a>
   - n개 중에 K개를 **중복 없이** 뽑는 방법의 수 : `nCk`
   - n개 중에 K개를 **중복을 허용**하면서 뽑는 방법의 수 : `(n+k-1)Ck`
   - 0과 1로만 이루어진 문자열의 개수 : `(n+k)Ck`
   - 0과 1로만 이루어진 문자열의 개수 (1은 연속하지 않음) : `(n+1)Ck`
   - 카탈란 수 : `(1/(n+1))*2nCn`


### <a href="./수학/카탈란수.md" target="_blank">카탈란 수</a>
  - 여는 괄호 n개와 닫는 괄호 n개로 이루어진 올바른 괄호 문자열의 개수 `Cn`
  - 항 n+1개를 곱하는 순서의 수 `Cn`
  - 길이가 2n인 Dyck Words (총 n 쌍의 X, Y로 구성된 문자열로, 어떤 경우에서도 X보다 많은 수의 Y가 먼저 나올 수 없다)
  - leaf 노드가 n+1개인 서로 다른 포화 이진 트리의 개수
  - n X n 격자 그리드에서 서로 다른 경로의 수 찾기


### 알고리즘

- <a href="./Binary Search.md" target="_blank">이진 탐색</a>
  - 정렬된 배열에서 원하는 값을 빠른 시간내에 찾는 알고리즘


- <a href="./Two Pointers.md" target="_blank">투 포인터</a>
  1. 정렬된 두 배열을 하나로 합치는 경우
  2. 자연수로 된 배열의 부분 연속합이 k인 경우의 수
  3. 중복된 문자 없이 가장 긴 부분 문자열을 찾는 경우


- <a href="./구간합 배열.md" target="_blank">구간합 배열</a>
  - N개의 원소로 이루어진 배열의 합


- <a href="./Kadane's 알고리즘.md" target="_blank">Kadane's 알고리즘</a>
  - 배열의 최대 부분합을 O(N)의 시간 복잡도로 구하는 알고리즘.


### 트리

- <a href="./트리1.md" target="_blank">트리 1</a>
  - 트리, 이진 트리, 트리의 순회(전위 중위 후위), 트리의 부모 찾기, 트리의 지름


- <a href="./트리2.md" target="_blank">트리 2</a>
  - 이진 탐색 트리 만들기, LCA


- <a href="./세그먼트 트리.md" target="_blank">세그먼트 트리</a>
  - 배열 구간 연산


### 그래프 순회

- <a href="./DFS_BFS.md" target="_blank">BFS/DFS</a>
  - DFS: 현재 정점에 연결된 정점 순서대로<br>
  - BFS: 현재 정점에 연결된 모든 정점 먼저<br>


- <a href="./Backtracking.md" target="_blank">백트래킹</a>
  - 유망성이 없는 정점은 가지치기


- <a href="./위상 정렬.md" target="_blank">위상 정렬</a>
  - 유향 그래프의 순서를 정하는 알고리즘


### 그래프 최단거리

- <a href="./Dijkstra's algorithm.md" target="_blank">다익스트라</a>
  - 한 정점에서 다른 모든 정점까지의 최단거리 (가중치: 양)


- <a href="./Bellman-Ford Algorithm.md" target="_blank">벨만 포드</a>
  - 한 정점에서 다른 모든 정점까지의 최단거리 (가중치: 음,양)


- <a href="./Floyd-Warshall algorithm.md" target="_blank">플로이드 와샬</a>
  - 모든 정점끼리의 최단거리 (가중치: 음,양)


### 다이나믹 프로그래밍

- <a href="./Dynamic Programming.md" target="_blank">다이나믹 프로그래밍 개요</a>
  - 가장 긴 Palindromic 부분 문자열(릿코드 Medium)
- <a href="./DP Example1.md" target="_blank">DP 예제 1: 배낭문제</a>
- <a href="./DP Example2.md" target="_blank">DP 예제 2: LCS(최장 공통 부분수열)</a>
- <a href="./DP Example3.md" target="_blank">DP 예제 3: LIS(최장 증가 부분수열)</a>
- <a href="./DP Example4.md" target="_blank">DP 예제 4: 편집거리</a>
