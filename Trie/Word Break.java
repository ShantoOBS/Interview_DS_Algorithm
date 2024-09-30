/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/word-break/description/?envType=problem-list-v2&envId=trie
*/

class TrieNode {
    Map<Character, TrieNode> map = new HashMap<>();
    boolean isWord = false;    
    void insert(String s) {
        TrieNode current = this;
        for(Character c : s.toCharArray()) {
            current = current.map.computeIfAbsent(c, k-> new TrieNode());            
        }
        current.isWord = true;
    }    
}

class Solution {
    Map<Integer, Boolean> cache = new HashMap<>();
    
    public boolean wordBreak(String s, TrieNode trie, int start) {    
        if(cache.containsKey(start))
            return cache.get(start);
        if(start == s.length()) { 
            return true;
        }
        TrieNode node = trie;
        for(int i = start; i < s.length(); i++) {
            if(node.map.containsKey(s.charAt(i))) {
                node = node.map.get(s.charAt(i));
                if(node.isWord) {
                    boolean isEnd = wordBreak(s, trie, i+1);
                    if(isEnd) {
                        cache.put(start, true);
                        return true;
                    }
                }
            } else {
                cache.put(start, false);
                return false;
            }
          }                
        return false;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        TrieNode root = new TrieNode();
        
        for(String word : wordDict) root.insert(word);
        
        return wordBreak(s, root, 0);    
    }
}
