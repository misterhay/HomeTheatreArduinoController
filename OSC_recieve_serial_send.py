import serial #requires pySerial
import OSC #requires pyOSC
import time, threading


receiveAddress = ('0.0.0.0', 9000)
server = OSC.OSCServer(receiveAddress) #set up the OSC server
server.addDefaultHandlers() #not really necessary

def yamahaHandler(address, typetag, value, source): #a function for the Yamaha receiver
    #address should be /yamaha
    #typetag should be i
    #value should be the number of the command we want to send
    #source should be the IP address and port it came from
    message = str(value)[1] #convert the value to a string, but only x in [x]
    print value
    ser = serial.Serial(4, 9600) #open COM5 at 9600 baud and 8N1
    ser.write(message) #send the command that we received
    ser.write('/n') #new line character to make it go
    ser.close()

server.addMsgHandler("/yamaha", yamahaHandler) #the OSC address

print "When you've finished, use ctrl-c to quit"
threadingServer = threading.Thread(target = server.serve_forever)
threadingServer.start() #start the server thread we just defined

try :
    while 1 :
        time.sleep(5)

except KeyboardInterrupt :
    print "Closing OSCServer."
    server.close()
    print "Waiting for Server-thread to finish"
    threadingServer.join() #stop the thread
    print "Done"
