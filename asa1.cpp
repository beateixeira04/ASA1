#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

inline string reconstructParenthesization(const vector<vector<vector<vector<int>>>> &resultTable, const vector<int> &operations, int line, int col, int index)
{
    if (line == col)
        return to_string(operations[line]);

    const auto &entry = resultTable[line][col][index];
    int k = entry[3];
    int indexLeft = entry[1];
    int indexRight = entry[2];

    string left = reconstructParenthesization(resultTable, operations, line, k, indexLeft);
    string right = reconstructParenthesization(resultTable, operations, k + 1, col, indexRight);

    return "(" + left + " " + right + ")";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tableSize, numberOperations, result;
    cin >> tableSize >> numberOperations;

    vector<vector<int>> table(tableSize, vector<int>(tableSize));
    for (int i = 0; i < tableSize; i++)
        for (int j = 0; j < tableSize; j++)
            cin >> table[i][j];

    vector<int> operations(numberOperations);
    for (int i = 0; i < numberOperations; i++)
        cin >> operations[i];

    cin >> result;

    if (numberOperations == 1)
    {
        if (operations[0] == result)
        {
            cout << "1\n" << operations[0] << endl;
            return 0;
        }
        cout << "0\n";
        return 0;
    }

    vector<vector<vector<vector<int>>>> resultTable(
    numberOperations, vector<vector<vector<int>>>(numberOperations));
    vector<vector<int>> currentResult(numberOperations * (numberOperations - 1) / 2);
    vector<vector<int>> finalResult;
    unordered_set<int> uniqueResults;

    for (int i = 0; i < numberOperations; i++)
        resultTable[i][i] = {{0, operations[i]}};

    bool foundResult = false;

    for (int length = 2; length <= numberOperations && !foundResult; length++) {
    for (int i = 0; i <= numberOperations - length && !foundResult; i++) {
        int j = i + length - 1;

        uniqueResults.clear();
        currentResult.clear();
        bool foundAllResults = false;

        for (int k = j - 1; k >= i && !foundResult && !foundAllResults; k--) {
            const auto &leftSet = resultTable[i][k];
            const auto &rightSet = resultTable[k + 1][j];

            for (const auto &left : leftSet) {
                int leftResult = left.back();

                for (const auto &right : rightSet) {
                    int rightResult = right.back();
                    int combinedResult = table[leftResult - 1][rightResult - 1];


                    if (length == numberOperations && combinedResult == result) {
                        foundResult = true;
                        finalResult = {{(int)currentResult.size(), left[0], right[0], k, combinedResult}};
                        break;
                    }


                    if (uniqueResults.insert(combinedResult).second) {
                        currentResult.push_back({(int)currentResult.size(), left[0], right[0], k, combinedResult});
                    }


                    if ((int)uniqueResults.size() == tableSize) {
                        foundAllResults = true;
                        break;
                    }
                }
                if (foundResult || foundAllResults) break;
            }
            if (foundResult || foundAllResults) break;
        }

        resultTable[i][j] = move(currentResult);
    }
}


    resultTable[0][numberOperations - 1] = move(finalResult);

    if (foundResult)
    {
        cout << "1\n" << reconstructParenthesization(resultTable, operations, 0, numberOperations - 1, 0) << endl;
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
