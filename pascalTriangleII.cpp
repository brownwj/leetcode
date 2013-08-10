#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        result.clear();
        if(rowIndex < 0) return result;
        for(int i=0;i<=rowIndex;i++)
            result.push_back(getC(i, rowIndex));
        return result;
    }

    int getC(int i, int n)
    {
        if(i==0 || i==n) return 1;
        int j=0;
        long long sum=1;
        for(;j<i;j++)
        {
            sum*=(n-j);
            sum/=(j+1);
        }
        return sum;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	vector<int> result = my_solution->getRow(21);

//print your output here
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
}
