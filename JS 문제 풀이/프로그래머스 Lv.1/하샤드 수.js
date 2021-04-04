function solution(x) {
    let answer = true;

    let num = String(x);
    let arr = num.split('').map(Number);

    const sum = arr.reduce(function add(sum, currValue) {
        return sum + currValue;
    }, 0);

    if(x%sum===0) return true;
    return false;
}
