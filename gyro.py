import serial
import mouse
from time import sleep

port="COM14"

ard=0

try:
	ard=serial.Serial(port,9600)
except Exception:
	ard=serial.Serial("COM3",9600)

while(1):
    a=ard.readline().decode()
    
    cur=a.split("\t")
    cur[0]=int(cur[0])
    cur[1]=int(cur[1])
    cur[2]=int(cur[2][:-2])

    k=mouse.get_position()

    mouse.move(k[0]-cur[0]/100,k[1]-cur[1]/100)

    if(cur[2]==2):
    	mouse.click(button='left')
    elif(cur[2]==1):
    	mouse.click(button='right')
    #elif(cur[2]==3):
    #	mouse.double_click()
    #print(mouse.get_position())
    
    sleep(0.001)
