#pragma once
#include <vector>

class UtilizationChecks
{
public:
	static int finalInstances(int instances, std::vector<int> averageUtil)
	{
		for (int i = 0; i < averageUtil.size(); i++)
		{
			// < 0.25: Reduce numInstances by half the number of instances if greater than 1
			// Take ceil if number is not an int. If number is 1 take no action
			if (averageUtil[i] < 25 && instances != 1)
			{
				instances = (int)ceil((double)instances / 2);
				i += 9;
			}

			// > 0.60 : an action is instantiated to double the ammount of instances if the doubled value does not exceed 2 * 10^8
			else if (averageUtil[i] > 60)
			{
				if (instances < pow(10.0, 8.0))
				{
					instances *= 2;
					i += 9;
				}
			}
		}

		return instances;
	};
	static void print_check(int instances, std::vector<int> averageUtil)
	{
		printf("Instances: %i \n", instances);
		printf("Average Util[]: [");
		for (auto& element : averageUtil)
		{
			printf("%i ", element);
		}
		printf("]\n");

		int num = UtilizationChecks::finalInstances(instances, averageUtil);
		printf("Output: %i \n\n", num);
	}
};

