/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let arr = s.split('');
    let ref;
    let ans=0;

    for(let i=0;i<s.length;i++){
        if(s[i]==='V') {
            if(ref==='I') {ans+=3; ref='';}
            else ans+=5;
        }
        else if(s[i]==='X'){
            if(ref==='I') {ans+=8; ref='';}
            else ans+=10;
        }
        else if(s[i]==='L') {
            if(ref==='X'){ans+=30; ref='';}
            else ans+=50;
        }

        else if(s[i]==='C') {
            if(ref==='X'){ans+=80; ref='';}
            else ans+=100;
        }
        else if(s[i]==='D') {
            if(ref==='C'){ans+=300; ref='';}
            else ans+=500;
        }
        else if(s[i]==='M') {
            if(ref==='C'){ans+=800; ref='';}
            else ans+=1000;
        }
        else if(s[i]==='I') ans+=1;
        else if(s[i]==='X') ans+=10;
        else if(s[i]==='C') ans+=100;

        ref=s[i];
    }
    console.log(ans);
    return ans;
};

/*
입력 로마 표기법 문자열 s를 숫자로 바꾸기
*/
