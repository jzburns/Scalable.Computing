computeEff <- function(p) {
	n <- 2^(6:20)
	Ts <- n
	Tp <-  n/p + (2 * log2(p))
	To <- p*Tp - Ts
	E <- round(1 / (1 + To / Ts), digits=2)
}

computeOhead <- function(n) {
	p <- c(1:32)
	Ts <- n
	Tp <- n/p + 2*p
	To <- p*Tp - Ts
}

computeS <- function(p, n) {
	Ts <- n
	Tp <- n/p + 2*p
	S <- Ts / Tp
}

options(width=150)
p <- 2^(0:14)
print(sapply(p, FUN=computeEff))
