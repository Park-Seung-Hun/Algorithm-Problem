/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length===0) return '';
    if(strs.length===1) return strs[0];

    // 1. strs를 길이순으로 정렬
    strs.sort(function (a,b){
        return a.length-b.length;
    })

    let ans='';
    // 2. 체크
    for(let len = 1;len<=strs[0].length;len++){
        let check=false;

        for(let i=1;i<strs.length;i++){
            if(strs[i-1].substr(0,len)!==strs[i].substr(0,len)){
                check=true;
                break;
            }
        }
        if(!check){
            ans= strs[0].substr(0,len);
        }
    }

    return ans;
};

/*
가장 긴 공통 prefix를 구하는 문제.
단순 구현 및 완전 탐색 
*/
