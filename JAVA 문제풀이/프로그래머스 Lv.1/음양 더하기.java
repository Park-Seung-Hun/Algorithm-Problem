class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        // signs가 true이면 플러스
        // signs가 false면 마이너스

        for(int i=0;i<signs.length;i++){
            if(!signs[i]){
                answer+= -absolutes[i];
            }
            else{
                answer+=absolutes[i];
            }
        }

        return answer;
    }
}
