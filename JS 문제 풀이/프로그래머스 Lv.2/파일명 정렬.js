function solution(files) {
    let answer = [];
    let file = []; // [HEAD,NUMBER,TAIL,idx] 배열 넣기

    for(let i=0;i<files.length;i++){
        let arr=files[i].split('');

        let tmp='',save=[],idx=0;
        for(let j=0;j<arr.length;j++){
            if(idx===0&&(arr[j]>='0'&&arr[j]<='9')) {idx++; save.push(tmp.toLowerCase()); tmp=''; }
            else if(idx===1){
                if(!(arr[j]>='0'&&arr[j]<='9')||tmp.length===5) { save.push(parseInt(tmp)); tmp=''; break;}
            }

            tmp+=arr[j];
        }
        if(tmp!=='') save.push(parseInt(tmp));
        save.push(i);
        file.push(save);
    }
    file.sort(function(a,b){
        if(a[0]<b[0]) return -1;
        else if(a[0]===b[0]){
            if(a[1]===b[1]) return a[2]-b[2];
            return a[1]-b[1];
        }
    })
    console.log(file);
    for(let num of file){
        answer.push(files[num[2]]);
    }
    return answer;
}
