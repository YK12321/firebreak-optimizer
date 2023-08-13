#include <iostream>
 
using namespace std;
 
int main()
{
    int maxY, maxX;
    cout << "Enter the number of rows (maxY): ";
    cin >> maxY;
    cout << "Enter the number of columns (maxX): ";
    cin >> maxX;
 
    int **ArrayMap = new int *[maxY];
    int **FireMap = new int *[maxY];
    int **OptimalFirebreaks = new int *[maxY];
 
    for (int y = 0; y < maxY; y++) {
        ArrayMap[y] = new int[maxX];
        FireMap[y] = new int[maxX];
        OptimalFirebreaks[y] = new int[maxX];
    }
 
    for (int y = 0; y < maxY; y++) {
        for (int x = 0; x < maxX; x++) {
            cout << "Enter a fire risk level (0, 1, 2, or 3) for ";
            cout << "Y = " << y << ", X = " << x << endl;
            cin >> ArrayMap[y][x];
            cout << "Now enter current fire state (1 for burning, 0 for not burning): ";
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
 
    // Deallocate memory
    for (int y = 0; y < maxY; y++) {
        delete[] ArrayMap[y];
        delete[] FireMap[y];
        delete[] OptimalFirebreaks[y];
    }
    delete[] ArrayMap;
    delete[] FireMap;
    delete[] OptimalFirebreaks;
 
    return 0;
}
 
