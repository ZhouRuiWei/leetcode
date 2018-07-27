/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true

示例 2:

输入: "()[]{}"
输出: true

示例 3:

输入: "(]"
输出: false

示例 4:

输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

*/
class Solution {
public:
    bool match(char a, char b)// a is the left, b is the right
    {
        if(a=='(' && b ==')')
            return true;
        if(a=='[' && b ==']')
            return true;
        if(a=='{' && b =='}')
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> ss;
        for(auto c : s)
        {
            if(c == '(' || c=='[' || c=='{')
                ss.push(c);
            else
            {
                if(ss.empty())// if ss is empty and we get a right  
                    return false;
                if(match(ss.top(),c))
                    ss.pop();
                else
                    return false;
            }
        }
        if(ss.empty())
            return true;
        else
            return false;
    }
};