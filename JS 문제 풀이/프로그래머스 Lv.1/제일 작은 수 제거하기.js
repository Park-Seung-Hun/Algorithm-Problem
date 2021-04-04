function solution(arr) {
    let answer = [];
    let min = Math.min.apply(null,arr);

    arr.splice(arr.indexOf(min),1);
    if(arr.length===0) arr.push(-1);
    answer=arr;
    return answer;
}
