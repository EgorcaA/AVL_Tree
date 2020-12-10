import csv
import matplotlib.pyplot as plt
import numpy as np

xwr = []
ywr = []
c = 0
xer = []
yer = []
with open('write.csv') as File:
    reader = csv.reader(File, delimiter=',', quotechar=',',
                        quoting=csv.QUOTE_MINIMAL)
    for row in reader:
        a = row[0].split()
        xwr.append(float(a[0]))
        ywr.append(float(a[1]))

with open('erase.csv') as File:
    reader = csv.reader(File, delimiter=',', quotechar=',',
                        quoting=csv.QUOTE_MINIMAL)
    for row in reader:
        a = row[0].split()
        xer.append(float(a[0]))
        yer.append(float(a[1]))





plt.plot(xwr, ywr, 'ro' , label='write')
plt.plot( xer, yer  , 'bx', label='erase')
plt.xlabel('число элементов в дереве')
plt.ylabel('время')
plt.title('AVL дерево')
plt.legend()



plt.show();
print("ye")
