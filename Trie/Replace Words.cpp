/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FxmFhwmKumU
    Company Tags                : UBER
    Leetcode Link               : https://leetcode.com/problems/replace-words
*/


/*************************************************************************** C++ ******************************************************************************************/
//Using Trie
//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)

//My code 

class Solution {
public:

    struct trieNode {
        bool is_end;
        trieNode *children[26];
    };

    trieNode * get_node(){
        trieNode * node=new trieNode();

        node->is_end=false;

        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }

        return node;
    }

    void insert(string s,trieNode *root){


        for(auto ch:s){

           int index=ch-'a';

           if(root->children[index]==NULL){
              root->children[index]=get_node();
           }
           root=root->children[index];
        }

        root->is_end=true;
    }
    
    string search(string s,trieNode * root){

        string ans="";

        for(auto ch:s){

            int index=ch-'a';

            if(root->children[index]==NULL || root->is_end){
                break;
            }
            
            ans+=ch;
            root=root->children[index];
        }

        if(ans.empty()){
            return s;
        }

        if(root->is_end){

           if(ans.size()>s.size())return s;   

           else return ans;
        }
        
        return s;

    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        trieNode * root=get_node();

        for(auto s:dictionary){
            insert(s,root);
        }

        string result="";

        sentence+=' ';

        for(int i=0;i<sentence.size();i++){

            string temp="";

            for(int j=i;j<sentence.size();j++){
                if(sentence[j]==' '){
                    i=j;
                    break;
                }else
                temp+=sentence[j];
            }

            result+=search(temp,root);
            result+=' ';
            cout<<temp<<endl;
        }
        

        result.pop_back();




        return result;
        
    }
};


//same concept but differnt code

class Solution {
public:
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }

            
    trieNode* root;

    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return word; 
            crawler = crawler->children[index];
            if(crawler->isEndOfWord) {
                return word.substr(0, i+1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);
        string word;
        string result;
        root = getNode();
        for (string word : dictionary) {
            insert(word);
        }

        while(getline(ss, word, ' ')) {
            result += search(word) + " ";
        }

        result.pop_back();
        return result;
    }
};



/*************************************************************************** JAVA ******************************************************************************************/
//Using Trie
//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)
import java.util.List;
import java.util.StringTokenizer;
import java.util.StringJoiner;

class Solution {
    class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;

        TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
    }

    TrieNode root;

    public Solution() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null) {
                crawler.children[index] = new TrieNode();
            }
            crawler = crawler.children[index];
        }

        crawler.isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    public String search(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null) {
                return word;
            }
            crawler = crawler.children[index];
            if (crawler.isEndOfWord) {
                return word.substring(0, i + 1);
            }
        }
        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        for (String word : dictionary) {
            insert(word);
        }

        StringTokenizer st = new StringTokenizer(sentence);
        StringJoiner sj = new StringJoiner(" ");
        
        while (st.hasMoreTokens()) {
            String word = st.nextToken();
            sj.add(search(word));
        }

        return sj.toString();
    }
}
