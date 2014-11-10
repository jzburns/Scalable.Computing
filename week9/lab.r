# set the wd

setwd ('/home/jburns/Scalable.Computing/week9')

n <- 512

# plotting efficiency
# for a parallel algorithm n / p * 2 log2(p)

plot (1 / ( 1 + (2 * p * log2(p) / n) ) , type='b')

# for n = 1024

n <- 1024
lines (1 / ( 1 + (2 * p * log2(p) / n) ) , type='b', pch=19)

n <- 4096
lines (1 / ( 1 + (2 * p * log2(p) / n) ) , type='b', pch=22)
