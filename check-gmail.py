import serial, sys, feedparser
#Settings - Change these to match your account details

USERNAME="siliconchef2013@gmail.com"
PASSWORD="hackbright"
PROTO="https://"
SERVER="mail.google.com"
PATH="/gmail/feed/atom"
SERIALPORT = "/dev/cu.usbserial-AD01TBUF" # Arduino serial port

try:
	ser = serial.Serial(SERIALPORT, 9600)
except serial.SerialException:
	print "no device connected - exiting"
	sys.exit()

newmails = int(feedparser.parse(PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH)["feed"]["fullcount"])
   
# Output data to serial port
if newmails > 0: 
	ser.write("m")
	print "some mail"
else: 
	ser.write("n")
	print "no mail" 
#print data to terminal


# Close serial port
ser.close()