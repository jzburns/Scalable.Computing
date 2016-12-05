computeEff <- function(n) {
	p <- c(1:32)

	Ts <- n
	# change this to reflect the 
	# parallel complexity
	Tp <- n/p + 2*p
	To <- p*Tp - Ts
	
	E <- 1 / (1 + To / Ts)
}

plot(computeEff(64), type='b', pch=18, xlab="p", ylab="E")
legend("topright", inset=.05, title="input size n",
   c("64","192","320", "512"), pch=18:21)
lines(computeEff(192), type='b', pch=19)
lines(computeEff(320), type='b', pch=20)
lines(computeEff(512), type='b', pch=21)
lines(computeEff(2048), type='b', pch=22)
