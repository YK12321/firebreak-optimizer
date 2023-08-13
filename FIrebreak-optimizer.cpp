#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int maxY, maxX;
    cout << "Enter the number of rows (maxY): ";
    cin >> maxY;
    cout << "Enter the number of columns (maxX): ";
    cin >> maxX;

    vector<vector<int>> ArrayMap(maxY, vector<int>(maxX));
    vector<vector<int>> FireMap(maxY, vector<int>(maxX));
    vector<vector<int>> OptimalFirebreaks(maxY, vector<int>(maxX, 0));

    cout << "Entering Fire hazard level:" << endl;
    for (int y = 0; y < maxY; y++) {
        cout << "Row " << y + 1 << ":" << endl;
        for (int x = 0; x < maxX; x++) {
            cin >> ArrayMap[y][x];
        }
    }

    cout << "Entering fire state:" << endl;
    for (int y = 0; y < maxY; y++) {
        cout << "Row " << y + 1 << ":" << endl;
        for (int x = 0; x < maxX; x++) {
            cin >> FireMap[y][x];
        }
    }

    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            if (FireMap[y][x] == 1) {
                OptimalFirebreaks[y][x] = 1;
                for (int i = y - 1; i <= y + 1; i++) {
                    for (int j = x - 1; j <= x + 1; j++) {
                        if (i >= 0 && i < maxY && j >= 0 && j < maxX) {
                            OptimalFirebreaks[i][j] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << "Optimal Firebreak Positions:" << endl;
    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            cout << OptimalFirebreaks[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
