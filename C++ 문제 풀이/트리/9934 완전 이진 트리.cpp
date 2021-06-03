#include <iostream>
#include <cmath>
using namespace std;
int k,cnt;
int n[1024];
int ans[1024];

void findTree(int idx, int depth) {
	if (depth == k) { // 가장 마지막 노드인 경우
		ans[idx] = n[cnt++];
	}
	else { // 가장 마지막 노드가 아닌 경우 (중위 순회)
		findTree(idx * 2, depth + 1);
		ans[idx] = n[cnt++];
		findTree(idx * 2 + 1, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	int num = pow(2, k) - 1;
	for (int i = 0; i < num; i++) cin >> n[i];

	findTree(1, 1);


	for (int n = 0, idx = 1; n < k; n++) {
		for (int i = 0; i < 1 << n; i++) {
			cout << ans[idx++] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
