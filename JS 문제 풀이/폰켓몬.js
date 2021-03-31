function solution(nums) {
    let answer = 0;
    let set = new Set(nums);
    let size = nums.length/2;

    for(let num of nums) set.add(num);

    if(set.size>size) answer=size;
    else answer=set.size;

    return answer;
}

/*
최대한 많은 종류의 폰켓몬을 가져가는 경우에서 폰켓몬의 종류 갯수
Tip. set의 사이즈는 size이다.

*/
