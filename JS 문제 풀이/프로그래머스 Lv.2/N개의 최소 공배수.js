function solution(arr) {
    let answer = 0;

    const gcd = function(a,b){
        if(b===0) return a;
        else return gcd(b,a%b);
    }
    const lcm = function(a,b){
        let g = gcd(a,b);
        return g*Math.floor(a/g)*Math.floor(b/g);
    }

    if(arr.length===1) return arr[0];
    else {
        let idx = 1;

        while(true){
            let l = lcm(arr[idx-1],arr[idx]);
            answer=l;
            idx++;
            if(idx===arr.length) break;
            arr[idx-1]=l;
        }
    }
    return answer;
}
