function solution(numbers) {
    var answer = '';
    numbers = numbers.map(num=>num+"").sort(function (a,b){
        return (b+a)-(a+b);
    });
    answer = numbers.join('');
    for(let char of answer){
        if(char!=="0") {
           return answer;
        }
    }
    return '0';
}
