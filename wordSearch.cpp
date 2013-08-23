class Solution {
private:
    vector<vector<int> > tag;
    int m,n;
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(word.size()==0) return true;
        if(!board.size()) return false;
        if(!board[0].size()) return false;
        m=board.size();
        n=board[0].size();
        tag.clear();
        for(int i=0;i<m;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
                temp.push_back(0);
            tag.push_back(temp);
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0])
                    if(find(i,j,word,board))
                        return true;
        return false;
    }
    
    bool find(int i, int j, string word, vector<vector<char> > board)
    {
        if(word[0]!=board[i][j]) return false;
        tag[i][j]=1;
        bool result=false;
        string temp_str = word.substr(1,word.size()-1);
        if(temp_str.size()==0) return true;
        if((i-1)>=0 && tag[i-1][j]==0)
        {
            if(find(i-1,j,temp_str,board))
                return true;
        }
        if((i+1)<m && tag[i+1][j]==0)
        {
            if(find(i+1,j,temp_str,board))
                return true;
        }
        if((j-1)>=0 && tag[i][j-1]==0)
        {
            if(find(i,j-1,temp_str,board))
                return true;
        }
        if((j+1)<n && tag[i][j+1]==0)
        {
            if(find(i,j+1,temp_str,board))
                return true;
        }
        tag[i][j]=0;
        return false;
    }
};
