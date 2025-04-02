#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_CITIES 5
#define INF INT_MAX

// 找到距离当前城市最近的未访问城市
int findNearestCity(int adjMatrix[], bool visited[], int currentCity, int numCities) {
    int nearestCity = -1;
    int minDist = INF;

    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && adjMatrix[currentCity][i] != INF && adjMatrix[currentCity][i] < minDist) {
            minDist = adjMatrix[currentCity][i];
            nearestCity = i;
        }
    }

    return nearestCity;
}

// 打印路径和路径之和
void printPathAndSum(int path[], int adjMatrix[], int numCities) {
    int totalDist = 0;
    printf("Path: %d", path[0]);
    for (int i = 1; i < numCities; i++) {
        printf(" -> %d", path[i]);
        totalDist += adjMatrix[path[i-1]][path[i]];
    }
    printf(" -> %d\n", path[0]); // 回到起始城市
    totalDist += adjMatrix[path[numCities-1]][path[0]];
    printf("Total Distance: %d\n", totalDist);
}

int main() {
    // 邻接矩阵，INF表示两个城市之间不可达
    int adjMatrix[NUM_CITIES][NUM_CITIES] = {
        {0, 10, INF, 30, 100},
        {10, 0, 50, INF, INF},
        {INF, 50, 0, 20, 10},
        {30, INF, 20, 0, 60},
        {100, INF, 10, 60, 0}
    };

    // 访问标记数组
    bool visited[NUM_CITIES] = {false};
    // 存储路径
    int path[NUM_CITIES];
    // 起始城市
    int currentCity = 0;
    visited[currentCity] = true;
    path[0] = currentCity;

    // 使用最近邻点策略构建路径
    for (int i = 1; i < NUM_CITIES; i++) {
        int nextCity = findNearestCity(adjMatrix, visited, currentCity, NUM_CITIES);
        visited[nextCity] = true;
        path[i] = nextCity;
        currentCity = nextCity;
    }

    // 打印路径和路径之和
    printPathAndSum(path, (int (*)[NUM_CITIES])adjMatrix, NUM_CITIES);

    return 0;
}
