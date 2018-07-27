/*给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


// catalan number!!!!!!
class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        long int result  = 1;
        for(int i = 1;i != n+1;i++)
        {
            result = result * (n+i)/i;
        }
        result = result/(n+1);
        return result;
    }
};