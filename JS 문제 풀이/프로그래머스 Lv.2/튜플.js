function solution(s) {
    let answer = [];
    /* 문자열 s를 구분하기 */
    let ans = [];
    for(let i=1;i<s.length-1;i++){
        let char = s[i];

        if(s[i]==='{'){
            let idx = s.indexOf('}',i);
            let arr = s.slice(i+1,idx).split(',');
            ans.push(arr);
            i=idx;
        }
    }

    ans.sort((a,b)=> a.length-b.length);
    /* ans를 set에 넣기 */
    let set = new Set();
    for(let a of ans){
        for(let b of a){
            set.add(Number(b));
        }
    }

    return [...set];
}
