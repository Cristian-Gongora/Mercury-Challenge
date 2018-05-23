import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)

print("Starting!")

while True:
      comando = raw_input('Introduce un comando: ') #Input
      arduino.write(comando) #Mandar un comando hacia Arduino
      if comando == 'w':
            print('ADELANTE')
      elif comando == 's':
            print('ATRAS')
      elif comando == 'a':
            print('IZQUIERDA')
      elif comando == 'd':
            print('DERECHA')
      elif comando == 'i':
            print('LUZ ON')
      elif comando == 'o':
            print('LUZ OFF')
      elif comando == 'p':
            print('DISTACIA')

arduino.close() #Finalizamos la comunicacion
