function solution(n, words) {
    let answer = [];
    let num=0 ,cycle=0;
    let check = {};
    let tmp = words[0].split('')[0];

    for(let i=0;i<words.length;i++){
        if(words[i] in check||tmp!==words[i].split('')[0]){
            cycle=Math.floor(i/n)+1;
            num=i%n+1
            break;
        }
        else{
            tmp=words[i].split('')[words[i].length-1];
            check[words[i]]=1;
        }
    }

    //console.log(num,cycle);
    answer.push(num,cycle);
    return answer;
}
