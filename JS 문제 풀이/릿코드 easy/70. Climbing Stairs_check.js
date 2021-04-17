/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let arr = Array.from({length:46},()=>0);
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;

    if(n < 3) return arr[n];

    for(let i=3;i<=n;i++){
        arr[i]=arr[i-2]+arr[i-1];
    }
    return arr[n];
};


/*
DP로 푸는 문제.
*/
