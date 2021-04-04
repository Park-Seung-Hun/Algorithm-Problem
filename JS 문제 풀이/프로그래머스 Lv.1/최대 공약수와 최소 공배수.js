function solution(n, m) {
    let answer = [];

    const gcd = function(a,b){
        if(b===0) return a;
        else return gcd(b,a%b);
    }
    const lcm = function(a,b){
        let g=gcd(a,b);
        return g*parseInt(a/g)*parseInt(b/g);
    }

    answer.push(gcd(n,m),lcm(n,m));
    return answer;
}
