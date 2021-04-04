function solution(numbers, hand) {
    let answer = '';
    let l = [4,1];
    let r = [4,3];

    let arr = new Object();
    arr[0]=[4,2];
    arr[1]=[1,1],arr[2]=[1,2],arr[3]=[1,3];
    arr[4]=[2,1],arr[5]=[2,2],arr[6]=[2,3];
    arr[7]=[3,1],arr[8]=[3,2],arr[9]=[3,3];

    for(let num of numbers){

        if(num===1||num===4||num===7) {
            answer+='L';
            l=arr[num];
        }
        else if(num===3||num===6||num===9) {
            answer+='R';
            r=arr[num];
        }
        else{
            let dist_l = Math.abs(l[0]-arr[num][0])+Math.abs(l[1]-arr[num][1]);
            let dist_r = Math.abs(r[0]-arr[num][0])+Math.abs(r[1]-arr[num][1]);

            if(dist_l===dist_r){
                if(hand === 'right'){
                    answer+='R';
                    r=arr[num];
                }
                else{
                    answer+='L';
                    l=arr[num];
                }
            }
            else if(dist_l>dist_r){
                    answer+='R';
                    r=arr[num];

            }
            else {
                    answer+='L';
                    l=arr[num];

            }
        }
    }

    return answer;
}
