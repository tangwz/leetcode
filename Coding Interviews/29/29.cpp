/**
 * 最小的K个数：http://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?rp=2&ru=/ta/coding-interviews
 *
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
 */
class Solution {
public:
    // 一种简单的方法，就是直接排序，取最小的k个
    // 但是这样会打乱元素顺序
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() < k) return res;
        // 使用最大堆（优先队列）来解决问题
        priority_queue<int> q;
        for(unsigned int i = 0; i < input.size(); ++i){
            q.push(input[i]);
            if(q.size() > k) q.pop();
        }
        while(!q.empty()) res.push_back(q.top()), q.pop();
        return res;
    }
};