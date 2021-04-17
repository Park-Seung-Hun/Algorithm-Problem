function solution(n) {
    // 2진법 숫자 만들기
    let str_n = n.toString(2).split('').filter(function(a) {if(a==='1') return a} ).length;

    // 2진법 숫자중 1의 개수가 같은 자연수 반환
    for(let i=n+1;i<=1000000;i++){
        if(str_n===i.toString(2).split('').filter(function(a) {if(a==='1')return a}).length) return i;


    }
}
