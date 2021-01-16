#pragma once
#include <algorithm>
#include <vector>

class CuttoffRanks
{
public:
	static int cutOffRank(int cutOffRank, int num, std::vector<int> scores)
	{
		std::sort(scores.begin(), scores.end(), std::greater<>());
		int levelUps = 0;
		int rank = 1;
		int nextRank = 1;
		for (int i = 0; i < scores.size() && rank <= cutOffRank; i++)
		{
			if (i == 0)
			{
				levelUps++;
			}
			else if (scores[i] == scores[i - 1])
			{
				levelUps++;
			}
			else
			{
				rank = nextRank;
				if (rank <= cutOffRank)
				{
					levelUps++;
				}
				else break;
			}
			nextRank++;
		}
		return levelUps;
	}
	static void print_cut_off_rank(int cutOffRank, int num, std::vector<int> scores)
	{
		printf("CutOffRank: %i \nNum: %i \nScores[]: [", cutOffRank, num);
		for (auto& s : scores)
		{
			printf("%i ", s);
		}
		int Output = CuttoffRanks::cutOffRank(cutOffRank, num, scores);
		printf("]\nOutput: %i \n\n", Output);
	}
};

