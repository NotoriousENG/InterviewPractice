#pragma once

class HourglassSum
{
    using namespace std;

    // Complete the hourglassSum function below.
    int hourglassSum(vector<vector<int>> arr) {
        int i = arr.size();
        int j = arr[0].size();
        printf("I: %i\n J: %i\n", i, j);
        return 0;
    }

    int main()
    {
        ofstream fout(getenv("OUTPUT_PATH"));

        vector<vector<int>> arr(6);
        for (int i = 0; i < 6; i++) {
            arr[i].resize(6);

            for (int j = 0; j < 6; j++) {
                cin >> arr[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = hourglassSum(arr);

        fout << result << "\n";

        fout.close();

        return 0;
    }

};

