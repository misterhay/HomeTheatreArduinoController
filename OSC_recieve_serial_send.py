import serial #requires pySerial
import OSC #requires pyOSC
import time, threading


receiveAddress = ('127.0.0.1', 901)
server = OSC.OSCServer(receiveAddress) #set up the OSC server
server.addDefaultHandlers() #not really necessary

def yamahaHandler(address, typetag, value, source): #a function for the Yamaha receiver
    #address should be /yamaha
    #typetag should be i
    #value should be the number of the command we want to send
    #source should be the IP address and port it came from
    message = str(value) #convert the value to a string 
    ser = serial.Serial(7, 9600) #open COM8 at 9600 baud and 8N1
    ser.write(value) #send the command that we received
    #ser.write('1') #toggle power
    ser.write('/n') #new line character to make it go
    ser.close()

server.addMsgHandler("/yamaha", yamahaHandler) #the OSC address

print "use ctrl-c to quit"
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
