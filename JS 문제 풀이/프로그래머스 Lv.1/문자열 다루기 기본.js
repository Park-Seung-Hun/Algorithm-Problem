function solution(s) {
    var answer = true;
    if(s.length===4 ||s.length === 6){
        for(let char of s){
            if(!(char>=0&&char<=9))return false;
        }
        return true;
    }
    else return false;
}
