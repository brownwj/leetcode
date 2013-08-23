#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty()) return true;
        int i=0, j=s.size()-1;
        while(i<s.size())
        {
            if(!valid(s[i]))
            {
                i++;continue;
            }
            if(!valid(s[j]))
            {
                j--;continue;
            }
            if(tolower(s[i])!=tolower(s[j]))
                return false;
            i++;j--;
        }
        return true;
    }
    
    bool valid(char c)
    {
        if((c>='a'&&c<='z') || (c>='A'&&c<='Z'))
            return true;
        if(c>='0'&&c<='9') return true;
        return false;
    }
};

int main()
{
    Solution *my = new Solution();
    bool result = my->isPalindrome("ab");
}
