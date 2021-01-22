#include <iostream>
using namespace std;
const int MAX = 1000000000;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;

    //확률이 바뀔 수 없는 경우

    if (Z >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    int low = 0, high = MAX;
    int result = -1;

    while (low <= high) {

        int mid = (low + high) / 2;
        //이분탐색 결과 확률

        int tempZ = (100 * (Y + mid)) / (X + mid);

        if (Z >= tempZ) {
            result = mid + 1;
            low = mid + 1;
        }
        else high = mid - 1;

    }

    cout << result << "\n";
    return 0;

}

/*
    백준 1072번 게임
*/
