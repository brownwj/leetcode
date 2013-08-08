#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(abs(x)<10) return true;
        int a=x,b=x%10;
        int length=0;
        int temp = a;
        while(temp!=0)
        {
            temp/=10;
            length++;
        }
        cout<<length<<endl;
        int m;
        if(length%2==1)
        {
            m=(length-1)/2;
            int up = pow(10,m+1);
            int up_x = x/up%10;
            int down = pow(10,m-1);
            int down_x = x/down%10;
            cout<<up<<" "<<down<<endl;
            cout<<up_x<<" "<<down_x<<endl;
            if(up_x!=down_x) return false;
            while(down/10!=0)
            {
                up = up*10;
                down = down/10;
                up_x = x/up%10;
                down_x = x/down%10;
                if(up_x!=down_x)
                    return false;
            }
            return true;
        }
        else
        {
            m=length/2-1;
            int up = pow(10,m+1);
            int down = pow(10,m);
            int up_x = x/up%10;
            int down_x = x/down%10;
            if(up_x!=down_x) return false;
            while(down/10!=0)
            {
                up = up*10;
                down = down/10;
                up_x = x/up%10;
                down_x = x/down%10;
                if(up_x!=down_x)
                    return false;
            }
            return true;
        }
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
    int num = -2147483648;
	bool result = my_solution->isPalindrome(num);

//print your output here
    cout<<result<<endl;
}
