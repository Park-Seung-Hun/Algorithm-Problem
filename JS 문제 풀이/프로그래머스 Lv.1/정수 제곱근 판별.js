function solution(n) {
    let answer = 0;
    let ref = parseInt(Math.sqrt(n));

    if(ref*ref===n) return (ref+1)*(ref+1);
    else return -1;
}
