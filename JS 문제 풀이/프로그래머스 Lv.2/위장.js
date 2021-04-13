function solution(clothes) {
    let answer = 1;
    let obj = {};

    for(let i=0;i<clothes.length;i++){
        const cloth = clothes[i][1];

        if(cloth in obj){
            obj[cloth]++;
        }
        else obj[cloth]=1;
    }

    // 각 의상의 종류에따라 각각의 경우의 수를 찾아 곱한다.
    // [1,2] => x , 1 , 2

    for(let key in obj){
        answer*=(obj[key]+1);
    }
    // -1은 모든 의상을 입지 않는 경우를 제외하는 것.
    return answer-1;
}
