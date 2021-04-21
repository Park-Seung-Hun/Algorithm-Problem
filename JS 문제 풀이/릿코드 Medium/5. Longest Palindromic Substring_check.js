/**
 * @param {string} s
 * @return {string}
 */

 // 1. DP를 사용하지 않고 풀이. (완전탐색)
var longestPalindrome = function(s) {
    let init_len = s.length;

    // 펠린드롬 판별 함수
    const is_p = function(str){
        if(str===str.split('').reverse().join('')) return true;
        return false;
    }

    // 가장 긴 부분 문자열부터 검사
    for(let len = 0; len<init_len;len++){
        for(let idx = 0; idx<=len;idx++) {

            // 가장 긴 부분 문자열의 양 끝 문자가 같다.
            // idx부터 init_len-len+idx 길이 만큼의 부분 문자열이 펠린드롬인지 확인.
            if(s[idx]===s[init_len-len+idx-1]&&is_p(s.slice(idx,init_len-len+idx))){
                return s.slice(idx,init_len-len+idx);
            }
        }
    }

    return answer;
};

// 2. DP를 사용하여 풀이.
var longestPalindrome = function(s) {
  // dp[i][j] => i부터 j까지의 부분문자열이 펠린드롬 문자열.
    let len = s.length,
        dp = new Array(len).fill(null).map(x => new Array(len).fill(false)),
        lps = '';

    // 길이가 1인 부분 문자열 펠린드롬 체크
    for (let i = 0; i < len; i ++) {
        dp[i][i] = true;
        lps = s.slice(i, i + 1)
    }

    // 길이기 2인 부분 문자열 펠린드롬 체크
    for (let i = 0; i < len; i ++) {
        if (s[i] === s[i + 1]) dp[i][i+1] = true;
        if(dp[i][i+1]) lps = s.slice(i, i + 2)
    }

    // 길이가 3 이상인 부분 문자열 펠린드롬 체크
    for (let i = len - 1; i >= 0; i --) {
        for (let j = i + 2; j < len; j ++) {
            dp[i][j] = dp[i+1][j-1] && s[i] === s[j];
            if(dp[i][j]) lps = lps.length < (j - i+ 1) ? s.slice(i, j + 1) : lps;
        }
    }
    return lps;
};
