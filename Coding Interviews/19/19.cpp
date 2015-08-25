/**
 * 顺时针打印矩阵：http://www.nowcoder.com/books/coding-interviews/9b4c81a02cd34f76be2659fa0d54342a?rp=1
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 
 */

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int row = matrix.size();//行数
        int column = matrix[0].size();//列数
        int start = 0;
        while(start*2 < row && start*2 < column){
            int endX = column - start -1;
            int endY = row - start - 1;
            // 从左到右打印一行
            for(int i = start; i <= endX; ++i)
                res.push_back(matrix[start][i]);
            // 从上到下打印一行
            for(int i = start + 1; i <= endY; ++i)
                res.push_back(matrix[i][endX]);
            // 从右到左打印一行
            if(start < endX && start < endY){
                for(int i = endX - 1; i >= start; --i)
                    res.push_back(matrix[endY][i]);
            }
            // 从下到上打印一行
            if(start < endX && start < endY - 1){
                for(int i = endY - 1; i >= start + 1; --i)
                    res.push_back(matrix[i][start]);
            }
            ++start;
        }
        return res;
    }
};