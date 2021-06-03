# 최대공약수(GCD)

- 두 수 A와 B의 최대공약수 G는 `A와 B의 공통된 약수 중 가장 큰 정수`이다.
- 최대공약수가 1인 두 수를 `서로소`라고 한다.

## 최대공약수 구하는 방법1

- `2부터 min(A,B)까지 모든 정수로 나누어 보는 방법`

```c++
int g = 1;
for (int i = 2; i <= min(a, b); i++) {
    // 두 수 a와 b가 i와 나누어 떨어질 경우
    if (a % i == 0 && b % i == 0) g = i;
}
```

## 최대공약수 구하는 방법2

- `유클리드 호제법` 이용 (1번보다 더 빠르다.)
- a를 b로 나눈 나머지를 r이라고 할 때, `GCD(a,b) = GCD(b,r)` 이므로 `r이 0이면 그떄 b가 최대 공약수`이다.

```c++
// 1. 재귀함수를 사용해서 구현
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// 2. 재귀함수를 사용하지 않고 구현
int gcd(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
```

- 세 수의 GCD는 GCD(a,b,c)=GCD(GCD(a,b),c)와 같다.


# 최소공배수(LCM)

- 두 수 A와 B의 최소공배수 G는 `A와 B의 공통된 배수 중 가장 작은 정수`이다.
- GCD를 응용해서 구할 수 있다.
- GCD(a,b)=g 일때 `최소공배수 l=g*(a/g)*(b/g)`

```c++
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return g * (a / g) * (b / g);
}
```
