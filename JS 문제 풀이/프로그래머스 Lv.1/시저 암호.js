function solution(s, n) {
    let answer = '';
    for(let idx in s){
        if(s[idx]>='a'&&s[idx]<='z'){
            answer+= String.fromCharCode((s.charCodeAt(idx)-97+n)%26+97);
        }
        else if(s[idx]>='A'&&s[idx]<='Z'){
            answer+= String.fromCharCode((s.charCodeAt(idx)-65+n)%26+65);
        }
        else{
            answer+=s[idx];
        }
    }
    return answer;
}

/*
Tip.
str.charCodeAt(idx) => 문자열에서 idx에 있는 문자의 아스키 코드 출력
String.fromCharCode(아스키 코드) => 아스키 코드를 문자로 바꿔준다.
*/
