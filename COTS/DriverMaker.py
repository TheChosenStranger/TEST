import sys,os

def DriverFiles(driver_name):
	interface = open(driver_name+"_interface.h",'w')
	interface.close()
	private = open(driver_name+"_private.h",'w')
	private.close()
	config = open(driver_name+"_config.h",'w')
	private.close()
	register = open(driver_name+"_register.h",'w')
	register.close()
	program = open(driver_name+"_program.c",'w')
	program.write('#include "STD_TYPES.h"\n')
	program.write('#include "BIT_MATH.h"\n\n')
	program.write("#include "+'"'+driver_name+'_interface.h"\n')
	program.write("#include "+'"'+driver_name+'_register.h"\n')
	program.write("#include "+'"'+driver_name+'_config.h"\n')
	program.write("#include "+'"'+driver_name+'_private.h"\n')
	program.close()
	return


def DriverFolder():
	old_folders=os.listdir()
	last_folder_name = old_folders[len(old_folders)-1].split('_')[0]
	user_driver = input("What is the name of your driver  ")
	os.mkdir("0"+str(int(last_folder_name)+1)+"_"+user_driver)
	os.chdir("0"+str(int(last_folder_name)+1)+"_"+user_driver)
	DriverFiles(user_driver)
	return

def DriverCreator():
	print("Welcome to the Driver Creator")
	user_layer = input("In which layer does your driver exist  ")
	if user_layer.lower() == "mcal":
		os.chdir("01_MCAL")
	elif user_layer.lower() == "hal":
		os.chdir("02_HAL")
	elif user_layer.lower() == "app":
		os.chdir("03_APP")
	elif user_layer.lower() == "lib":
		os.chdir("04_LIB")
	elif user_layer.lower() == "srv":
		os.chdir("05_SRV")
	elif user_layer.lower() == "mem":
		os.chdir("06_MEM")
	elif user_layer.lower() == "os":
		os.chdir("07_OS")
	else:
		print("<"+user_layer +">"+" Wrong input: layer doesn't exist")
		return
	DriverFolder()
	return 

if __name__ == '__main__':
  DriverCreator() 