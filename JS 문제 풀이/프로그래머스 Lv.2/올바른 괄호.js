function solution(s){
    let arr = s.split('');
    let ref = 0;

    for(let char of arr){
        if(char === ')'){
            if(ref===0) return false;
            ref--;
        }
        else{
            ref++;
        }
    }
    if(ref!==0) return false;
    return true;
}

/*
시간 초과가 날 경우 queue를 만들어서 shift(), push() 연산을 하지 말고,
다른 flag를 사용해서 체크한다.
*/
