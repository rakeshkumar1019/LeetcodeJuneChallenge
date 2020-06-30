class Solution {
         class TrieNode{
                 public:
                string word;
                TrieNode* children[26];
                TrieNode(){
                        word="";
                        for(int i=0;i<26;i++){
                                children[i]=NULL;
                        }
                }
        };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=buildTree(words);
            vector<string> res;
            for(int i=0;i<board.size();i++){
                    for(int j=0;j<board[0].size();j++){
                            dfs(board,root,res,i,j);
                    }
            }
            return res;
            
    }
        
  TrieNode* buildTree(vector<string>& words){
          TrieNode* root=new TrieNode();
          for(int i=0;i<words.size();i++){
                   string currWord=words[i];
                  TrieNode * curr=root;
                  for(int j=0;j<currWord.length();j++){
                        int c=currWord[j]-'a';
                          if(curr->children[c]==NULL){
                                  curr->children[c]=new TrieNode();
                          }
                          curr=curr->children[c];
                  }
                  curr->word=currWord;
          }
          return root;
          
  }
  void dfs(vector<vector<char>>& board,TrieNode* root,vector<string> &res,int i,int j){
          char c=board[i][j];
          if(c=='#' || !root->children[c-'a']) return;
          root=root->children[c-'a'];
          if(root->word.size()>0){
                  res.push_back(root->word);
                  root->word="";
          }
          board[i][j]='#';
          if(i>0)dfs(board,root,res,i-1,j);
          if(j>0)dfs(board,root,res,i,j-1);
          if(i<board.size()-1)dfs(board,root,res,i+1,j);
          if(j<board[0].size()-1)dfs(board,root,res,i,j+1);
          board[i][j]=c;
  }   
        
};
