/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    a=a.split('');
    b=b.split('');

    let ans=[];
    let a_num,b_num;
    let tmp=0;

    while(true){
        if(a.length!==0)a_num = Number(a.pop());
        else a_num = 0;
        if(b.length!==0) b_num = Number(b.pop());
        else b_num = 0;

        let check = a_num+b_num+tmp;
        tmp=Math.floor(check/2);
        check=check%2;

        ans.unshift(check);
        if(a.length===0&&b.length===0&&tmp===0) break;
    }
    console.log(ans.join(''));

    return ans.join('');
};

/*
이진수 더하기 연산
*/
