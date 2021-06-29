from time import sleep
import serial
ser = serial.Serial('/dev/ttyACM0', 115200) # Establish the connection on a specific port
while True:
	p = float(ser.readline())
	print (p)
