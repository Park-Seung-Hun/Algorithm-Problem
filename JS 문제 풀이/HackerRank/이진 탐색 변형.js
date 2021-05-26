/*
번역
앨리스는 아케이드 게임을 하고있으며 리더보드에 탑으로 올라가는 것과 그녀의 랭킹을 추적하길 원한다.
게임은 Dense Ranking을 사용하고, 리더보드는 다음과 같이 동작한다.

-> 플레이어 중 가장 높은 점수가 1번이 되는 리더보드이다.
-> 플레이어가 동일한 점수이면, 동일한 랭킹 넘버를 받으며, 다음 플레이어는 바로 다음 랭킹 번호를 받는다.

예를들어 플레이어 4명의 점수가 각각 100, 90, 90, 80이면, 플레이어는 각각 1,2,2,3 의 랭킹을 가진다.
만약 엘리스의 스코어가 70, 80, 105라면 그녀의 랭킹은 각각 4등, 3등, 1등이다.



함수 설명
아래 에디터에서 climbingLeaderboard 함수를 완성하라. 리턴값은 앨리스의 j번째 게임 순위를 각각의 원소로 하는 정수형 배열을 나타낸다.
climbingLeaderboard 함수는 아래와 같은 파라미터를 받는다.[s]
스코어 : 정수형 배열로 리더보드의 스코어를 나타낸다.
앨리스 : 정수형 배열로 앨리스의 점수를 나타낸다.

풀이 : 이진 탐색을 이용해 푼다.
1. ranked를 중복 없는 배열로 만든다.
2. alice가 득점한 점수마다 경우를 적용한다.
  2-1 alice의 점수가 ranked의 가장 첫 점수보다 높거나 같은 경우 = 1등
  2-2 alice의 점수가 ranked의 가장 마지막 점수보다 작은 경우 = ranked길이 +1 등
  2-2 나머지 경우 => 이진 탐색
3. 나머지 경우엔 이진 탐색을 이용하여 alice의 점수 값이 어느 순위에 위치하는지 확인한다.
  3-1 ranked[mid] 점수와 alice의 점수가 같은 경우 => mid+1등 (배열은 0부터 시작하므로)
  3-2 ranked[mid+1] < alice < ranked[mid] => mid+1 +1 등
  3-3 alice < ranked[mid] ?? 이부분이 잘 모르겠음
*/

function climbingLeaderboard(ranked, player) {
    let result = [];
    let uniqueScores = [...new Set(ranked)];

    const rankBinarySearch = function(s,u){
        let left = 0;
        let right = u.length-1;

        while(true){
            let mid = parseInt((left+right)/2);

            if(u[mid]===s){
                return mid+1;
            }
            else if (u[mid] > s && u[mid + 1] < s) {
                return mid + 2;
            } else if (u[mid] < s && u[mid - 1 > s]) {
                return mid - 1;
            }

            if(s<u[mid]) left = mid+1;
            else right = mid-1;
        }
    }


    for(let i=0;i<player.length;i++){
        let num = player[i];

        if(num>=uniqueScores[0]) result.push(1);
        else if(num<uniqueScores[uniqueScores.length-1]) result.push(uniqueScores.length + 1)
        else{
            result.push(rankBinarySearch(num, uniqueScores));
        }
    }

    return result;
}
