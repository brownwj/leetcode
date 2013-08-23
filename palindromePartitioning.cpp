#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
private:
    vector<vector<string> > result;
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(s.size()==0) return result;
        vector<string> current;
        help(s,current);
        return result;
    }
    
    void help(string s, vector<string> current)
    {
        if(s.size()==0) result.push_back(current);
        for(int i=0;i<s.size();i++)
        {
            string temp = s.substr(0,i+1);
            if(!isPalindrome(temp))
                continue;
            vector<string> here=current;
            here.push_back(temp);
            temp = s.substr(i+1,s.size()-i-1);
            help(temp,here);
        }
        return;
    }
    
    bool isPalindrome(string s)
    {
        if(s.size()==0) return true;
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	vector<vector<string> > result = my_solution->partition("bb");

//print your output here
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<",";
        cout<<endl;
    }
    cout<<endl;
}
