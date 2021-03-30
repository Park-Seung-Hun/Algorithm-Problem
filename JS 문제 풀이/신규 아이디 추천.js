function solution(new_id) {
    let answer = '';
    let check=[]
    // 1. 모든 대문자를 소문자로 치환한다.
    new_id = new_id.toLowerCase();

    // 2. 알파벳 소문자, 숫자, - _ . 를 제외한 모든 문자 제거
    for(let i=0;i<new_id.length;i++){
        if(new_id[i]>='a'&&new_id[i]<='z') check.push(new_id[i]);
        else if(new_id[i]>='0'&&new_id[i]<='9') check.push(new_id[i]);
        else if(new_id[i]==='-'||new_id[i]==='_') check.push(new_id[i]);
        else if(new_id[i]==='.'&&check[check.length-1] !== '.'){ // 3. .가 2번이상 연속된 부분을 하나의 .로 치환(스택 이용)
            check.push(new_id[i]);
        }
    }

    // 4. new_id의 처음이나 끝에 . 가 존재하면 제거
    if(check[0] === '.') check.shift();
    if(check.lengt!==0 && check[check.length-1] ==='.') check.pop();

    // 5. new_id가 빈 문자열이면 "a"
    if(check.length===0) check.push('a');

    new_id = check.join('');
    // 6. new_id가 16자 이상 첫 문자에서 15개 문자(줄인 id 맨 뒤에 .이면 제거)
    if(new_id.length > 15){
        if(new_id[14]!=='.')new_id = new_id.slice(0,15);
        else new_id=new_id.slice(0,14);
    }
    // 7. new_id가 2자 이하 new_id의 마지막 문자를 3이 될때까지 붙인다.
    if(new_id.length<=2){
        let char = new_id[new_id.length-1];
        while(new_id.length!==3){
            new_id+=char;
        }
    }
    answer = new_id;
    return answer;
}

/*
sol. 문제의 조건에 따라 단순 구현.

Tip.
1. 모든 문자 대문자 str.toUpperCase(), 소문자 str.toLowerCase();
2. 배열의 맨 앞 요소 제거: arr.shift(), 맨 뒤 요소 제거: arr.pop()
3. 배열을 문자열로 만들기(배열 요소 사이에 넣을 문자열 생성 가능): str = arr.join('');
4. 문자열 자르기: str.slice(시작 지점,길이);
5. 문자열 뒤에 문자열 추가: str+= str1;, 앞에 문자열 추가: str = str1 + str;  
*/
