from PIL import Image
import numpy as np
from sys import stdout
from os import listdir

conversionlist = listdir('pics')
m = len(conversionlist)
for i in range(m):
	fileNameStr = conversionlist[i]
	fileStr = fileNameStr.split('.')[0]     #take off .txt
	writefile = fileStr + ".txt"
	i = Image.open('pics/%s' % fileNameStr)
	iar = np.asarray(i)
	avg = 0
	for eachrow in iar:
		for eachpixel in eachrow:
			a = 0
			a = int(a) + int(eachpixel[0:1])
			a = int(a) + int(eachpixel[1:2])
			a = int(a) + int(eachpixel[2:3])
			a = a / 3
			#print "%d" % a
			avg = avg + a
		#print "%d\n" % avg,

	print(avg)
	avg = avg / 1024
	print(avg)

	print writefile
	file = writefile

	fr = open(file, 'w')
	for eachrow in iar:
		for eachpixel in eachrow:
			total = int(eachpixel[0:1]) + int(eachpixel[1:2]) + int(eachpixel[2:3])
			total = total/3;
			if total < avg:
				fr.write('1')
			else:
				fr.write('0')
		fr.write('\n')
	fr.close()
