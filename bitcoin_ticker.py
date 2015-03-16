import requests
import serial
import time

s = serial.Serial('/dev/ttyACM0', baudrate=9600)
time.sleep(2)

if s.isOpen():
  while (True):
    r = requests.get('https://api.bitcoinaverage.com/ticker/USD')
    r = r.json()
    price = r['last']
    print price
    s.write(str(price))
    s.write('\n')

    time.sleep(25)
