/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let left =0 ,right = 0;
    let check = [];

    let ans = 0;
    while (left < s.length && right < s.length) {

        // check배열에 s[right]가 포함 되어 있는 경우
        while (check.includes(s[right])) {

            // check배열에서 s[i]를 제거하고 왼쪽 값을 증가
            check.splice(check.indexOf(s[left]), 1);
            left++;
        }

        // check배열에 문자열의 문자를 넣는다.
        check.push(s[right]);
        right++;
        ans = Math.max(ans, right - left);
    }
    return ans;
}

/* 투포인터? */
