class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        result.clear();
        vector<int> temp_null;
        temp_null.clear();
        result.push_back(temp_null);
        if(S.size()==0)  return result;
        vector<vector<int> > current;
        for(int i=0;i<S.size();i++)
        {
            vector<int> temp;
            temp.push_back(S[i]);
            result.push_back(temp);
            current.push_back(temp);
        }
        vector<vector<int> > current_temp;
        for(int i=1;i<S.size();i++)
        {
            for(int j=0;j<current.size();j++)
            {
                int this_size = current[0].size();
                for(int k=S.size()-1;k>=0 && S[k]>current[j][this_size-1];k--)
                {
                    vector<int> high(current[j]);
                    high.push_back(S[k]);
                    result.push_back(high);
                    current_temp.push_back(high);
                }
            }
            current = current_temp;
            current_temp.clear();
        }
        return result;
    }
};
