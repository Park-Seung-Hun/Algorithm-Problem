function solution(n, weak, dist) {
    if(weak.length===1) return 1;

    let answer = 10;
    let permutation = [];
    let arr = [...weak];

    /* 순열 구하기 */
    const getPermutation = function (arr, selectNum) {
        let result = [];
        if (selectNum === 1) return arr.map((v) => [v]);

        arr.forEach((v, idx, arr) => {
            const fixer = v;
            const restArr = arr.filter((_, index) => index !== idx);
            const permuationArr = getPermutation(restArr, selectNum - 1);
            const combineFixer = permuationArr.map((v) => [fixer, ...v]);
            result.push(...combineFixer);
        });
        return result;
    }

    /* 친구들을 선택해서 나열하는 방법 (순열) */
    for (let i=1; i<=dist.length; i++) {
        const permu = getPermutation(dist, i);
        permutation = permutation.concat(permu);
    }

    /* 각각의 방법에 대해 취약지점을 모두 점검할 수 있는지 확인. */
    for (let i=0; i<weak.length; i++) {

        for (const value of permutation) {
            const selected = [...value];
            const wall = [...arr];

            // 가장 앞의 weak 지점 뽑기
            let now = wall.shift();


            while (selected.length) {
                if (wall[0] - now <= selected[0]) {
                // 현재 있는 지점과 점검할 지점의 거리가 친구가 점검할 수 있는 거리보다 작거나 같은 경우 => 다음 벽으로 이동
                    wall.shift();
                } else {
                // 현재 있는 지점과 점검할 지점의 거리가 친구가 점검할 수 있는 거리보다 큰 경우 => 현재 벽에서 멈추고 다음 친구를 불러온다.
                    now = wall[0];
                    selected.shift();
                }
            }

            if (wall.length === 0) { // 벽을 모두 점검한 경우 => 점검해준 친구들의 최소 값을 구한다.
                if (answer > value.length) answer = value.length;
            }
        }

        /* 다음 벽의 순서로 이동 => [1, 3, 4, 9, 10] -> [3, 4, 9, 10, 13] */
        arr.push(arr.shift() + n);
    }

    return answer === 10 ? -1 : answer;
}
/*


*/
