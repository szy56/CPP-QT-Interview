/*
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True

*/

#include<iostream>
using namespace std;

struct TrieNode{
    bool isEnd; //该节点是否是一个串的结束
    TrieNode* next[26]; //字母映射表
};

class Trie{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode(); //创建一个节点
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for(char c : word){
            if(node->next[c - 'a'] == NULL){
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true; //标记结尾
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for(char c : word){
            node = node->next[c - 'a'];
            if(node == nullptr)return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for(char c : prefix)
        {
            node = node->next[c - 'a'];
            if(node == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{

    Trie trie;
    trie.insert("apple");
    cout << "查找apple：" << trie.search("apple") << endl;   // 返回 True
    cout << "查找app：" << trie.search("app") << endl;     // 返回 False
    cout << "查找app前缀：" << trie.startsWith("app") << endl; // 返回 True
    trie.insert("app");
    trie.search("app");     // 返回 True

    return 0;
}
