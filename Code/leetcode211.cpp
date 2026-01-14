/*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 

示例：

输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // 返回 False
wordDictionary.search("bad"); // 返回 True
wordDictionary.search(".ad"); // 返回 True
wordDictionary.search("b.."); // 返回 True

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct TireNode
{
    bool isEnd;
    unordered_map<char, TireNode*> children;

    TireNode() : isEnd(false){}

    ~TireNode()
    {
        for(auto& p : children)
        {
            delete p.second;
        }
    }
};


class WordDictionary {
public:
    TireNode* root;

    WordDictionary()
    {
        root = new TireNode();
    }

    bool dfs(TireNode* root, string word, int index)
    {
        if(root == nullptr)return false;
        if(index == word.size())
        {
            return root->isEnd;
        }

        char ch = word[index];
        
        if(ch == '.')
        {
            //尝试所有可能子节点
            for(auto &p : root->children)
            {
                if(p.second && dfs(p.second, word, index + 1))
                {
                    return true;
                }
            }
        }
        else
        {
            if(root->children.find(ch) == root->children.end())
            {
                return false;
            }
        }

        return dfs(root->children[ch], word, index + 1);
    }

    void addWord(string word) {
        TireNode *node = root;

        for(char ch : word)
        {
            if(node->children.find(ch) == node->children.end())
            {
                TireNode *newNode = new TireNode();
                node->children[ch] = newNode;
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};


int main()
{

    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << "serach 'pad'：" << wordDictionary.search("pad") << endl; // 返回 False
    cout << "serach 'bad'：" << wordDictionary.search("bad") << endl; // 返回 True
    cout << "serach '.ad'：" << wordDictionary.search(".ad") << endl; // 返回 True
    cout << "serach 'b..'：" << wordDictionary.search("b..") << endl; // 返回 True

    return 0;
}