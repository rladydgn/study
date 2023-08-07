#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int img[502][502];
bool visited[502][502];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m, cnt;
vector<int> imgSizeList;

void dfs(int x, int y, int &imgSize)
{
    visited[x][y] = true;
    imgSize++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || ny >= m || nx < 0 || ny < 0)
            continue;

        if (!visited[nx][ny] && img[nx][ny] == 1)
        {
            dfs(nx, ny, imgSize);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> img[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && img[i][j] == 1)
            {
                int imageSize = 0;
                dfs(i, j, imageSize);
                cnt++;
                imgSizeList.push_back(imageSize);
            }
        }
    }

    cout << cnt << '\n';
    int max = *max_element(imgSizeList.begin(), imgSizeList.end());
    cout << max << "\n";

    return 0;
}