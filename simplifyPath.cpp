#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(path.size()==0) return "";
        if(path[0]!='/') return "";
        stack<string> st;
        stringstream ss;
        string temp="";
        int first = 0;
        for(int i=1;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(temp=="" || temp==".")
                {
                    temp="";
                }
                else if(temp=="..") 
                {
//                    cout<<"HHH"<<endl;
                    temp="";
                    if(!st.empty()) st.pop();
                    first--;
                }
                else
                {
//                    cout<<temp<<endl;
                    st.push(temp);
                    temp="";
                    first=1;
                }
                continue;
            }
            ss.clear();
            ss<<temp;
            ss<<path[i];
            ss>>temp;
        }
        if(path[path.size()-1]!='/')
        {
            if(temp=="..")
            {
                if(!st.empty()) st.pop();
            }
            else if(temp!="." && temp!="")
            {
                st.push(temp);
                temp="";
                first=0;
            }
        }
        string result="";
        stack<string> last;
        while(!st.empty())
        {
            last.push(st.top());
            st.pop();
        }
        while(!last.empty())
        {
            ss.clear();
            ss<<result;
            ss<<"/";
            ss<<last.top();
            ss>>result;
            last.pop();
//            cout<<"result = "<<result<<endl;
        }
        if(result=="") return "/";
        return result;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    string path="/.hidden";
//solute your problem here
	string result = my_solution->simplifyPath(path);

//print your output here
    cout<<result<<endl;
}
