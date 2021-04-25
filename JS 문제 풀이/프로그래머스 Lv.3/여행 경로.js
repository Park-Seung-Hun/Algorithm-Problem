function solution(tickets) {
    // 1. tickets를 알파벳 순으로 정렬하기
    tickets.sort();

    let arr = [],ans = [],Max=0;
    let visited = new Array(10000).fill(false);

    // DFS를 이용해 정리하기
    const dfs = function(start,cnt){
        arr.push(start);

        if(Max<cnt){
            Max=cnt;
            ans=[...arr];
        }

        for(let i=0;i<tickets.length;i++){
            if(start===tickets[i][0]&&visited[i]==false){
                visited[i]=true;
                dfs(tickets[i][1],cnt+1);
                visited[i]=false;
            }
        }
        arr.pop();
    }

    dfs("ICN",0);
    return ans;
}
