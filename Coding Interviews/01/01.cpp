class Solution {
/*
 * ��̨�ף�
 * һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
 */
public:
    int jumpFloor(int number) {
        /*
		�ݹ�棺
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