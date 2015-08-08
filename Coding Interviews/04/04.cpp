/*
 * 二维数组中的查找：http://www.nowcoder.com/books/coding-interviews/abc3fe2ce8e146608e868a70efebf62e?rp=1
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int rows = array.size();
        int columns = array[0].size();
        int row = 0;
        int col = columns - 1;
        while( row < rows &&  col >= 0){
            if(array[row][col] == target){
                return true;
            }else if(array[row][col] < target){
                ++row;
            }else{
                --col;
            }
        }
        return false;
    }
};