/*
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

边界情况:

    你是否考虑了 路径 = "/../" 的情况？
    在这种情况下，你需返回 "/" 。
    此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
    在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。


*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        int cnt = 0;
        for(auto c : path)
        {
            if(c == '/')
            {   
                cnt=0;
                if(s.empty() || s.top()!= '/')
                    s.push(c);
                continue;
            }
            if(c == '.')
            {
                cnt++;
                if(cnt == 1)
                    s.pop();
                if(cnt == 2)
                {
                    cnt = 0;
                    if(s.empty())
                        s.push('/');
                    else
                    {
                        while(s.top()!='/')
                            s.pop();
                    }
                }
            }
            else
            {
                cnt = 0;
                s.push(c);
            }
        }
        if(s.empty())
            s.push('/');
        if(s.size()> 1 && s.top() == '/')
            s.pop();
        int n = s.size();
        string result(n,'*');
        while(n)
        {
            result[n-1] = s.top();
            s.pop();
            n--;
        }
        return result;


    }
};