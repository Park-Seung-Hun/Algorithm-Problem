/*
Java의 Stack을 사용해보자
*/
import java.util.Stack;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();

        for(int value:moves){
            int col = value-1;
            int doll=0;

            for(int i=0;i<board.length;i++){
                if(board[i][col]!=0){
                    doll=board[i][col];
                    board[i][col]=0;
                    break;
                }
            }

            if(doll!=0){
                if(stack.size()==0){
                    stack.push(doll);
                }
                else{
                    if(stack.peek()==doll){
                        stack.pop();
                        answer++;
                    }
                    else{
                        stack.push(doll);
                    }
                }
            }
        }

        return answer*2;
    }
}
