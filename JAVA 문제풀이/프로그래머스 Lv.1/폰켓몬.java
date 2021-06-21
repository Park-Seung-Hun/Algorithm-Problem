import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        /*
            폰켓몬 n마리중 n/2 마리를 가져갈 수있다.
            각 폰켓몬은 번호가 주어짐
            가질수 있는 폰켓몬의 종류의 수
        */
        HashSet<Integer> set = new HashSet<Integer>();

        for(int i=0;i<nums.length;i++){
            set.add(nums[i]);
        }

        if(nums.length/2>=set.size()){
            answer=set.size();
        }else{
            answer=nums.length/2;
        }
        System.out.println(set.size());

        return answer;
    }
}
