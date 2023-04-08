n, c = map(int, input().split())
a = [int(input()) - 1 for _ in range(n)]

ans = 0
selected_color = None
for i in range(2):
    color_cnts = [0] * 10
    for j, color in enumerate(a):
        if j % 2 == i:
            continue
        color_cnts[color] += 1
    total = sum(color_cnts)
    if selected_color is not None:
        color_cnts[selected_color] = 0
    ans += (total - max(color_cnts)) * c
    selected_color = color_cnts.index(max(color_cnts))

selected_color = None
tmp_ans = 0
for i in [1, 0]:
    color_cnts = [0] * 10
    for j, color in enumerate(a):
        if j % 2 == i:
            continue
        color_cnts[color] += 1
    total = sum(color_cnts)
    if selected_color is not None:
        color_cnts[selected_color] = 0
    tmp_ans += (total - max(color_cnts)) * c
    selected_color = color_cnts.index(max(color_cnts))

print(min(ans, tmp_ans))
