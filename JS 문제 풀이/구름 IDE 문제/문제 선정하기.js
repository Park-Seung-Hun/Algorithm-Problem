/*
단순히 중복을 제외한 나머지 숫자가 3개 이상인지 확인하는 문제.
=> 조합을 사용하는 줄 알았으나 그건 아니였다네.

입력
6
3 1 4 1 5 9
*/
const solution = (n,num)=>{

    let set = new Set(num);
    let size = set.size;

    if(size<3){
      console.log("NO");
    }
    else{
      console.log("YES");
    }
}

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let N = null;
let count = 0;
const data = [];

rl.on('line', function (line) {
  if (!N) {
    N = +line;
  } else {
    data.push(line);
    count += 1; // data를 입력받으면 count를 증가시켜주고
  }
  if(data.length===N)rl.close();
}).on('close', function () { // rl.close()를 호출하면 이 콜백함수로 들어오고
	let problem = data[0].split(' ').map(Number);

	solution(N,problem)
  process.exit(); // 프로세스를 종료한다.
});
