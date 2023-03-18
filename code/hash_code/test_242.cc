#include <iostream>
#include <string>
#include <set>
#include <cstring>

//  242是leetcode题号

//  有效的字母异位词

//  [1]. 解读题目:什么叫字母异位词：两个字符串，字母种类相同，字母出现的次数也相同。

bool ValidAnagrams(char word1[], char word2[])
{
    //  [1]. 用可重复的哈希表来存储字符
    std::multiset<char> word1_set, word2_set;

    //  [2]. 统计word1 和 word2的长度
    int len1 = std::strlen(word1);
    int len2 = std::strlen(word2);

    std::cout << "len1:" << len1 << std::endl;
    std::cout << "len2:" << len2 << std::endl; 

    //  [3]. 把字符添加到set容器中去
    for(int i=0; i<len1; i++)
    {
        word1_set.emplace(word1[i]);
    }
    for(int i=0; i<len1; i++)
    {
        word2_set.emplace(word2[i]);
    }

    //  [4]. 首先判断元素是否出现，再判断次数是否相等
    for(auto value : word1_set)
    {
        if(word1_set.count(value) != word2_set.count(value))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief 官方版本
*/
bool validanagrams(std::string word1, std::string word2)
{
    char num[26] = {0};

    for(int i=0; i<word1.size(); i++)
    {
        num[word1[i]-'a']++;
    }
    for(int i=0; i<word2.size(); i++)
    {
        num[word2[i]-'a']--;
    }
    for(int i=0; i<26; i++)
    {
        if(num[i] != 0)
            return false;
    }
    return true;

}


int main(int argc, char** argv)
{
    char word1[] = "sdafasfa", word2[]="sdafasfa";
    std::cout << ValidAnagrams(word1, word2) << std::endl;
    std::cout << validanagrams(word1, word2) << std::endl;
    return 0;
}