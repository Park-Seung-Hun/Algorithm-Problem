function solution(answers) {
    let answer = [];
    let cnt=[0,0,0];
    let one = [1, 2, 3, 4, 5];
    let two = [2, 1, 2, 3, 2, 4, 2, 5];
    let three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];


    for(let i=0;i<answers.length;i++){
        if(one[i%one.length] === answers[i]) cnt[0]++;
        if(two[i%two.length] === answers[i]) cnt[1]++;
        if(three[i%three.length] === answers[i]) cnt[2]++;
    }

    let max = Math.max.apply(null,cnt);
    for(let i=0;i<3;i++){
        if(max===cnt[i]) answer.push(i+1);
    }
    return answer;
}

/*
1번 2번 3번 수포자가 문제를 맞춘 개수 찾기.
Tip.
배열에서 max값: Math.max.apply(null,arr), min값: Math.min.apply(null,arr)

(배열의 크기가 ~10^7 이상이 될 경우)
배열에서 max값:
var max = array.reduce( function (previous, current) {
	return previous > current ? previous:current;
});
배열에서 min값:
var min = array.reduce( function (previous, current) {
	return previous > current ? current:previous;
});
*/
