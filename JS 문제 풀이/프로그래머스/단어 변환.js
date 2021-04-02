function checkStr(str1,str2){
    let cnt=0;
    for(let i=0;i<str1.length;i++){
        if(str1[i]!==str2[i]) cnt++;
    }

    if(cnt===1) return true;
    else return false;

}
function solution(begin, target, words) {
    let answer = 987654321;
    if(!words.includes(target)) return 0;

    let check = Array.from({length: words.length},()=>false);
    const dfs = function(str,tg,cnt){
        if(str===tg){
            if(cnt<answer) answer=cnt;
            return;
        }

        for(let i=0;i<words.length;i++){
            if(checkStr(str,words[i])&&check[i]===false){
                check[i]=true;
                dfs(words[i],tg,cnt+1);
                check[i]=false;
            }
        }
    }

    dfs(begin,target,0);

    if(answer===987654321) answer=0;
    console.log(answer);

    return answer;
}
