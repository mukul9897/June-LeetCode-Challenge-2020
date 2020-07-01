class trie{
public:
    trie* ch[26];  
    bool Endofword;
    trie():Endofword(false){
        for(int i=0;i<26;i++)
            ch[i]=nullptr;
    }
    ~trie(){
         for(int i=0;i<26;i++)
            if(ch[i]) delete ch[i];
    }
    void insert(string word){
        trie *curr=this;
        for(char c:word){
            if(!curr->ch[c-'a']) curr->ch[c-'a']=new trie();
            curr=curr->ch[c-'a'];
        }
        curr->Endofword=true;
    }
            
};
class Solution {
    void dfs(vector<vector<char>>& board,int i,int j,unordered_set<string>& result,trie* Trie,string s){
        char c=board[i][j];
        if(c=='$') return;
        board[i][j]='$';
        trie* t=Trie->ch[c-'a'];
        if(t){
            string ss=s+c;
            if(t->Endofword) result.insert(ss);
            if(i< board.size()-1) dfs(board,i+1,j,result,t,ss);
            if(j< board[0].size()-1) dfs(board,i,j+1,result,t,ss);
            if(i> 0) dfs(board,i-1,j,result,t,ss);
            if(j> 0) dfs(board,i,j-1,result,t,ss);
        }
        board[i][j]=c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size()==0) return {};
        trie Trie;
        for(string w:words) Trie.insert(w);
        
        unordered_set<string>result;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,result,&Trie,"");
        }
        vector<string>result_v(result.begin(),result.end());
        return result_v;
    }
};
