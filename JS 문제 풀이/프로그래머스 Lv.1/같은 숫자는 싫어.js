function solution(arr)
{
    let answer = [];

    for(let num of arr) {
        if(answer[answer.length-1] !== num) answer.push(num);

    }
    return answer;
}
