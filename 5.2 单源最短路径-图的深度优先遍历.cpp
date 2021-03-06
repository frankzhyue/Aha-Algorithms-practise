5.2 单源最短路径-图的深度优先遍历
#include <iostream>
using namespace std;
int minn = 99999999;
int book[101];
int n;
int e[101][101];

//cur是当前所在的城市编号，dis是当前已经走过的路程
void dfs(int cur, int dis) {
    if (dis > minn)
        return ;
    if (cur == n) {
        if (dis < minn)
            minn = dis;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (e[cur][i] != 99999999 && book[i] == 0) {
            book[i] = 1;
            dfs(i, dis + e[cur][i]);
            book[i] = 0;
        }
    }
    return ;
}

int main() {
    int m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = 99999999;
        }
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        e[a][b] = c;
    }
    book[1] = 1;
    dfs(1, 0);
    cout << minn;
    return 0;
}