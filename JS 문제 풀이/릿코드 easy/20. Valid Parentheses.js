/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    let arr = s.split('');
    let top;
    for(let char of arr){
        if(char === ')'){
            if(stack.length===0) return false;
            top=stack.pop();
            if(top!=='(') return false;
        }else if(char===']'){
            if(stack.length===0) return false;
            top=stack.pop();
            if(top!=='[') return false;
        }else if(char === '}'){
            if(stack.length===0) return false;
            top=stack.pop();
            if(top!=='{') return false;

        }else stack.push(char);

    }
    if(stack.length!==0) return false;
    return true;

};

/*
올바른 괄호 찾기 문제
*/
