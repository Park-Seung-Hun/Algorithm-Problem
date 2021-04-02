function solution(s) {
    let arr = [];
    // 문자열 크기의 절반 수까지 i개 단위로 압축
    for(let i=1; i<= parseInt(s.length/2); i++){
        // 0부터 i개의 문자가 첫 번째 압축 문자
        let str = s.substr(0,i);
        let cnt = 1;

        for (let j=i; j<= s.length-i; j=j+i){
            // 압축 가능한 문자열.
            if (s.substr(j-i,i) === s.substr(j,i)){
                cnt++;
                // 끝까지 간경우
                if(s.length-j-i<i){
                    str+= cnt;
                }
            }
            // 압축 가능하지 않은 문자열.
            else{
                if (cnt !== 1){
                    str+= cnt;
                    str+=s.substr(j,i);
                }else{
                    str+=s.substr(j,i);
                }
                cnt = 1;
            }
        }
        // 남은 문자열은 압축할 수 없으므로 그대로 붙이기
        str+=s.substr(s.length-1-(s.length % i), (s.length % i));
        arr.push(str);
    }

    arr = arr.map(Str => Str.length);
    arr.sort(function (a,b){
        if(a<b) return -1;
        if(a===b)return 0;
        if(a>b)return 1;
    });
    console.log(arr);

    let answer=arr[0];
    if(parseInt(s.length/2) === 0) answer =1;
    return answer;
}
