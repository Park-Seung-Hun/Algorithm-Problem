/*
어쩃든 해당 방식으로 가게 된다면 최소 값으로 변할 수 있기 때문에.
idx=0인 경우 k만큼 더 해준다.
idx!=0인 경우 k-1만큼 더 해준다.

입력
4 2
1 2 3 4
*/
const solution = (n,k,arr)=>{
	let idx = 0;
	let ans = 0;
	while(true){
		if(idx>=n)break;
		else if(idx===0) idx+=k;
		else idx+=k-1;

		ans++;
	}

	console.log(ans);
};


const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let cnt = 0;
const check = [];
const num = [];

rl.on("line", function(line) {
	if(check.length!==1) check.push(line);
	else {
		num.push(line);
	}

	if(num.length!==0) rl.close();
}).on("close", function() {
	let t = check[0].split(' ').map(Number);
	let q = num[0].split(' ').map(Number);

	//console.log(t,q);
	solution(t[0],t[1],q);
	process.exit();
});
