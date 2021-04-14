function solution(arr) {
    var answer = [];

    let ans_one=0;
    let ans_two=0;

    const quad = function(sx,sy,ref,len){
        // 1. sx부터 시작해서 sy까지 체크

        let check=false;
        for(let i=sx; i<sx+len;i++){
            for(let j=sy;j<sy+len;j++){
                if(ref!==arr[i][j]){
                    let len_ref=Math.floor(len/2);

                    check=true;

                    quad(sx,sy,arr[sx][sy],len_ref);
                    quad(sx+len_ref,sy,arr[sx+len_ref][sy],len_ref);
                    quad(sx,sy+len_ref,arr[sx][sy+len_ref],len_ref);
                    quad(sx+len_ref,sy+len_ref,arr[sx+len_ref][sy+len_ref],len_ref);
                    return;
                } // 다른 값이 나올 경우
            }
        }

        if(!check){

            if(ref===1) ans_one++;
            else ans_two++;
        }
        return;
    }

    quad(0,0,arr[0][0],arr.length);

    console.log(ans_one,ans_two);
    return [ans_two,ans_one];
}

/*
각 각의 경우마다 backtracking을 이용해 유망한 노드만 체크한다.
*/
