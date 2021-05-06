function solution(stones, k) {
    let answer = 0;

    const bSearch = function(left,right){
        while(left<=right){
            let mid = parseInt((left+right)/2); // 건너는 인원 수
            let length = 0;

            for(let stone of stones){
                if(stone - mid <=0) length ++; // 해당 돌이 mid보다 작거나 같아지면 => 못 건너는 디딤돌 칸수 증가
                else length=0; // 해당 돌이 mid 보다 크면 => 못 건너는 디딤돌 칸수 초기화
                if(length>=k) break; // 못 건너는 디딤돌 칸수가 k보다 크거나 같아지면 break;
            }

            if(length>=k) right=mid-1; // 못 건너는 디딤돌 칸수가 크거나 같으면 => 범위를 낮춘다.
            else left=mid+1; // 못 건너는 디딤돌 칸수가 작으면 => 범위를 늘린다.
        }
        return left;
    }

    answer = bSearch(0,200000000);
    return answer;
}
