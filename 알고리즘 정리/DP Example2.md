DP Example2 LCS(최장 공통 부분수열)
===========

- 정의
> **주어진 수열 모두의 부분 수열이 되는 수열 중 가장 긴 수열을 찾는 문제**
<br>

- 풀이<br>
> 예시를 통해 풀이. A={a,b,a,a,b,c,d} B={b,a,a,d,c,a}의 LCS 구하기.
`lcs[i][j]=LCS(A[0,i],B[0,j])의 길이` : A문자열의 0-i번까지의 부분문자열과 B문자열의 0-j번까지의 부분문자열의 LCS<br>

### lcs 값의 세가지 상태
1.`lcs[i-1][j]에 A[i]가 새롭게 붙은 경우`: lcs[i-1][j]에 A[i]가 추가되어도 lcs[i][j]의 값은 증가할 수 없다. <br>
2.`lcs[i][j-1]에 B[j]가 새롭게 붙은 경우`: lcs[i][j-1]에 B[j]가 추가되어도 lcs[i][j]의 값은 증가할 수 없다. <br>
3.`lcs[i-1][j-1]에 A[i],B[j]가 새롭게 붙은 경우`: lcs[i-1][j-1]에 A[i],B[j]가 추가되면 lcs[i-1][j-1]까지의 값에서 1 증가한다.<br>

점화식:
``` c++
            0                             if(i==0 or j==0)                            
lcs[i][j] = lcs[i-1][j-1]+1               if(A[i-1]==B[j-1])
            max(lcs[i-1][j],lcs[i][j-1]   
```


### LCS Code
```c++
#include <iostream>
#include <string>
using namespace std;

int lcs[1001][1001];
string a, b;

int main() {
    int la, lb;
    // a문자열 b문자열의 길이
    cin >> la >> lb;
    cin >> a >> b;

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            // lcs에 a와 b 모두 붙을 때 ( 부분 수열의 원소 )
            // lcs의 길이 증가
            else {
                if (lcs[i - 1][j] < lcs[i][j - 1]) {
                    lcs[i][j] = lcs[i][j - 1];
                }// b가 새롭게 붙여진 경우
                else {
                    lcs[i][j] = lcs[i - 1][j];
                }// a가 새롭게 붙여진 경우
            }
            // lcs에 a와 b 둘중 하나라도 붙지 않았을 때 ( 부분수열 x )
            // lcs의 길이는 이전 lcs의 길이중 최대 값
        }
    }

    cout << lcs[la][lb] << "\n";
    // lcs 값
    return 0;
/*
input:
7  6
abaabcd
baadca

output(LCS의 길이):
4
*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote)
