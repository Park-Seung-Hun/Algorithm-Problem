function solution(str1, str2) {
    var answer = 0;
    str1=str1.toLowerCase();
    str2=str2.toLowerCase();

    // 두 문장에서 특수기호를 빼고 길이 2짜리 문자열로 만들기
    let A=[];
    let B=[];
    for(let i=0;i<str1.length-1;i++){
        if(str1[i]>='a'&&str1[i]<='z'&&str1[i+1]>='a'&&str1[i+1]<='z')
            A.push(str1.substr(i,2));
    }
    for(let i=0;i<str2.length-1;i++){
        if(str2[i]>='a'&&str2[i]<='z'&&str2[i+1]>='a'&&str2[i+1]<='z')
            B.push(str2.substr(i,2));
    }


    let parent = A.length+B.length;
    // 1. 두 집합의 교집합 크기
    let son = 0;
    for(let num of A){
        if(B.length===0) break;
        if(B.includes(num)){
            B.splice(B.indexOf(num),1);
            son++;
        }
    }
    // 2. 두 집합의 합집합 크기
    parent-=son;

    if(parent===0&&son===0) return 65536;
    answer = parseInt(son/parent*65536);
    return answer;
}

/*
자카드 유사도 J(A,B) = 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값
*/
