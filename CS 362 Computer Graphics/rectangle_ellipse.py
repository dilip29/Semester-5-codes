from math import sqrt
l, h = 500, 500
mat = [[0 for x in range(l)]for y in range(h)]

xc = int(input("enter the xc"))
yc = int(input("enter the yc"))
ry, rx, a, b ,shx=  20, 10, 100, 80,0.5

for i in range(500):
    mat[yc+50][i]=255

for i in(range(2*ry)):
    mat[yc-ry+i][xc-int(a/2)-int(shx*i)] = 255
    mat[yc-ry+i][xc+int(a/2)-int(shx*i)] = 255
    mat[yc - ry + i+100][xc - int(a / 2)-int(shx*2*ry) + int(shx * i)] = 255
    mat[yc - ry + i+100][xc + int(a / 2) -int(shx*2*ry) + int(shx * i)] = 255


for j in(range(a)):
    mat[yc-ry][xc -int(a/2)+j] = 255
    mat[yc + ry][xc -int(a/2)+j-int(shx*i)] = 255
    mat[yc-ry+100][xc -int(a/2)+j-int(shx*2*ry)] = 255
    mat[yc + ry+100][xc -int(a/2)+j] = 255



def ellipse(xc, yc, rx, ry):
    x, y = 0, ry
    p1 = float(((rx*rx)/4) + (ry*ry) - (rx*rx*ry))
    while(x*ry*ry) <= (y*rx*rx):

        mat[yc-y][xc+x] = 255
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




xc = xc -int(shx*ry)
ellipse(xc, yc, rx, ry)
ellipse(xc, yc+100, rx, ry)
file = open("test.pgm", 'w+')
file.write("P2\n" + str(l)+" " + str(h)+"\n" + "255\n")

for i in range(l):
    for j in range(h):
        file.write(str(mat[i][j])+" ")
    file.write("\n")

file.close()

