#------------------------Q2------------------------
# **What is the name of the node on Anvil that you are running on?**
system("hostname", intern=TRUE)


#------------------------Q5------------------------
# From: https://stackoverflow.com/questions/13023274/how-to-do-printf-in-r
printf <- function(...) invisible(print(sprintf(...)))

cores_a = 1000 * 128
cores_b = 32 * 128
cores_c = 16 * 128

mem_a =  1000*256
mem_b = 32*1
mem_c = 16*512

printf(c("A: total cores ==%.2f", ", total memory =%.2f"), c(cores_a, mem_a))
printf(c("B: total cores ==%.2f", ", total memory =%.2f"), c(cores_b, mem_b))
printf(c("C: total cores ==%.2f", ", total memory =%.2f"), c(cores_c, mem_c))


#------------------------Q6------------------------
dat <- read.csv("/anvil/projects/tdm/data/disney/flight_of_passage.csv")

head(dat)