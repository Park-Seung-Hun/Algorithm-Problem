function solution(board, moves) {
    let answer = 0;
    let stack = [];
    const N=board.length;//격자 크기

    for(let i=0;i<moves.length;i++){
        let col = moves[i]-1;
        let doll = 0;

        for(let j=0;j<N;j++){
            if(board[j][col] !=0 ){// 인형이 존재할 경우
                doll=board[j][col]; // 1. 인형을 집는다
                board[j][col]=0; // 2. 해당 격자를 비운다.
                break;
            }
        }
        if(doll !=0 ){ // 인형을 집은 경우
            if(stack.length == 0 ) stack.push(doll); // stack에 인형이 없는 경우
            else{ // stack에 인형이 있는 경우
                if(doll == stack[stack.length-1]){ // stack의 마지막 인형이 같은 인형일 때
                    stack.pop();
                    answer+=2;
                }
                else { // stack의 인형이 같은 인형이 아닐 때
                    stack.push(doll);
                }
            }
        }else{ // 인형을 못 집은 경우
            continue;
        }
    }
    return answer;
}

console.log(solution([[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4])); // 4

/*
sol. 인형 뽑기 게임으로 간단하게 stack을 이용한 구현 문제이다.
*/
