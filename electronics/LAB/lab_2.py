r1 = 98.8 # ohm
r2 = 74.2 # ohm
vcc = 4.98 #V
mes_i = 28.63*10**(-3)

def ex_1():
	r_tot = r1 + r2
	I = vcc / r_tot
	print(f"I = {I}")
	return I

def ex_1_pd():
	r_i = (vcc-mes_i*(r1+r2))/mes_i
	print(f"r_i = {r_i}")
	return r_i

vecc = vcc
re1 = .765 * 10**(6)
re2 = .993 * 10**(6)

# pass lab room (append) floor number 30903
def ex_1_e():
	print(f"expe: {vcc * (re2/(re1+re2))}")

ex_1_e()

ex_1_pd()

calc_i = ex_1() * 10**(-3) #ma