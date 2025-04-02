#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_CITIES 5
#define INF INT_MAX
#define START_CITY 1 // ������ʼ����Ϊ1

// ����һ������������Ѱ�Ҿ��뵱ǰ��������ġ���δ���ʵĳ���
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
    printf("Path: %d", path[0]); // ��ʼ����
    for (int i = 1; i < NUM_CITIES; i++) {
        printf(" -> %d", path[i]); // �м����
        pathSum += adjMatrix[path[i-1]-1][path[i]-1]; // �������ʱ��1
    }
    pathSum += adjMatrix[path[NUM_CITIES-1]-1][path[0]-1]; //
    printf(" -> %d", START_CITY); // ����ص����Ĳ���
    printf("\n"); // ����
    printf("Path Sum : %d\n", pathSum); // ��ӡ��·������
}

int main() {
    int adjMatrix[NUM_CITIES][NUM_CITIES] = {
        {0, 3, 3, 2, 6}, //
        {3, 0, 7, 3, 2},
        {3, 7, 0, 2, 5},
        {2, 3, 2, 0, 3},
        {6, 2, 5, 3, 0}
    };

    // ����һ�����飬���ڱ�ǳ����Ƿ��ѱ�����
    bool visited[NUM_CITIES] = {false};
    // ����һ�����飬���ڴ洢����·��
    int path[NUM_CITIES];
    int currentCity = START_CITY;
    visited[currentCity-1] = true;
    path[0] = currentCity; // �洢��ʼ���б��

    // ʹ������ڵ���Թ���·��
    for (int i = 1; i < NUM_CITIES; i++) {
        int nextCity = findNearestCity(adjMatrix, visited, currentCity); // �ӵ�ǰ�����ҵ�����ĳ���
        visited[nextCity-1] = true; // ���Ϊ�ѷ��ʣ�
        path[i] = nextCity; // �洢·��
        currentCity = nextCity; // ���µ�ǰ����Ϊ�ҵ����������
    }
    printPathAndSum(path, adjMatrix);

    return 0;
}
