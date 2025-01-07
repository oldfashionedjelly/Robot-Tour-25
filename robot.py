import encoder
from machine import Pin, PWM
import time

# Test with encoder on pins 2 and 3:
leftEncoder = encoder.Encoder(0, Pin(16))
rightEncoder = encoder.Encoder(1, Pin(18))

class Motor:
    def __init__(self, ena, enb, ina, encoder, cap=100):
        self.ena = Pin(ena, Pin.OUT)
        self.enb = Pin(enb, Pin.OUT)
        self.ina = PWM(Pin(ina))
        self.encoder = encoder
        self.ina.freq(20000)
        self.cap = cap

    
    def move(self, speed):
        speed = max(-self.cap, speed)
        speed = min(self.cap, speed)
        if (speed < 0):
            self.ena.value(0)
            self.enb.value(1)
            self.ina.duty_u16(int(65535*(speed*-1)/100))
        else:
            self.ena.value(1)
            self.enb.value(0)
            self.ina.duty_u16(int(65535*(speed)/100))
            
    def stop(self):
        self.ena.value(0)
        self.enb.value(0)
        self.ina.duty_u16(0)
        

leftM = Motor(12, 13, 8, leftEncoder, 93)
rightM = Motor(10, 11, 9, rightEncoder)

def move(ticks, timeout=1.5):
    kP_L = 40
    kP_R = 40
    k_I = 150
    rStop = False
    lStop = False
    leftEncoder.position(0)
    rightEncoder.position(0)
    lread = leftM.encoder.position()
    rread = rightM.encoder.position()
    prevlError = ticks - lread
    prevrError = ticks - rread
    stime = time.time()
    while True:
        if (time.time() - stime > timeout):
            print("Done")
            break
        lread = leftM.encoder.position()
        rread = rightM.encoder.position()
        lError = ticks - lread
        rError = ticks - rread
        print(lread, rread)
        print(lError, rError)
        print(lStop, rStop)
        if not lStop:
            leftM.move((lError * kP_L + (lError - prevlError) * k_I))
        if not rStop:
            rightM.move(rError * kP_R + (rError - prevrError) * k_I)
        if abs(lError) < 5 and (prevlError-lError == 0):
            print("L\n\n\n")
            lStop = True
            leftM.stop()
        if abs(rError) < 5 and (prevrError-rError == 0):
            print("R\n\n\n")
            rStop = True
            rightM.stop()
        if (lStop==True) and (rStop==True):
            break
        prevlError, prevrError = lError, rError
        time.sleep(0.01)

def turn(ticks):
    kP_L = 40
    kP_R = 40
    k_I = 150
    rStop = False
    lStop = False
    leftEncoder.position(0)
    rightEncoder.position(0)
    lread = leftM.encoder.position()
    rread = rightM.encoder.position()
    prevlError = ticks - lread
    prevrError = ticks - rread
    stime = time.time()
    while True:
        if (time.time() - stime > 0.85):
            print("Done")
            break
        lread = leftM.encoder.position()
        rread = rightM.encoder.position()
        lError = -ticks - lread
        rError = ticks - rread
        print(lread, rread)
        print(lError, rError)
        print(lStop, rStop)
        if not lStop:
            leftM.move((lError * kP_L + (lError - prevlError) * k_I) * 0.8)
        if not rStop:
            rightM.move(rError * kP_R + (rError - prevrError) * k_I)
        if abs(lError) < 5 and (prevlError-lError == 0):
            print("L\n\n\n")
            lStop = True
            leftM.stop()
        if abs(rError) < 5 and (prevrError-rError == 0):
            print("R\n\n\n")
            rStop = True
            rightM.stop()
        if (lStop==True) and (rStop==True):
            break
        prevlError, prevrError = lError, rError
        time.sleep(0.01)

TURN = 1470
HALF = 2670 # 25 cm in 1.5 secs
move(HALF*2, 2.5)
turn(TURN)
move(HALF, 1.5)
turn(-TURN)
move(-HALF*2, 2.5)
turn(TURN)
turn(TURN)
turn(TURN)
turn(TURN)

leftM.stop()
rightM.stop()

