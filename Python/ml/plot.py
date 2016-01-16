import scipy as sp
data = sp.genfromtxt("web_traffic.tsv", delimiter="\t")

x = data[:,0]
y = data[:,1]

x = x[~sp.isnan(y)]
y = y[~sp.isnan(y)]

import matplotlib.pyplot as plt
# plot the (x,y) points with dots of size 10
plt.scatter(x, y, s=10)
plt.title("Web traffic over the last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*24 for w in range(10)],
['week %i' % w for w in range(10)])
plt.autoscale(tight=True)
# draw a slightly opaque, dashed grid
plt.grid(True, linestyle='-', color='0.1')

fp1, residuals, rank, sv, rcond = sp.polyfit(x, y, 1, full=True)
f1 = sp.poly1d(fp1)

fx = sp.linspace(0,x[-1],1000)
plt.plot(fx, f1(fx), linewidth=4)
plt.legend(["d=%i"%f1.order], loc="upper left")

fp53, residuals, rank, sv, rcond = sp.polyfit(x, y, 53, full=True)
f53 = sp.poly1d(fp53)
plt.plot(fx, f53(fx), linewidth=4)
plt.legend(["d=%i"%f53.order], loc="upper left")

inflection=3.5*7*24
xa = x [:inflection]
ya = y[:inflection]
xb = x[inflection:]
yb = y[inflection:]






plt.show()