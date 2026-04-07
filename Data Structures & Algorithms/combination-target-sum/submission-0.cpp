class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> visited;
        backtracking(candidates, target, 0, visited, answer);
        return answer;
    }
    void backtracking(vector<int>& candidates, int target, int start, vector<int>& visited, vector<vector<int>>& answer) {
        if (target == 0) {
            answer.push_back(visited);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                visited.push_back(candidates[i]);
                backtracking(candidates, target - candidates[i], i, visited, answer);
                visited.pop_back();
            }
        }
    }
};