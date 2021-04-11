function solution(people, limit) {
    let answer = 0;

    people.sort(function (a,b){
        return b-a;
    });

    let lptr = 0;
    let rptr = people.length - 1;

    while (lptr < rptr) {
        let weight = people[lptr] + people[rptr];
        if (weight > limit) {
            ++lptr;
        } else {
            ++lptr;
            --rptr;
        }
        ++answer;
    }
    if (rptr === lptr) ++answer;
    return answer;
}

/*
풀이.
-> 구명보트의 limit은 people의 최대 값보다 항상 크다.

1. people의 내름차순 정렬
2. 왼쪽 idx , 오른쪽 idx 생성
3. 두 사람의 무게의 합이 limit보다 큰 경우 => 왼쪽 idx(무게가 큰 people)이동
4. 두사람의 무게의 합이 limit보다 작거나 같은 경우 => 왼쪽idx, 오른쪽 idx 동시 이동
5. 두 idx 가 같은 경우  
*/
