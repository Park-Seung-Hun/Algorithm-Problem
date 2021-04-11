function solution(n, arr1, arr2) {
    var answer = [];

    for(let i=0;i<arr1.length;i++) {
        let tmp = arr1[i]|arr2[i];
        tmp = tmp.toString(2);
        let ans='';

        // 앞자리 0인 경우
        console.log(n-tmp.length , tmp)
        for(let len=0;len<n-tmp.length;len++){
            ans+=' ';
        }

        // 이진 계산한 값
        for(let len=0;len<tmp.length;len++){
            if(tmp[len]==='0') ans+=' ';
            else ans+='#';
        }
        answer.push(ans);
    }
    return answer;
}

/*
비트연산자 생각하기!
Number.toString(진법) => 진법 변환된 String 반환
*/
