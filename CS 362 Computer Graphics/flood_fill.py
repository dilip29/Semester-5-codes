l, b = 200, 200
mat = [[0 for i in range(l)]for j in range(b)]
r = 10
x_c=int(input("enter the xc :"))
y_c=int(input("enter the yc :"))

def left_circle(xc, yc, r):
	x=0
	y=r
	p=1.25-r

	while x<=y:
		x=x+1
		if p<0:
			p=p+2*x+1
		else:
			y=y-1
			p=p+2*x+1-2*y
		mat[yc-y][xc-x]=255
		mat[yc-x][xc-y]=255
		mat[yc +x][xc - y] = 255
		mat[yc +y][xc -x] = 255

def right_circle(xc, yc, r):
	x=0
	y=r
	p=1.25-r

	while x<=y:
		x=x+1
		if p<0:
			p=p+2*x+1
		else:
			y=y-1
			p=p+2*x+1-2*y
		mat[yc-y][xc+x]=255
		mat[yc-x][xc+y]=255
		mat[yc +x][xc + y] = 255
		mat[yc +y][xc +x] = 255



def fill(x,y,color):
	if mat[x][y]==0:

		mat[x][y]=color
		fill(x+1,y,color)
		fill(x-1,y,color)
		fill(x,y-1,color)
		fill(x,y+1,color)

	else:
		return

mat[y_c-10][x_c-20-r]=255
mat[y_c+10][x_c-20+r]=255
mat[y_c+10][x_c+20-r]=255
mat[y_c-10][x_c+20+r]=255
mat[y_c][x_c-20]=255
mat[y_c][x_c+20]=255


for i in range(41):
	mat[y_c-20][x_c-20+i]=255
	mat[y_c+20][x_c-20+i]=255


left_circle(x_c-20,y_c-10,r)
left_circle(x_c+20,y_c+10,r)
right_circle(x_c+20,y_c-10,r)
right_circle(x_c-20,y_c+10,r)
#print(x_c,y_c)
fill(x_c,y_c,255)





file = open("test.pgm", 'w+')
file.write("P2\n" + str(l)+" " + str(b)+"\n" + "255\n")

for i in range(l):
    for j in range(b):
        file.write(str(mat[i][j])+" ")
    file.write("\n")

file.close()
