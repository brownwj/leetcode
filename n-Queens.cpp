#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Solution
{
//write your function to calculate here
private:
    vector<vector<vector<int> > > result;
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v_i;
        result.clear();
        v_i.clear();
        if(n<=0) return convert2string(result, n);
        help(v_i, n, 0);
        return convert2string(result, n);
    }

    void help(vector<vector<int> > v_i, int n, int i)
    {
        if(i==n)
        {
//            print_v_i(v_i, n);
            result.push_back(v_i);
            return;
        }
        for(int j=0;j<n;j++)
        {
            vector<int> temp(n,0);
            temp[j]=1;
            v_i.push_back(temp);
            if(check(v_i,n,i,j))
            {
                help(v_i,n,i+1);
                vector<vector<int> >::iterator iter = v_i.begin();
                for(int k=0;k<i;k++,iter++);
                iter = v_i.erase(iter);
            }
            else
            {
                vector<vector<int> >::iterator iter = v_i.begin();
                for(int k=0;k<i;k++,iter++);
                iter = v_i.erase(iter);
            }
        }
    }

//    void print_v_i(vector<vector<int> > v_i, int n)
//    {
//        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
//        for(int i=0;i<v_i.size();i++)
//        {
//            for(int j=0;j<n;j++)
//                cout<<v_i[i][j]<<" ";
//            cout<<endl;
//        }
//    }

    bool check(vector<vector<int> > v_i, int n, int i, int j)
    {
        for(int p=0;p<i;p++)
        {
            if(v_i[p][j]==1)
                return false;
            for(int q=0;q<n;q++)
            {
                if(v_i[p][q] == 1 && (abs(p-i) == abs(q-j)))
                    return false;
            }
        }
        return true;
    }

    vector<vector<string> > convert2string(vector<vector<vector<int> > > v_i, int n)
    {
        vector<vector<string> > s_v;
        s_v.clear();
        if(n<=0) return s_v;
        for(int i=0;i<v_i.size();i++)
        {
            vector<string> temp;
            for(int j=0;j<n;j++)
            {
                string temp_string = "";
                for(int k=0;k<n;k++)
                {
                    if(v_i[i][j][k] == 0)
                        temp_string+=".";
                    else
                        temp_string+="Q";
                }
                temp.push_back(temp_string);
            }
            s_v.push_back(temp);
        }
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
    int n = 4;
	vector<vector<string> > my_result = my_solution->solveNQueens(n);

//print your output here
    for(int i=0;i<my_result.size();i++)
    {
        for(int j=0;j<n;j++)
            cout<<my_result[i][j]<<endl;
        cout<<"*************************"<<endl;
    }
}
