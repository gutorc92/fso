import sys
import numpy as np
import os
def main(argv=sys.argv):
	
	if(len(argv) >= 3):
		print(argv[1])
		print(argv[2])
		t = int(argv[1])
		j = int(argv[2])
		a = np.random.randint(400,size=(t,j))
		b = np.random.randint(400,size=(t,j))
		c = np.dot(a,b)
		name = "matrix" + str(argv[1]) + "_" + str(argv[2])	
		print(name)
		filename = os.path.join("/home/gustavo/Documents/fso/trabalho2/q3/matrixs/",name)
		np.savetxt(filename,a,fmt='%+3d')
		write(filename,t,j)
		name1 = "matrix" + str(argv[1]) + "_" + str(argv[2]) + "_2"	
		print(name1)
		filename = os.path.join("/home/gustavo/Documents/fso/trabalho2/q3/matrixs/",name1)
		np.savetxt(filename,b,fmt='%+3d')
		write(filename,t,j)
		name2 = "matrix" + str(argv[1]) + "_" + str(argv[2]) + "_result"
		print(name2)
		np.savetxt(os.path.join("/home/gustavo/Documents/fso/trabalho2/q3/matrixs/",name2),c,fmt='%3d')

def write(filename,i,j):
	text = str(i) + " " + str(j) + "\n"
	print(text)
	with open(filename, 'r') as original: data = original.read()
	with open(filename, 'w') as modified: modified.write(text + data)
	
if __name__=="__main__":
	main()
