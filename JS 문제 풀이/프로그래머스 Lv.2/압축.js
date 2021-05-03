function solution(msg) {
    let answer = [];
    let arr = msg.split(''),i=0;

    // 알파벳 초기화
    let alpha = {};
    let idx=0;
    for(i=65;i<=90;i++){
        let tmp = String.fromCharCode(i);
        alpha[tmp]=++idx;
    }

    // arr을 돌아가며 확인한다 이때 해당 알파벳이 존재하면 다음 알파벳을 합쳐 글자를 만든 다음에 추가한다.
    let w='',check={};
    for(i=0;i<arr.length;i++){
        w+=arr[i]; // w에 문자 추가
        if(i+1!==arr.length && !((w+arr[i+1]) in alpha)){ // w+c가 사전에 포함 되어있지 않으면.
            alpha[w+arr[i+1]]=++idx; // 사전에 추가 후 이전 w를 정답에 포함시킨후 제거한다.
            answer.push(alpha[w]);
            w='';
        }
    }
    if(!(w in alpha)) alpha[w]=++idx;
    answer.push(alpha[w]);
    console.log(answer);


    return answer;
}
