# scaling equation of efficiency

p <- 2^(0:12)
n <- 2^(6:20)

computeEff <- function(p) {
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

m <- sapply(p, FUN=computeEff)
rownames(m) <- n
colnames(m) <- p
print(m)
matplot(rownames(m), m, type="b", log="x")
