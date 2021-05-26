/*
마방진은 n x n 행렬에서 각각의 위치의 양수가 1에서 n^2 사이이고, 모든 행과 열, 대각선의 합이 항상 동일한 값을 가진다. 이 동일한 값을 마법상수라 한다.
1부터 9 사이에 정수값을 범위로 하는 3x3 행렬 s가 주어진다.
우리는 어떤 숫자 a를 1부터 9사이의 다른 값 b로 |a-b|((절대값) 만큼의 비용을 사용하여 변환할 수 있다.
주어진 s를 통해 최소의 비용으로 마방진을 완성하라. 비용을 새 라인에 출력하라.
Note: 결과는 1부터 9 사이의 정수를 반드시 포함하고 있는 마방진이어야 한다.


예를들어, 아래 행렬 s가 주어진다
5 3 4
1 5 8
6 4 2

우리는 아래 마방진으로 변환할 수 있다.
8 3 4
1 5 9
6 7 2


이렇게 변환하는데 드는 비용은 [5-8]+[8-9]+[4-7] = 7 이다.
(3 + 1 + 3)


함수 설명
아래 편집기에서 formingMagicSquare 함수를 완성하라.
행렬을 마방진으로 변환하기 위한 최소 비용의 합계를 리턴해야한다.
formingMagicSquare는 다음의 파라미터를 가진다.
S : 3x3 정수배열

=> 풀이
1. 기본 3x3 마방진을 하나 만든다
2. 마방진을 회전, 대칭 하는 함수와 마방진끼리 비교하여 비용을 구하는 함수 만들기
3. 앞선 함수들을 이용해 최소 비용을 구한다.

*/


function formingMagicSquare(s) {
    let answer = 987654321;

    let arr = [[6,1,8],[7,5,3],[2,9,4]];

    const cycleArr = function(arr){
        let ref = new Array(3).fill(null).map(()=>new Array());
        for(let i=0;i<3;i++){
            for(let j=0;j<3;j++){
                ref[i][j]=arr[2-j][i];
            }
        }

        return ref;
    }

    const mirrorArr = function(arr){
        let ref = new Array(3).fill(null).map(()=>new Array());
        for(let i=0;i<3;i++){
            for(let j=0;j<3;j++){
                ref[i][j]=arr[i][2-j];
            }
        }
        return ref;
    }

    const calculateNum = function(A,B){
        let ref = 0;
        for(let i=0;i<3;i++){
            for(let j=0;j<3;j++){
                ref+=Math.abs(A[i][j]-B[i][j]);
            }
        }
        return ref;
    }

    for(let i=0;i<4;i++){
        let tmp_arr = mirrorArr(arr);

        let num = Math.min(calculateNum(s,tmp_arr),calculateNum(s,arr));
        answer=Math.min(answer,num);

        arr=cycleArr(arr);
    }
    return answer;
}
