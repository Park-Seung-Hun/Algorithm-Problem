function solution(n,a,b) {
    let answer = 3;
    // 1. 거듭제곱 찾기
    let p = 0;
    while(n!==0){
        n=Math.floor(n/2);
        p++;
    }
    p--;
    //console.log(p,n);
    // 2. 2^(n-1) 보다 큰지 작은지 구한다.
    while(true){
        let ref = Math.pow(2,p-1);
        //console.log(ref,a,b);
        if((a<=ref&&b<=ref)||(a>ref&&b>ref)){
            a=a%ref;
            if(a===0) a=ref;
            b=b%ref;
            if(b===0) b=ref;

            p--;
            continue;
        }
        else return p;
    }

}
