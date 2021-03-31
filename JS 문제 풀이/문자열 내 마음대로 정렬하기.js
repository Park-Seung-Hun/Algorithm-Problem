function solution(strings, n) {
    var answer = [];

    strings.sort(function(a,b){
        var f = a[n];
        var s = b[n];

        if(f===s)return (a>b) - (a<b);
        else return (f>s) - (f<s);

    })
    answer = strings;
    return answer;
}

/*
sol. strings라는 배열을 정렬
1. strings[i]의 n번째 수를 비교
2. n번째 수가 같으면 문자열 전체 비교

if(f===s) return (a>b) - (a<b) => a>b이면 1 , a<b이면 -1 반환
else return (f>s) - (f<s); => 마찬가지로 f>s이면 1, f<s이면 -1 반환 (일반 정렬과 같다.)
*/
