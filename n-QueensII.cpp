#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Solution {
private:
    int ret;
    bool visit[100];
    int rec[100];
public:
    bool check(int i, int dep) {
        for (int j = 0; j < dep; j++) {
            if (abs(j - dep) == abs(i - rec[j])) return false;
        }
        return true;
    }
    void dfs(int dep, int n) {
         if (dep == n) {
             ret++;
             return;
         }
         for (int i = 0; i < n; i++) {
             if (!visit[i] && check(i, dep)) {
                 visit[i] = true;
                 rec[dep] = i;
                 dfs(dep+1, n);
                 visit[i] = false;
             }
         }
     }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        memset(visit, false, sizeof(visit));
        dfs(0, n);
        return ret;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
    int n = 12;
	int my_result = my_solution->totalNQueens(n);

//print your output here
    cout<<my_result<<endl;
}
