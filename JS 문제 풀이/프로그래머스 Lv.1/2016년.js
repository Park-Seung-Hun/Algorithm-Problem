function check(t) {
	if (t === 0) return "THU";
	else if (t === 1) return "FRI";
	else if (t === 2) return "SAT";
	else if (t === 3) return "SUN";
	else if (t === 4) return "MON";
	else if (t === 5) return "TUE";
	else if (t === 6) return "WED";
}
function sum(mon, day) {
	let tmp = 0;
	if (mon == 1) return day;

	for (let i = 1; i < mon; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			tmp += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			tmp += 30;
		}
		else tmp += 29;
	}
	tmp += day;
	return tmp;
}


function solution(a, b) {
    let answer = check(sum(a,b)%7);
    return answer;
}

// 단순 구현문제
