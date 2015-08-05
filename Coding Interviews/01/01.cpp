class Solution {
/*
 * 跳台阶：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
public:
    int jumpFloor(int number) {
        /*
		递归版：
		if(number <= 0){
            return 0;
        }else if(number == 1){
        	return 1;    
        }else if(number == 2){
            return 2;
        }else{
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }*/
        int res = 0;
        if(number <= 0){
            return 0;
        }
        if(number == 1){
            return 1;
        }
        if(number == 2){
            return 2;
        }
        int two = 2;
        int one = 1;
        for(int i = 3; i <= number; ++i){
            res = one + two;
            one = two;
            two = res;
        }
        return res;
    }
};