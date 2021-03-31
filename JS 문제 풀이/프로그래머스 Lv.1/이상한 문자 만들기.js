function solution(s) {
    var answer = '';
    let arr = s.split(' ');
    let arr2 = [];
    for(let str of arr){
        let tmp = '';
        for(let idx in str){
            if(idx%2===0){
                tmp+=str[idx].toUpperCase();
            }
            else{
                tmp+=str[idx].toLowerCase();
            }
        }
        arr2.push(tmp);
    }
    answer=arr2.join(' ');
    return answer;
}
