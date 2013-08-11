class Solution {
private:
    vector<string> result;
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        help(s,"",0);
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    
    void help(string left, string current, int seg)
    {
        if(left=="")
        {
            if(seg==4)
            {
                current = current.substr(0,current.size()-1);
                result.push_back(current);
            }
            return;
        }
        if(seg == 4) return;
        stringstream ss;
        int temp_int;
        
        string temp = left.substr(0,1);
        string temp_left, temp_current;
        
        ss.clear();
        ss<<temp;
        ss>>temp_int;
        ss.clear();
        ss<<temp_int;
        ss>>temp;
        if(temp == left.substr(0,1))
        {
            temp_left = left.substr(1,left.size()-1);
            temp_current = current+temp+".";
            help(temp_left, temp_current,seg+1);
        }
        if(left.size()==1) return;
        temp = left.substr(0,2);
        
        ss.clear();
        ss<<temp;
        ss>>temp_int;
        ss.clear();
        ss<<temp_int;
        ss>>temp;
        if(temp==left.substr(0,2))
        {
            temp_left = left.substr(2,left.size()-2);
            temp_current = current+temp+".";
            help(temp_left, temp_current, seg+1);
        }
        if(left.size()==2) return;
        temp = left.substr(0,3);
        ss.clear();
        ss<<temp;
        ss>>temp_int;
        ss.clear();
        ss<<temp_int;
        ss>>temp;
        if(temp == left.substr(0,3))
        {
            if(temp_int>255) return;
            temp_left = left.substr(3,left.size()-3);
            temp_current = current+temp+".";
            help(temp_left, temp_current, seg+1);
        }
        return;
    }
};
