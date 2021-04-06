function solution(arr1, arr2) {
    let answer = [];
    for(let row = 0;row<arr1.length;row++){
        let tmp = [];
        for(let col=0;col<arr1[0].length;col++){
            tmp.push(arr1[row][col]+arr2[row][col])
        }
        answer.push(tmp);
    }
    return answer;
}
