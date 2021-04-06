let answer=0;
function dfs(arr,idx,sum,tg){
    if(idx===arr.length){
        if(sum===tg)answer++;
        return;
    }
    dfs(arr,idx+1,sum+arr[idx],tg);
    dfs(arr,idx+1,sum-arr[idx],tg);
}

function solution(numbers, target) {
    console.log(numbers);
    dfs(numbers,0,0,target);

    return answer;
}
