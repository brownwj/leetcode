#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(num.size() == 0) return result;
        vector<int> current;
        current.clear();
        getPermute(current, num, num.size());
        return result;
    }

    void getPermute(vector<int> current, vector<int> num, int n)
    {
        if(n==0)
        {
            result.push_back(current);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            vector<int> temp_current(current);
            temp_current.push_back(num[i]);
            vector<int> temp;
            temp.clear();
            for(int j=0;j<num.size();j++)
            {
                if(j==i) continue;
                temp.push_back(num[j]);
            }
            getPermute(temp_current, temp, n-1);
        }
        return;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int a[3] = {1,2,3};
    vector<int> num(a,a+3);
//solute your problem here
	vector<vector<int> > result = my_solution->permute(num);

//print your output here
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
