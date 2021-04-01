function solution(bridge_length, weight, truck_weights) {

    let answer = 0;// answer: 걸린 시간
    let queue = Array.from({length:bridge_length},()=>0); // 현재 다리상태
    let currentTruck = truck_weights.shift(); // 현재 트럭의 무게
    let currentWeight = 0; // 현재 다리에 가해지는 하중

    currentWeight+=currentTruck;
    queue.unshift(currentTruck);
    queue.pop();
    answer++; // 첫 트럭이 올라감

    while(true){
        currentWeight -= queue.pop(); // 다리 이동
        currentTruck = truck_weights.shift(); // 현재 트럭의 무게

         if(currentTruck+currentWeight<=weight){ // 다리의 무게가 다리 위에 올라간 트럭의 무게보다 크거나 같은 경우
            queue.unshift(currentTruck);
            currentWeight+=currentTruck;
        }
        else{ // 다리에 새로운 트럭이 못 올라가는 경우
            queue.unshift(0); // 트럭 한칸씩 이동
            truck_weights.unshift(currentTruck);
        }
        answer++;
        if(currentWeight===0) break;
    }

    return answer;
}
