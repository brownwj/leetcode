class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stringstream ss;
        int result;
        ss.clear();
        int flag=1;
        if(x<0) {flag=-1;x=-x;}
        string temp;
        ss<<x;
        ss>>temp;
        int begin=0, end=temp.size()-1;
        while(begin<end)
        {
            char temp_c = temp[begin];
            temp[begin] = temp[end];
            temp[end] = temp_c;
            begin++;
            end--;
        }
        ss.clear();
        ss<<temp;
        ss>>result;
        result*=flag;
        return result;
    }
};
