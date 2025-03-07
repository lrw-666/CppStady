//std::unordered-map的底层实现为哈希表,std::set、std::map和std::multimap的底层实现是红黑树(有序)
/*
力扣题号: 242.有效的字母异位词。
［题目描述］
判断字符串s中的字符是否可以通过改变顺序的方式变成字符串t（如果字符串S与字符串t相
同,那么也星可以的）。
字符串中只包含小写字母
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII值，只要求出一个相对数即可
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // 如果record数组中有的元素不为0
                // 则说明字符串s和t一定是谁多了字符或者少了字符
                return false;
            }
        }
        // record数组中所有元素均为0
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    bool res = s.isAnagram(s1, s2);
    cout << res << endl;
    return 0;
}