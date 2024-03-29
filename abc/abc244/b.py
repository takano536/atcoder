n = int(input())
t = input()

DIR_CHARS = 'RDLU'
DIR_VECS = {
    'R': (1, 0),
    'D': (0, -1),
    'L': (-1, 0),
    'U': (0, 1)
}
curr_coord = [0, 0]
curr_dir_idx = 0
for c in t:
    if c == 'R':
        curr_dir_idx = (curr_dir_idx + 1) % len(DIR_CHARS)
    if c == 'S':
        curr_coord[0] += DIR_VECS[DIR_CHARS[curr_dir_idx]][0]
        curr_coord[1] += DIR_VECS[DIR_CHARS[curr_dir_idx]][1]
print(' '.join(str(coord) for coord in curr_coord))
