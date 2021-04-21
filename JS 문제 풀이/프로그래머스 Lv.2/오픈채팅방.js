function solution(record) {
    let answer = [];
    let ans=[];
    let name = {};

    for(let i=0;i<record.length;i++){
        // 명령어 자르기
        let arr = record[i].split(' ');

        if(arr[0]==='Enter'){
            name[arr[1]]=arr[2];
            answer.push([arr[1],0]);
        }
        else if(arr[0]==='Leave'){
            answer.push([arr[1],1]);
        }
        else {
            name[arr[1]]=arr[2];
        }
    }

    for(let i=0;i<answer.length;i++){
        if(answer[i][1]===0){
            ans.push(`${name[answer[i][0]]}님이 들어왔습니다.`);
        }else{
            ans.push(`${name[answer[i][0]]}님이 나갔습니다.`);
        }
    }

    return ans;
}

/*단순 구현*/
