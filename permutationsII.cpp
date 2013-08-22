#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(num.size() == 0) return result;
        vector<int> current;
        current.clear();
        map<int,int> used;
        map<int,int>::iterator iter;
        for(int i=0;i<num.size();i++)
        {
            iter = used.find(num[i]);
            if(iter!=used.end())
                iter->second++;
            else
            {
                used.insert(pair<int,int>(num[i],1));
            }
        }
        getPermute(current, used, num.size());
        return result;
    }

    void getPermute(vector<int> current, map<int,int> used, int n)
    {
        if(n==0)
        {
            result.push_back(current);
            return;
        }
        map<int,int>::iterator iter;
        for(iter=used.begin();iter!=used.end();iter++)
        {
            if(iter->second == 0) continue;

            vector<int> temp_current(current.begin(), current.end());
            temp_current.push_back(iter->first);
            map<int,int> temp_used(used.begin(), used.end());
            map<int,int>::iterator temp_iter;
            temp_iter = temp_used.find(iter->first);
            temp_iter->second--;
            getPermute(temp_current, temp_used, n-1);
        }
        return;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int a[3] = {1,1,3};
    vector<int> num(a,a+3);
//solute your problem here
	vector<vector<int> > result = my_solution->permuteUnique(num);

//print your output here
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
