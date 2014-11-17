#
#
# plotting the efficiency of functions

setwd('/home/jburns/Scalable.Computing/week10')

computeEff <- function(n) {
	p <- c(1:32)

	Ts <- n
	Tp <- n/p + 2*log2(p)
	To <- p*Tp - Ts
	
	E <- 1 / (1 + To / Ts)

	return (E)
}

plot(computeEff(64), type='b', pch=18)
legend("topright", inset=.05, title="input size n", c("64","192","320", "512"), pch=18:21)
lines(computeEff(192), type='b', pch=19)
lines(computeEff(320), type='b', pch=20)
lines(computeEff(512), type='b', pch=21)

