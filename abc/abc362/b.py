xa, ya = map(int, input().split())
xb, yb = map(int, input().split())
xc, yc = map(int, input().split())

ab = (xa - xb)**2 + (ya - yb)**2
bc = (xb - xc)**2 + (yb - yc)**2
ca = (xc - xa)**2 + (yc - ya)**2

print('Yes' if ab + bc == ca or bc + ca == ab or ca + ab == bc else 'No')
