#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        result.clear();
        if(numRows == 0) return result; 
        for(int i=0;i<numRows;i++)
        {
            int j=0;
            vector<int> current;
            current.push_back(1);
            j++;
            for(;j<=i-1;j++)
                current.push_back(result[i-1][j-1]+result[i-1][j]);
            if(j<i+1)
                current.push_back(1);
            result.push_back(current);
        }
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	vector<vector<int> > result = my_solution->generate(5);

//print your output here
   	for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
