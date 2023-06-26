#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DIR_CNT 4

#define MAX_WIDTH      (50 + 1)
#define MAX_HEIGHT     (50 + 1)
#define MAX_QUEUE_SIZE (MAX_WIDTH * MAX_HEIGHT * DIR_CNT + 1)

typedef struct coord_t {
    int h;
    int w;
} coord_t;

typedef struct queue_t {
    int head_idx;
    int tail_idx;
    coord_t array[MAX_QUEUE_SIZE];
} queue_t;

void init(queue_t *);
bool empty(queue_t *);
void push(queue_t *, coord_t);
coord_t top(queue_t *);
void pop(queue_t *);

int main(void) {
    const int H_DIR[DIR_CNT] = {0, 0, 1, -1};
    const int W_DIR[DIR_CNT] = {1, -1, 0, 0};

    int i, j;

    int h, w;
    char s[MAX_HEIGHT][MAX_WIDTH];

    int ans = 0;

    int dist[MAX_HEIGHT][MAX_WIDTH];

    queue_t que;
    coord_t prev_pos;
    coord_t next_pos;

    scanf("%d%d", &h, &w);
    for (i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }

    init(&que);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            dist[i][j] = -1;
        }
    }

    push(&que, (coord_t){0, 0});
    dist[0][0] = 0;

    while (!empty(&que)) {
        prev_pos = top(&que);
        pop(&que);

        for (i = 0; i < DIR_CNT; i++) {
            next_pos = prev_pos;
            next_pos.h += H_DIR[i];
            next_pos.w += W_DIR[i];

            if (next_pos.h < 0 || next_pos.h >= h || next_pos.w < 0 || next_pos.w >= w) {
                continue;
            }

            if (s[next_pos.h][next_pos.w] == '#') {
                continue;
            }

            if (dist[next_pos.h][next_pos.w] != -1) {
                continue;
            }

            push(&que, next_pos);
            dist[next_pos.h][next_pos.w] = dist[prev_pos.h][prev_pos.w] + 1;
        }
    }

    if (dist[h - 1][w - 1] == -1) {
        puts("-1");
        return 0;
    }

    ans = -(dist[h - 1][w - 1] + 1);
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

void init(queue_t *que) {
    que->head_idx = 0;
    que->tail_idx = -1;
}

bool empty(queue_t *que) {
    return ((que->tail_idx + 1) % MAX_QUEUE_SIZE == que->head_idx);
}

void push(queue_t *que, coord_t input) {
    if ((que->tail_idx + 2) % MAX_QUEUE_SIZE == que->head_idx) {
        puts("error: not enough capacity");
        exit(EXIT_FAILURE);
    }

    que->array[(que->tail_idx + 1) % MAX_QUEUE_SIZE] = input;
    que->tail_idx = (que->tail_idx + 1) % MAX_QUEUE_SIZE;
}

coord_t top(queue_t *que) {
    return que->array[que->head_idx];
}

void pop(queue_t *que) {
    if (empty(que)) {
        puts("error: queue is empty");
        exit(EXIT_FAILURE);
    }

    que->head_idx = (que->head_idx + 1) % MAX_QUEUE_SIZE;
}
