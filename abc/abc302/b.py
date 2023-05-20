h, w = map(int, input().split())
s = [input() for _ in range(h)]

DX = [1, 0, -1, 0, 1, -1, -1, 1]
DY = [0, 1, 0, -1, 1, 1, -1, -1]
TARGET_WORD = 'snuke'

for i in range(h):
    for j in range(w):

        for dx, dy in zip(DX, DY):

            word = str()
            curr_y, curr_x = i, j

            for _ in range(len(TARGET_WORD)):
                if 0 <= curr_y < h and 0 <= curr_x < w:
                    word += s[curr_y][curr_x]
                else:
                    break
                curr_x += dx
                curr_y += dy

            if word != TARGET_WORD:
                continue

            curr_y, curr_x = i, j
            for _ in range(len(TARGET_WORD)):
                print(curr_y + 1, curr_x + 1)
                curr_x += dx
                curr_y += dy
