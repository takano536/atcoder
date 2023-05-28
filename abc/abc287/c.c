#include <stdio.h>

#define MAX_NODE_NUM 200000
#define MAX_EDGE_NUM 2

int N, M;

int graph[MAX_NODE_NUM][MAX_EDGE_NUM];

int node_count = 0;
int visited[MAX_NODE_NUM] = {0};

void dfs(int start) {
    int i;
    int next;

    visited[start] = 1;
    node_count++;

    for (i = 0; i < MAX_EDGE_NUM; i++) {
        next = graph[start][i];

        if (next == -1) {
            continue;
        }
        if (visited[next]) {
            continue;
        }

        dfs(next);
    }

    return;
}

int main(void) {
    int i, j;
    int u, v;

    int satisfies = 1;    // パスグラフであるかどうか
    int is_addable;       // 辺を受け取るときに使用 グラフに辺を追加できるかどうか

    // グラフを-1で初期化
    for (i = 0; i < MAX_NODE_NUM; i++) {
        for (j = 0; j < MAX_EDGE_NUM; j++) {
            graph[i][j] = -1;
        }
    }

    scanf("%d%d", &N, &M);

    // 辺がピッタリ(頂点-1)個か
    if (M != N - 1) {
        satisfies = 0;
    }

    // 辺を受け取りながら頂点の次数が2以下か判定
    for (i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        u--, v--;

        is_addable = 0;
        for (j = 0; j < MAX_EDGE_NUM; j++) {
            // u -> v 方向の追加
            if (graph[u][j] != -1) {
                continue;
            }
            graph[u][j] = v;
            is_addable = 1;
            break;
        }
        for (j = 0; j < MAX_EDGE_NUM; j++) {
            // v -> u 方向の追加
            if (graph[v][j] != -1) {
                continue;
            }
            graph[v][j] = u;
            is_addable = 1;
            break;
        }
        if (!is_addable) {
            // 辺を追加できなかった場合
            satisfies = 0;
        }
    }

    // 頂点0からdfsを実施し、グラフが連結かを確認
    dfs(0);

    if (node_count != N) {
        // 頂点0から連結な頂点を数えた結果、Nと一致しない = グラフが連結でない
        satisfies = 0;
    }

    puts(satisfies ? "Yes" : "No");
    return 0;
}