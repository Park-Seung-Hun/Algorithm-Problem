function solution(s){
    let answer = 0;
    // 1. 문자열을 나눈다.
    let arr = s.split('');
    // 2. stack 활용
    let stack = [];
    for(let i=0;i<arr.length;i++){
        if(stack.length!==0){
            if(stack[stack.length-1]===arr[i]) stack.pop();
            else stack.push(arr[i]);
        }else{
            stack.push(arr[i]);
        }
    }

    if(stack.length!==0) return 0;
    return 1;
}

/*
1. 문자열에서 같은 알파벳이 붙은 짝을 찾는다.
2. 그 둘을 제거하고 앞뒤로 문자열을 이어 붙인다.
3. 이 과정을 반복해서 모두 제거 가능하면 return 1 아니면 return 0;
*/
