/*
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

示例 1：

输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
示例 2：

输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
输出：2
示例 3：

输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
输出：3

*/

#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> cnt;
    unordered_set<string> visited;
    char keys[4] = {'A', 'C', 'G','T'};
    for(auto &w : bank)
    {
        cnt.insert(w);
    }

    if(startGene == endGene)
    {
        return 0;
    }

    if(cnt.empty())
    {
        return -1;
    }

    queue<string> qu;
    qu.push(startGene);
    visited.insert(startGene);
    int step = 1;
    while(!qu.empty())
    {
        int sz = qu.size();
        for(int i = 0; i < sz; ++i)
        {
            string curr = qu.front();
            qu.pop();
            for(int j = 0; j < 8; ++j)
            {
                for(int k = 0; k < 4; ++k)
                {
                    if(keys[k] != curr[j])
                    {
                        string next = curr;
                        next[j] = keys[k];
                        if(!visited.count(next) && cnt.count(next))
                        {
                            if(next == endGene)
                            {
                                return step;
                            }
                            qu.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};

    cout << "最小路径为：" << minMutation(start, end, bank) << endl;

    return 0;
}