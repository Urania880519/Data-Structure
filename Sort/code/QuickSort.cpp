#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& universe, int i, int j, int& area) {
    //Hint : Use DFS here to calculate the area of every planet.
    if (i < 0 || j < 0 || i >= universe.size() || j >= universe[0].size() || universe[i][j] == 0) {
        return;
    }
    universe[i][j] = 0; 
    area++;
    dfs(universe, i + 1, j, area);
    dfs(universe, i - 1, j, area);
    dfs(universe, i, j + 1, area);
    dfs(universe, i, j - 1, area);

}

int partition(vector<int>& v, int front, int end) {
    //TO-DO
   
    int pivot = v[end];
        
    int i = front - 1;
    for (int j = front; j < end; j++) {
        if (v[j] < pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    i++;
    int temp = v[i];
    v[i] = v[end];
    v[end] = temp;
    
    return i;
}

void quickSort(vector<int>& v, int front, int end) {
    //TO-DO
    if (front < end) {
        int pivot = partition(v, front, end);
        quickSort(v, front, pivot - 1);
        quickSort(v, pivot + 1, end);
    }

}

int main() {
    int m, n; //m,n represent the size of the universe.
    int res = 0; //res is the number of planets in the universe.
    vector<int> collectingArea; //collectingArea is used to collect the area of every planet.
    cin >> m >> n;
    vector<vector<int>> universe(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> universe[i][j];
        }
    }

    //TO-DO
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (universe[i][j] == 1) {
                int area = 0;
                dfs(universe, i, j, area);
                collectingArea.push_back(area);
                res++;
            }
        }
    }
    
    //TO-DO : Use the quickSort function you wrote to sort the vector collectingArea.
    quickSort(collectingArea, 0, res-1);

    cout << "The total number of planets is : " << res << endl;
    cout << "The areas of the planets in non-decreasing order are : ";
    for (int area : collectingArea) {
        cout << area << " ";
    }
}