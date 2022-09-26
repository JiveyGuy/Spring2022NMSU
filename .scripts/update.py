import datetime
import getpass
import socket 
import os
import time

def make_comment():
	now = datetime.date.today()
	time_formatted = now.strftime("%B %d, %Y")
	user_name = getpass.getuser()
	host_name = socket.gethostname()

	comment = f"""
Update to school dir on {time_formatted}:
	written by {user_name} on {host_name}
	"""

	return comment
def do_command(cmd):
	return os.system(cmd)

def full_update():
	cmnt = make_comment()
	print(do_command("git add -A"))
	time.sleep(1)
	print(do_command(f"git commit -m \"{cmnt}\""))
	time.sleep(1)
	print(do_command("git push"))

full_update()
