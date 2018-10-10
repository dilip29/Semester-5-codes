class Edge(object):
    def __init__(self, x1, y1, x2, y2, flag):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.flag = flag

# line drawing function created
def line_draw(x1, y1, x2, y2):
    dx = (x2 - x1)
    dy = (y2 - y1)
    if abs(dx) >= abs(dy):
        step = abs(dx)
    else:
        step = abs(dy)

    dx = dx / step
    dy = dy / step

    x, y, i = x1, y1, 1
    while i <= step:
        mat[int(y)][int(x)]= 128
        x = x + dx
        y = y + dy
        i = i + 1


def fill(x1, y1, x2, y2):
	for i in range(int(x1),int(x2),1):
		mat[int(y1)][int(i)]=255

l, b = 500, 500
mat = [[0 for i in range(l)]for j in range(b)]

n = int(input("enter the no. of vertices"))
xc = int(input("enter the x of center"))
yc = int(input("enter the y of center"))
r = int(input("enter the radius"))


edge = []
#x = [50 , 80,100,160,90,70,40]


#y = [50,80,40,100,120,110,140]
x=[xc-r,int(xc-r/2),int(xc+r/2),xc+r,int(xc+r/2),int(xc-r/2)]
y=[yc,int(yc-0.867*r),int(yc-0.867*r),yc,int(0.867*r+yc),int(0.867*r+yc)]

y_min= min(y)
y_max= max(y)



# for creating the edges
for i in range(n-1):
    edge.append(Edge(x[i], y[i], x[i+1], y[i+1], 0))
edge.append(Edge(x[n-1], y[n-1], x[0], y[0], 0))


# y1 > y2
for i in range(n):
	if edge[i].y1 < edge[i].y2:
		temp=edge[i].x1
		edge[i].x1=edge[i].x2
		edge[i].x2=temp
		temp=edge[i].y1
		edge[i].y1=edge[i].y2
		edge[i].y2=temp		


for i in range(n):
    line_draw(edge[i].x2, edge[i].y2, edge[i].x1, edge[i].y1)

# sorting the edges in the order y1,y2,x1
for j in range(n-1):
	for i in range(n-1):
		if edge[i].y1 < edge[i+1].y1:
			temp1=edge[i+1]
			edge[i+1]=edge[i]
			edge[i]=temp1
		if edge[i].y1 == edge[i+1].y1:
			if edge[i].y2 < edge[i+1].y2:
		    		temp1 = edge[i + 1]
		    		edge[i + 1] = edge[i]
		    		edge[i] = temp1
		if edge[i].y2 == edge[i+1].y2:
			if edge[i].x1 < edge[i+1].x1:
				temp1 = edge[i + 1]
				edge[i + 1] = edge[i]
				edge[i] = temp1		
'''
for i in range(n):
	print(str(edge[i].x1)+" "+str(edge[i].y1) +" " +str(edge[i].x2)+" "+str(edge[i].y2))
'''
inter_x, m = [], []

# store the slopes of the edges
for i in range(n):
	dx = edge[i].x2 - edge[i].x1
	dy = edge[i].y2 - edge[i].y1
	if dy == 0:
		m.append(int(0))
	else:
		m.append(dx/dy)
	

	inter_x.append(edge[i].x1)




yy=y_max
'''
for i in range(n):
	x_int.append(int(0))
'''

while yy > y_min:
	for i in range(n):
		if edge[i].y1>=yy and edge[i].y2<yy:
		    edge[i].flag = 1
		else:
		    edge[i].flag = 0
	j=0
	x_int=[]
	for i in range(n):
		if edge[i].flag == 1:
			if yy == edge[i].y1:
				x_int.append(edge[i].x1)
				j=j+1
			else:
		        	x_int.append(inter_x[i] - m[i])
		        	inter_x[i]=x_int[j]
		        	j=j+1

	x_int.sort()

	i=0
	while i<j:
		fill(x_int[i], yy, x_int[i+1], yy)
		i=i+2

	yy = yy - 1



file = open("test.pgm", 'w+')
file.write("P2\n" + str(l)+" " + str(b)+"\n" + "255\n")

for i in range(l):
    for j in range(b):
        file.write(str(mat[i][j])+" ")
    file.write("\n")

file.close()
