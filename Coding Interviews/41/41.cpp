/**
 * 和为S的连续正数序列：http://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 * 
 */
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum<3)
            return res;
        int small = 1, big = 2,tempSum=3;
        while (small < sum / 2)
        {
            if (tempSum == sum)
            {
                vector<int> temp;
                for (int i = small; i <= big; ++i)
                {
                    temp.push_back(i);
                }
                res.push_back(temp);
                big++;
                tempSum += big;
            }
            else if (tempSum < sum)
            {
                big++;
                tempSum += big;
            }
            else
            {
                tempSum -= small;
                small++;
            }
        }
        if (tempSum == sum)//如果最后一组数和为sum
        {
            vector<int> temp;
            for (int i = small; i <= big; ++i)
            {
                temp.push_back(i);
            }
            res.push_back(temp);
        }
        return res;
    }

};