/* ------------------------------------------------------------------|
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*	执行用时：4 ms, 在所有 C++ 提交中击败了97.56%的用户
*	内存消耗：8.8 MB, 在所有 C++ 提交中击败了60.17%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<int>> res;
vector<int> visited;
vector<int> tmp;

void dfs(vector<int> &nums,int index) {
    //index用于确保tmp长度符合要求
    if (index == nums.size()) {
        res.emplace_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        //因为事先将nums排序过，因此该操作可避免重复元素重复操作，确保只将第一个未重复元素进行操作
        //如果当前位置访问过了或者说虽然没访问过但是因为和前面的元素相同
        //即前面的相同元素访问过了的话，就不再操作，进行下一个循环
        if (visited[i] || (i > 0 && !visited[i-1] && nums[i] == nums[i - 1])) {
            continue;
        }
        tmp.emplace_back(nums[i]);
        visited[i] = 1;
        dfs(nums, index + 1);
        visited[i] = 0;
        tmp.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    visited.resize(nums.size());
    sort(nums.begin(), nums.end());

    dfs(nums, 0);
    return res;
}

int main() {
    vector<int> nums = { 1,2,3 };
    permuteUnique(nums);
}