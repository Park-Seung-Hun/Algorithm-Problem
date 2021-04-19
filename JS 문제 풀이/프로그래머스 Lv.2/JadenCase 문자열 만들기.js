function solution(s) {
    var answer = '';
    var arr = [];

    arr=s.split(' ');
    console.log(arr);
    answer = arr.map(str=> (str === '') ? '' : str.toLowerCase())
      .map(str=> (str === '') ? '' : str.replace(str[0], str[0].toUpperCase()))
      .join(' ');
    return answer;
}
