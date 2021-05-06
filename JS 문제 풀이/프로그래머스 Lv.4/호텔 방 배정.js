

function solution(k, room_number) {
    let answer = [];
    let room = new Map(); // 현재 방은 배정받지 않은 상황

    const findRoom = function(room_num){
        if(!(room.has(room_num))){//  현재 방이 배정받지 않은 경우
            room.set(room_num,room_num+1);
            return room_num;
        }

        // 현재 방이 배정받은 경우
        let t = findRoom(room.get(room_num));
        room.set(room_num,t+1);
        return t;
    }
    for(let i=0;i<room_number.length;i++){
        let check = findRoom(room_number[i],i+1);
        answer.push(check);
    }

    return answer;
}

/*
Map의 힘을 생각하자
*/
