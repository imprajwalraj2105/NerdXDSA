// You are using GCC
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image, int i, int j, int m, int n, int oldColor, int newColor){
    if(i<0 || i>=m || j<0 || j>=n) return;
    if(image[i][j] != oldColor) return;  // stop if different color

    image[i][j] = newColor;  // recolor

    dfs(image, i+1, j, m, n, oldColor, newColor);
    dfs(image, i-1, j, m, n, oldColor, newColor);
    dfs(image, i, j+1, m, n, oldColor, newColor);
    dfs(image, i, j-1, m, n, oldColor, newColor);
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> image(m, vector<int>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> image[i][j];

    int sr, sc, color;
    cin >> sr >> sc >> color;

    int oldColor = image[sr][sc];

    if(oldColor != color)  // only fill if different color
        dfs(image, sr, sc, m, n, oldColor, color);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(j) cout << " ";
            cout << image[i][j];
        }
        cout << "\n";
    }
    return 0;
}