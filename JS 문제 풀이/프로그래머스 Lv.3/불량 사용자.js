function solution(user_id, banned_id) {
    let answer = 0;

    /*
        풀이 ?
        1. 제재 아이디를 전체 확인
        2. 제재 아이디와 맞는 유저 아이디를 찾아 넣기 => 2중 for문
    */
    let ans = [];
    for(let ban of banned_id){
        let tmp = [];
        for(let user of user_id){

            if(user.length!==ban.length) continue; // 유저 아이디와 제재 아이디의 길이가 다르면 체크하지 않음

            let flag = false; // 제재 대상인지 확인하는 flag
            for(let idx in user){
                if(ban[idx]==='*') continue; // * 모양인 경우

                if(user[idx]!==ban[idx]) { // 제재 아이디랑 다를 경우
                    flag=true;
                    break;
                }
            }

            if(!flag) tmp.push(user); // 제재아이디와 같은 경우
        }
        ans.push(tmp);
    }

    // backTracking 을 통해 경우의 수를 찾는다.
    let save = [];
    let check = {};
    const backTracking = function(len){
        if(len===ans.length){
            let save_copy =[...save];
            save_copy.sort();
            if(!(save_copy in check)){ check[save_copy]=1; answer++;}
            return;
        }

        for(let i=0;i<ans[len].length;i++){
            if(save.includes(ans[len][i])) continue; // 중복으로 제재된 아이디가 존재하는 경우
            save.push(ans[len][i]);
            backTracking(len+1);
            save.pop();
        }
        return;
    }
    backTracking(0);
    return answer;
}

/*
1. 유저 아이디는 서로 중복이 안됨 , 알파벳 소문자.숫자로만 이루어짐
2. 제재 아이디는 알파벳 소문자 숫자 *로 이루어짐.
제재 아이디 하나는 응모자 아이디 중 하나에 해당하고 중복해서 제재 아이디 목록에 들어가는 경우는 없음
*/
