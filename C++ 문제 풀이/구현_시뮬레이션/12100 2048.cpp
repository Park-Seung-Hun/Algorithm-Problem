#include <iostream>
#include <vector>
using namespace std;

int n,num,answer;
vector<vector<int>> board;
vector<vector<bool>> check;

void Move(vector<vector<int>> board, int move,int cnt) {
	if (cnt > 5) return;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0)answer = max(answer, board[i][j]);
		}
	}



	check.assign(n, vector<bool>(n, false));

	if (move == 0) { // 위로 이동

		for (int j = 0; j < n; j++) {
			for (int i = 1; i < n; i++) {
				if (board[i][j] != 0) {
					int tmp = board[i][j];
					int idx = i;

					while (true) {
						idx--;
						if (board[idx][j] == 0) { // 비어있는 보드인 경우 = 이동
							board[idx + 1][j] = 0;
							board[idx][j] = tmp;
						}
						else {
							if (board[idx][j] == tmp) { // 숫자가 적힌 보드 중 숫자가 같은 경우
								if (check[idx][j] == false) { // 한번도 합쳐진 적이 없는 경우
									check[idx][j] = true;
									board[idx][j] = tmp * 2;
									board[idx + 1][j] = 0;
									break;
								}
								else break; // 합쳐진 경우
							}
							else break;
						}

						if (idx == 0) break;
					}
				}
			}
		}


		for (int i = 0; i < 4; i++) Move(board, i, cnt + 1); // 다시 이동
	}
	else  if (move == 1) { // 오른쪽
		for (int i = 0; i < n; i++) {
			for (int j = n-2; j >=0; j--) {
				if (board[i][j] != 0) {
					int tmp = board[i][j];
					int idx = j;

					while (true) {
						idx++;
						if (board[i][idx] == 0) { // 비어있는 보드인 경우 = 이동
							board[i][idx - 1] = 0;
							board[i][idx] = tmp;
						}
						else {
							if (board[i][idx] == tmp) { // 숫자가 적힌 보드 중 숫자가 같은 경우
								if (check[i][idx] == false) { // 한번도 합쳐진 적이 없는 경우
									check[i][idx] = true;
									board[i][idx] = tmp * 2;
									board[i][idx - 1] = 0;
									break;
								}
								else break; // 합쳐진 경우
							}
							else break;
						}

						if (idx == n-1) break;
					}
				}
			}
		}


		for (int i = 0; i < 4; i++) Move(board, i, cnt + 1); // 다시 이동

	}
	else if (move == 2) { // 아래

		for (int j = 0; j < n; j++) {
			for (int i = n-2; i >=0; i--) {
				if (board[i][j] != 0) {
					int tmp = board[i][j];
					int idx = i;

					while (true) {
						idx++;
						if (board[idx][j] == 0) { // 비어있는 보드인 경우 = 이동
							board[idx - 1][j] = 0;
							board[idx][j] = tmp;
						}
						else {
							if (board[idx][j] == tmp) { // 숫자가 적힌 보드 중 숫자가 같은 경우
								if (check[idx][j] == false) { // 한번도 합쳐진 적이 없는 경우
									check[idx][j] = true;
									board[idx][j] = tmp * 2;
									board[idx - 1][j] = 0;
									break;
								}
								else break; // 합쳐진 경우
							}
							else break;
						}

						if (idx == n-1) break;
					}
				}
			}
		}


		for (int i = 0; i < 4; i++) Move(board, i, cnt + 1); // 다시 이동
	}
	else {// 왼쪽

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (board[i][j] != 0) {
					int tmp = board[i][j];
					int idx = j;

					while (true) {
						idx--;
						if (board[i][idx] == 0) { // 비어있는 보드인 경우 = 이동
							board[i][idx+1] = 0;
							board[i][idx] = tmp;
						}
						else {
							if (board[i][idx] == tmp) { // 숫자가 적힌 보드 중 숫자가 같은 경우
								if (check[i][idx] == false) { // 한번도 합쳐진 적이 없는 경우
									check[i][idx] = true;
									board[i][idx] = tmp * 2;
									board[i][idx + 1] = 0;
									break;
								}
								else break; // 합쳐진 경우
							}
							else break;
						}

						if (idx == 0) break;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) Move(board, i, cnt + 1); // 다시 이동
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	board.assign(n, vector<int>(n, 0));

	if (n == 1) {
		cin >> num;
		cout << num;
	}
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		for (int i = 0; i < 4; i++) {
			Move(board, i, 0);
		}
		cout << answer << '\n';
	}

	return 0;
}
