import java.util.Arrays;
import java.util.Objects;

class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int leftr = 1,lefth = 3;
        int rightr = 3, righth = 3;

        for(int i=0;i<numbers.length;i++){

            if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
                answer+='L';
                leftr = 1;
                lefth=numbers[i]/3;
            }
            else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
                answer+='R';
                rightr = 3;
                righth = (numbers[i]/3)-1;
            }
            else{
                if(numbers[i]==0) numbers[i]=9;
                int left_len = Math.abs(leftr-2)+Math.abs(lefth-numbers[i]/3);
                int right_len = Math.abs(rightr-2)+Math.abs(righth-numbers[i]/3);

                if(left_len>right_len){
                    answer+='R';
                    rightr=2;
                    righth=numbers[i]/3;
                }
                else if(left_len<right_len){
                    answer+='L';
                    leftr=2;
                    lefth=numbers[i]/3;
                }
                else{
                    if(Objects.equals(hand,"right")){
                        answer+='R';
                        rightr=2;
                        righth=numbers[i]/3;
                    }
                    else if(Objects.equals(hand,"left")){
                        answer+='L';
                        leftr=2;
                        lefth=numbers[i]/3;
                    }
                }
            }
        }
        return answer;
    }
}

// System.out.print
