function solution(s) {
    let answer = 0;
    let arr = s.split('');

    const check = function (arr){
        let stack = [];
        let tmp='';
        for(let char of arr){

            if(stack.length===0) stack.push(char);
            else{
                if(char === ')'){
                    tmp=stack.pop();
                    if(tmp!=='(') return false;
                }else if(char === '}') {
                    tmp=stack.pop();
                    if(tmp!=='{') return false;

                }else if(char === ']'){
                    tmp=stack.pop();
                    if(tmp!=='[') return false;

                }else{
                    stack.push(char);
                }
            }

        }

        if(stack.length!==0) return false;
        return true;
    }

    for(let i=0;i<arr.length;i++){
        if(check(arr)) answer++;

        arr.push(arr.shift());
    }
    return answer;
}
