#------------------------Q3------------------------
# Practice running the following examples.

my_list = [1, 2, 3]
print(f'My list is: {my_list}')

#------------------------Q5------------------------

# In question (1) we answered questions about cores
# and memory for the Anvil clusters. To do so, we 
# needed to perform some arithmetic. Instead of 
# using a calculator (or paper, or mental math for 
# you good-at-mental-math folks), write these 
# calculations using R and Python, in separate code 
# cells.

(cores_a, mem_a) = ( 1000 * 128, 1000*256)
(cores_b, mem_b) = ( 32 * 128, 32*1)
(cores_c, mem_c) = ( 16 * 128, 16*512)

print(f"""
A: total cores = {cores_a}, total memory = {mem_a} GB
B: total cores = {cores_b}, total memory = {mem_b} TB 
C: total cores = {cores_c}, total memory = {mem_c} GB 
""")