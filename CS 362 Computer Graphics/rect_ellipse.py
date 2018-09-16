l, h = 50, 50
mat = [[0 for x in range(l)]for y in range(h)]
# print(mat)
xc, yc, rx, ry, a, b = 25, 25, 5, 10, 20, 20

for i, j in zip(range(2*ry), range(a)):

    mat[yc-ry+i][xc-int(a/2)] = 255
    mat[yc-ry+i][xc+int(a/2)] = 255
    mat[yc-ry][xc - int(a/2)+j] = 255
    mat[yc + ry][xc - int(a/2)+j] = 255

    # print(i, j)
shx = sqrt ((b*b) - (4*ry*ry))/(2*ry)
def ellipse(xc, yc, rx, ry):
    x, y = 0, ry
    p1 = float(((rx*rx)/4) + (ry*ry) - (rx*rx*ry))
    while(x*ry*ry) <= (y*rx*rx):

        mat[yc-y][xc+x  ] = 255
        mat[yc - y][xc - x] = 255
        mat[yc + y][xc + x] = 255
        mat[yc + y][xc - x] = 255

        x = x+1
        if p1 < 0:
            p1 = p1 + (2*ry*ry*x) + (ry*ry)
        else:
            y = y - 1
            p1 = p1 + (2*ry*ry*x) - (2*rx*rx*y) + (ry*ry)

# region 2
    p2 = float((ry*ry) * (x+0.5)*(x+0.5)) + (rx*rx) * ((y-1)*(y-1)) - (ry*ry*rx*rx)

    while y >= 0:
        mat[yc-y][xc+x] = 255
        mat[yc - y][xc - x] = 255
        mat[yc + y][xc + x] = 255
        mat[yc + y][xc - x] = 255

        y = y - 1
        if p2 < 0:
            x = x + 1
            p2 = p2 + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx
        else:
            p2 = p2 - 2 * rx * rx * y + rx * rx





'''
rx = input("enter the rx")
ry = input("enter the ry")
a = input("enter the a")
b = input("enter the b")
xc = input("enter the xc")
yc = input("enter the yc")
'''
ellipse(xc, yc, rx, ry)

file = open("test.pgm", 'w+')
file.write("P2\n" + str(l)+" " + str(h)+"\n" + "255\n")

for i in range(l):
    for j in range(h):
        file.write(str(mat[i][j])+" ")
    file.write("\n")

# print(mat[49][49])
file.close()





