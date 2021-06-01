/*
  해당 문제는 15퍼즐 문제를 알고있어야 풀이가 가능
  15퍼즐 문제란?
  https://gamjeon.tistory.com/19

  풀이 :
  주어진 배열을 pair로 검사하여 index가 작은 요소가 더 큰 경우 count한다.
  count한 수가 짝수이면 => 정렬 가능
  count한 수가 홀수이면 => 정렬 불가능
*/

function larrysArray(A) {
    console.log(A);
    let cnt = 0;
    for(let i=0;i<A.length-1;i++){
        for(let j=i+1;j<A.length;j++){
            if(A[i]>A[j])cnt++;
        }
    }

    if(cnt%2===0) return "YES";
    else return "NO";
}
