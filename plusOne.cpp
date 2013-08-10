class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int temp=1;
        for(int i=digits.size()-1;i>-1;i--)
        {
            int current = digits[i]+temp;
            digits[i] = current%10;
            temp = current/10;
        }
        if(temp==0) return digits;
        vector<int> result;
        result.clear();
        result.push_back(1);
        for(int i=0;i<digits.size();i++)
            result.push_back(digits[i]);
        return result;
    }
};
