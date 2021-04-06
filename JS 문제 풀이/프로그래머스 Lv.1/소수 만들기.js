function solution(nums) {
    let answer = 0;

    let len = nums.length;
    let arr=[];

    for(let i=0;i<len-2;i++){
        for(let j=i+1;j<len-1;j++){
            for(let k=j+1;k<len;k++){
               arr.push(nums[i]+nums[j]+nums[k]);
            }
        }
    }

    let max = Math.max.apply(null,arr);

    let check=Array.from({length: max+1}, ()=>false); // 소수 체크 배열

    check[0]=check[1]=true;
    for(let i=2;i<max;i++){
        if(check[i]===false){
            for(let j=i+i;j<=max;j+=i) check[j]=true;
        }
    }

    for(let num of arr) {
        if(check[num]===false) answer++;
    }
    return answer;
}
