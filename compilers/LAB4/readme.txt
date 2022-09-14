	██╗      █████╗ ██████╗     ██╗  ██╗
	██║     ██╔══██╗██╔══██╗    ██║  ██║
	██║     ███████║██████╔╝    ███████║
	██║     ██╔══██║██╔══██╗    ╚════██║
	███████╗██║  ██║██████╔╝         ██║
	╚══════╝╚═╝  ╚═╝╚═════╝          ╚═╝
	Jason Ivey, 2022, 
		for NMSU's CS370 with Dr. Shaun Cooper.

This is a lab for the class cs370, specifically LAB4. In this lab, we combine the work in LAB2_2 (a calculator) and the work in LAB3 to make a working symbol table of vars as well as an integer declaration system. 

	> The syntax for this is quite hard to follow at first but the logic is simple:
	> Encounter a new variable
	> put it at address 0
	> increment addr
	> store address and variable name in a symbol table
	> use address and variable name to reference this variable now

Uage:
	make
	make run