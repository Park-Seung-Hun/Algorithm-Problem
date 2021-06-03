# a의 b제곱

> a의 b제곱을 빠르게 구해야한다.

### 시간복잡도 O(b)

```c++
int ans = 1;
for (int i = 1; i <= b; i++) {
	ans = ans * a;
}
```

> 더 빠른 방법을 이용해야한다.

### 분할정복 ( O(logb) )

```c++
int calc(int a, int b) {
	if (b == 0) return 1; // a^0 = 1
	else if (b == 1) return a; // a^1 = 1
	else if (b % 2 == 0) { // a^b = a^b/2 * a^b/2 (b는 짝수)
		int tmp = calc(a, b / 2);
		return tmp * tmp;
	}
	else { // a^b = a * a^(b-1) (b는 홀수)
		return a * calc(a, b - 1);
	}
}
```

### 이진수 응용 ( O(logb) )

```c++
int calc(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
		}
		a = a * a;
		b /= 2;
	}
	return ans;
}
```

- 동작 과정 (예시 a=3, b=27)
  1. 27은 이진수로 11011이다.
  2. 27=1+2+8+16
  3. 3^27=3^(1+2+8+16)
