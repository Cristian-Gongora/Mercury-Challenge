# Mi primer programa con python
# Clase Electronica Digital III

import socket, fcntl, smtplib, struct
import time

# MAIL DATA
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

def getIpAddress(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(s.fileno(),0x8915,struct.pack('256s', ifname[:15]))[20:24])

def sendEmail(toaddr,subject,body,fileData):
	msg = MIMEMultipart()
	if(fileData!=''):
		msg.attach(MIMEText(file(fileData).read()))
	fromaddr='@gmail.com'
	msg['From'] = fromaddr
	msg['To'] = toaddr
	msg['Subject'] = subject
	msg.attach(MIMEText(body, 'plain'))
	mailer = smtplib.SMTP('smtp.gmail.com', 587)
	mailer.starttls()
	mailer.login(fromaddr, "password")
	text = msg.as_string()
	mailer.sendmail(fromaddr, toaddr, text)
	mailer.quit()

if __name__ == "__main__":
    time.sleep(5)
    print ("Hola, Bienvenido a Rpi3.... ")
    if1 = 'wlan0'
    myIp = getIpAddress(if1)
    print ("La direccion Ip de esta Rpi3 es: ") + str(myIp)
    body = "Ip:" + str(myIp)
    sendEmail('@gmail.com','Hola, esta es mi Ip',body,'')
