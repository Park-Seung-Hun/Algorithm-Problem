function solution(land) {
    let answer = 0;

    let arr = [];
    for(let idx =0;idx<land.length;idx++ ){
        arr.push(Array.from({length: land[0].length},()=>0));
    }
    arr[0]=land[0];
    // 땅따먹기 => 같은 열을 밟을 수 없다.
    for(let i=1;i<land.length;i++){
        for(let j=0;j<4;j++){
            if(j===0){
                arr[i][j]=Math.max(arr[i-1][1]+land[i][j],arr[i-1][2]+land[i][j],arr[i-1][3]+land[i][j]);
            }
            else if(j===1){
                arr[i][j]=Math.max(arr[i-1][0]+land[i][j],arr[i-1][2]+land[i][j],arr[i-1][3]+land[i][j]);

            }
            else if(j===2){
                arr[i][j]=Math.max(arr[i-1][0]+land[i][j],arr[i-1][1]+land[i][j],arr[i-1][3]+land[i][j]);
            }
            else if(j===3){
                arr[i][j]=Math.max(arr[i-1][0]+land[i][j],arr[i-1][1]+land[i][j],arr[i-1][2]+land[i][j]);
            }

    }}

    answer = Math.max.apply(null,arr[arr.length-1]);
    return answer;
}

/*
시간초과는 DP로 해결!
js에서 2차원 배열 설정시 위와 같이.
*/
