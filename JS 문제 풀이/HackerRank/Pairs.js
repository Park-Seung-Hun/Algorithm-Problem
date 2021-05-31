/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 행렬에서 두 원소의 차가 k인 pair찾기
 */

function pairs(k, arr) {
    let ans = 0;
    let s = new Set(arr);
    arr = Array.from(s);
    for(let i=0;i<arr.length-1;i++){
        for(let j=i+1;j<arr.length;j++){
            if(Math.abs(arr[i]-arr[j])===k) ans++;
        }
    }
    return ans;
}
