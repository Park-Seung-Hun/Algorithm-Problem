DP Example2 LCS(최장 공통 부분수열)
===========

- 정의
> **주어진 수열 모두의 부분 수열이 되는 수열 중 가장 긴 수열을 찾는 문제**
<br>

- 풀이<br>
> 예시를 통해 풀이. A={a,b,a,a,b,c,d} B={b,a,a,d,c,a}의 LCS 구하기.
lcs[i][j]=LCS(A[0,i],B[0,j])의 길이 : A문자열의 0~i번까지의 부분문자열과 B문자열의 0~j번까지의 부분문자열의 LCS

점화식: **D[i][j] = Max(D[i-1][j], D[i-1][j - W[i]] + V[i])**<br>
* 위 D[i][j]를 채우는 두 가지 경우를 점화식으로 나타낸 것. 
  - D[i-1][j]는 i번째 물건을 넣지 않는 상태, 무게 j의 변화 없음.
  - D[i-1][j-W[i]] + V[i]는 i번째 물건을 넣는 상태를 의미, 무게 j에 물건의 무게 W[i]만큼 빼고, 가치 V[i]만큼 더해준다.

### LCS Code
```c++
/*
input:

output(물건 가치의 총합):

*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote)
