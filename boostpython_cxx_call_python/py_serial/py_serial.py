# refer to http://www.instructables.com/id/Interface-Python-and-Arduino-with-pySerial/
# this script is meant for Interface between Python and Arduino With PySerial 
# by Hammock Boy in arduino

# edited by myf 2017/01/07

from time import sleep
import serial
ser = serial.Serial('/dev/ttyACM0', 9600) # Establish the connection on a specific port

def readLinefromSerialPort():
    line = ser.readline() # Read the newest output from the Arduino
    #sleep(0.1) # Delay for one tenth of a second
    return line


#while True:
#    print readLinefromSerialPort() # Read the newest output from the Arduino

