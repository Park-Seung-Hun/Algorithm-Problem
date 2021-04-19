function solution(arr1, arr2) {
    let answer = new Array(arr1.length).fill(null).map(()=>new Array(arr2[0].length).fill(0));
    console.log(answer);

    for(let i=0;i<arr1.length;i++){

        for(let k=0;k<arr2[0].length;k++){
            let tmp=0;
            for(let j=0;j<arr1[i].length;j++){

                tmp+=arr1[i][j]*arr2[j][k];
            }
            answer[i][k]=tmp;
        }
    }


    return answer;
}
