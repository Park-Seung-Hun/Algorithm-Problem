function checkStr(str){
    let arr = [];

    for(let i of str){
        if(arr.length!==0){
            if(arr[arr.length-1]==='('&&i===')') arr.pop();
            else arr.push(i);
        }
        else arr.push(i);
    }

    if(arr.length===0) return true;
    else return false;
}

function algorithm(input){
    if(input.length===0) return '';

    let u="";
    let v="";
    let cnt=0;let check=false;
    // 조건 1. 문자열 w를 두 균형잡힌 문자열 u,v로 분리
    for(let char of input){
        if(check) {
            v+=char;
            continue;
        }

        if(char ===')') cnt++;
        u+=char;
        if(2*cnt===u.length) check=true;
    }
    console.log(`${u},${v}`);

    // 조건 2. 문자열 u 가 올바른 괄호 문자열인 경우 v에 대해 1단계부터 다시 수행
    if(checkStr(u)){
        return u+algorithm(v);
    }
    // 조건 3. 문자열 u 가 올바른 괄호 문자열이 아닌 경우
    else {
        let str = '(';
        str+=algorithm(v);
        str+=')';

        for(let i=1;i<u.length-1;i++){
            if(u[i]==='(') str+=')';
            else str+='(';
        }
        return str;
    }

}
function solution(p) {
    let answer = '';
    console.log(algorithm(p));
    answer = algorithm(p);
    return answer;
}

// 균형잡힌 괄호 문자열 : ()개수가 같으면
// 올바른 괄호 문자열: 균형잡힌 괄호 문자열에 짝도 맞는 경우
