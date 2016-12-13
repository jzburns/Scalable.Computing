# scaling equation of efficiency

p <- 2^(0:14)
n <- 2^(6:20)

computeEff <- function(p) {
	Ts <- n
	Tp <-  n/p + (2 * log2(n))
	To <- p*Tp - Ts
	E <- round(1 / (1 + To / Ts), digits=2)
}

computeEff2 <- function(p) {
        Ts <- n^3
        Tp <-  n^3/p + (5 * p * n)
        To <- p*Tp - Ts
        E <- round(1 / (1 + To / Ts), digits=2)
}

computeOhead <- function(p) {
	Ts <- n
	Tp <-  n/p + (2 * log2(n))
	To <- round(p*Tp - Ts, digits=2)
	To <- p*Tp - Ts
}

computeOhead2 <- function(n) {
        Ts <- n^3
        Tp <-  n^3/p + (5 * p * n)
        To <- round(p*Tp - Ts, digits=2)
}

computeS <- function(p, n) {
	Ts <- n
	Tp <- n/p + 2*p
	S <- Ts / Tp
}

#### plotting the efficiency
m <- sapply(p, FUN=computeEff)
rownames(m) <- n
colnames(m) <- p
matplot(main="Linear", rownames(m), m, ylab="E", xlab="n", type="b", log="x")

x11()
m <- sapply(p, FUN=computeEff2)
rownames(m) <- n
colnames(m) <- p
matplot(main="Cubic", rownames(m), m, ylab="E", xlab="n", type="b", log="x")

#### plotting the overhead
x11()
m <- sapply(p, FUN=computeOhead)
rownames(m) <- n
colnames(m) <- p
# print(m)
matplot(main="Linear", rownames(m), m, xlab="n", ylab="To", type="b", log="xy")
lines (n, n)

x11()
m <- sapply(p, FUN=computeOhead2)
rownames(m) <- n
colnames(m) <- p
matplot(main="Cubic", rownames(m), m, xlab="n", ylab="To", type="b", log="xy")
lines (n, n^3)


