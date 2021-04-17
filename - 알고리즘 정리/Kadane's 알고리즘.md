Kadane's 알고리즘
===========

- Kadane's 알고리즘이란?
  - 배열 최대 부분 합을 O(n)의 시간복잡도로 구하는 알고리즘.



- 예제로 알아보는 Kadane's 알고리즘 동작<br>
  - i번째 인덱스를 오른쪽 끝으로 하는 부분배열들의 최대 부분 합을 M[i]라고 할때, `M[i+1]=max(M[i]+arr[i+1],arr[i+1])` 이다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FDutBF%2FbtqDGgylwPq%2FikOY8oOrFveyZeaPie02bK%2Fimg.png">


1. `M[0]=arr[0] => 1`
2. `M[1]=arr[1]+M[0] or arr[1] => -5 or -6 중에 -5이다.`
3. `M[2]=arr[2]+M[1] or arr[2] => -1 or 4 중에 4이다.`
4. `M[i+1]=arr[i+1]+M[i] or arr[i+1]`


##### Code

```js
let a1=0;
let a2=nums[0];

for(let idx=0;idx<nums.length;idx++){
    a1 = Math.max(nums[idx], a1+nums[idx]);
    a2 = Math.max(a2,a1);
}
return a2;
```

```c++
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, array[100000], m[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    m[0] = array[0];
    int res = m[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, m[i] = max(m[i - 1] + array[i], array[i]));
    }
    cout << res;
}
```
