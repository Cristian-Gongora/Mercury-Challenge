import serial, time

arduino = serial.Serial('/dev/ttyACM0',baudrate = 9600, timeout=5)
arduino.flushInput()

print("Starting!")

#Inicializando VARIABLES
ref = 25

#constantes del controlador
kd = float(1)
kp = float(0.5)
ki = float(0.1)
Ts = float(0.02)

tic = time.time()
error_1=0.0
Ui_1=0.0
derivada=0.0
Up=Ud=Ui=0.0
error=0.0
dist=0.0
Ui=0.0
def separar(data):
    global kd,kp,ki,Ts,tic,error_1,Ui_1,derivada,Up,Ud,Ui,error,dist
    if "Distancia" in data:
        label = data.split(":")
        dist =float (label[1])
        print "Distancia US: " + str(dist)

    error = -ref + dist
    Up = float(kp*error)
    derivada = (error - error_1)/Ts
    Ud = kd*derivada
    Ui = Ts*ki*(error) + Ui_1
    U = Up  + Ud +Ui
    Ui_1 = Ui
    error_1 = error
    if U > 255:
        U = 255
    if U < -255:
        U = -255
    U = U + 255
    arduino.write(str(U))
    print U
    toc = time.time()
    dt = toc - tic
    while dt < Ts:
        toc = time.time()
        dt = toc - tic
if __name__ == "__main__":
    print('Inicializando Sensor ... ')
    while(True):
        try:
                #arduino.write("1")
                data_Arduino=arduino.readline()
                separar(data_Arduino)
                #control()
        except KeyboardInterrupt:
                print "Algo va mal :("
                break
arduino.close()
