function solution(n, lost, reserve) {
    let answer = 0;
    let student = [];

    for(let i=0;i<n;i++) student.push(1);
    for(let reserve_num of reserve) student[reserve_num-1]++;
    for(let lost_num of lost) student[lost_num-1]--;

    for(let i=0;i<n;i++){
        if(student[i]===0){ // 체육복이 없는 친구
            if(i===0){ // 제일 첫번째 학생일 때
                if(student[i+1]===2){
                    student[i]++;
                    student[i+1]--;
                }
                else answer++;
            }
            else if(i===n-1){ // 제일 마지막 학생일 때
                if(student[i-1]===2){
                    student[i]++;
                    student[i-1]--;
                }
                else answer++;
            }
            else{ // 나머지 학생
              // 앞에 있는 친구를 먼저 확인 하는 것(그리디)
                if(student[i-1]===2){
                    student[i]++;
                    student[i-1]--;
                }
                else if(student[i+1]===2){
                    student[i]++;
                    student[i+1]--;
                }
                else answer++;
            }
        }
    }
    answer = n-answer;
    return answer;
}

// 바로 앞번호나 뒷번호 학생만 빌려줄 수 있다.
