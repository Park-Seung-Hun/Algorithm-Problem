function solution(s) {
    let answer = [];
    // 1. s를 길이로 정렬한다.
    let arr = s.split('}');
    arr.pop();arr.pop();

    for(let i =0;i<arr.length;i++){
        arr[i]=arr[i].substr(2);
    }
    arr = arr.sort(function (a,b){
        if(a.length < b.length) return -1;
        if(a.length===b.length) return 0;
        if(a.length>b.length) return 1;
    })

    // 2. 각 요소마다 존재하지 않는 요소를 삽입
    console.log(arr[0].split(','));
    let map =new Map();

    for(let i=0;i<arr.length;i++){
        let check = arr[i].split(',');
        for(let j of check){
            if(!map.has(j)){
                map.set(j,true);
                answer.push(parseInt(j));
            }
        }
    }

    return answer;
}
