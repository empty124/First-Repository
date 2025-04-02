#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_CITIES 5
#define INF INT_MAX
#define START_CITY 1 // 定义起始城市为1

// 定义一个函数，用于寻找距离当前城市最近的、尚未访问的城市
int findNearestCity(int adjMatrix[][NUM_CITIES], bool visited[], int currentCity) {
    int nearestCity = -1;
    int minDist = INF;

    for (int i = 0; i < NUM_CITIES; i++) {
        if (!visited[i] && adjMatrix[currentCity-1][i] < minDist) {
            minDist = adjMatrix[currentCity-1][i];
            nearestCity = i + 1;
        }
    }

    return nearestCity;
}

void printPathAndSum(int path[], int adjMatrix[][NUM_CITIES]) {
    int pathSum = 0;
    printf("Path: %d", path[0]); // 起始城市
    for (int i = 1; i < NUM_CITIES; i++) {
        printf(" -> %d", path[i]); // 中间城市
        pathSum += adjMatrix[path[i-1]-1][path[i]-1]; // 计算距离时减1
    }
    pathSum += adjMatrix[path[NUM_CITIES-1]-1][path[0]-1]; //
    printf(" -> %d", START_CITY); // 输出回到起点的步骤
    printf("\n"); // 换行
    printf("Path Sum : %d\n", pathSum); // 打印总路径距离
}

int main() {
    int adjMatrix[NUM_CITIES][NUM_CITIES] = {
        {0, 3, 3, 2, 6}, //
        {3, 0, 7, 3, 2},
        {3, 7, 0, 2, 5},
        {2, 3, 2, 0, 3},
        {6, 2, 5, 3, 0}
    };

    // 定义一个数组，用于标记城市是否已被访问
    bool visited[NUM_CITIES] = {false};
    // 定义一个数组，用于存储访问路径
    int path[NUM_CITIES];
    int currentCity = START_CITY;
    visited[currentCity-1] = true;
    path[0] = currentCity; // 存储起始城市编号

    // 使用最近邻点策略构建路径
    for (int i = 1; i < NUM_CITIES; i++) {
        int nextCity = findNearestCity(adjMatrix, visited, currentCity); // 从当前城市找到最近的城市
        visited[nextCity-1] = true; // 标记为已访问（
        path[i] = nextCity; // 存储路径
        currentCity = nextCity; // 更新当前城市为找到的最近城市
    }
    printPathAndSum(path, adjMatrix);

    return 0;
}
