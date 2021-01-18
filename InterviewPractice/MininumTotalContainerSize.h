#pragma once
#include <vector>
#include <string>
#include <numeric>

using namespace std;
class MininumTotalContainerSize
{

protected:
    // optimal solution
    static int helper(int index, int d, vector<vector<int>>& dp, vector<int>& jobDifficulty) {
        if (index == jobDifficulty.size() and d == 0)
            return 0;

        if (index == jobDifficulty.size() or d == 0)
            return -1;

        if (dp[index][d] != -1)
            return dp[index][d];

        int maxDifficultJob = INT_MIN;
        int minDifficulty = INT_MAX;
        int limitIndex = jobDifficulty.size() - d;

        for (int i = index; i <= limitIndex; i++) {
            maxDifficultJob = max(maxDifficultJob, jobDifficulty[i]);

            int subSequentResult = helper(i + 1, d - 1, dp, jobDifficulty);

            if (subSequentResult != -1) {
                int curDifficulty = maxDifficultJob + subSequentResult;
                minDifficulty = min(minDifficulty, curDifficulty);
            }
        }

        return dp[index][d] = minDifficulty == INT_MAX ? -1 : minDifficulty;
    }

public:
    static int findMininumTotalContainerSize(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        int output = helper(0, d, dp, jobDifficulty);
        printf("Output: %i\n\n", output);
        return output;
    }

protected:
    // first solution
	static int recursionAlgorithm(vector<int> arr, int days)
	{
		if (days == 1)
		{
			return *max_element(begin(arr), end(arr));
		}

		if (*arr.begin() < *(arr.end() - 1))
		{
			vector<int> v(arr.begin() + 1, arr.end());
			return recursionAlgorithm(v, days - 1) + *arr.begin();
		}
		else {
			vector<int> v(arr.begin(), arr.end() - 1);
			return recursionAlgorithm(v, days - 1) + *(arr.end() - 1);
		}
	}
};

