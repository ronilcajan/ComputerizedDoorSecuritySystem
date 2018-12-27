<h1>Computerized Door Security System</h1>
    
    PINcode based door lock system using GizDuino Microcontrollers.

<h3>Materials</h3>

    • Microcontroller(GizDuino Atmega164P/324P/644P)                  
    • 16x2 LCD
    • 4x4 Keypad
    • 9g Servo motor
    • Buzzer
    • 220 Ohm Resistor
    • 10k Potentiometer
    • Breadboard
    • Connecting wires(jumper wires)
    • Glue Gun
    • Stick Glue
    • Cutter
    • 1 Empty Box 
    • 1/4 Illustration Board
    • Laptop/Computer
    • Arduino IDE Software
    • Fritzing Software
    
<h3>Algorith</h3>

First, secure all the components needed for this set-up. First,will then connect the 4x4 Keypad to the microcontroller.

    • Connect the pin 1 from the keypad to digital pin 9 of GizDuino.
    • Pin 2 from the keypad to digital pin 8 of GizDuino.
    • Pin 3 from the keypad to digital pin 7 of GizDuino.
    • Pin 4 from the keypad to digital pin 6 of GizDuino.
    • Pin 5 from the keypad to digital pin 5 of GizDuino.
    • Pin 6 from the keypad to digital pin 4 of GizDuino.
    • Pin 7 from the keypad to digital pin 3 of GizDuino.
    • Pin 8 from the keypad to digtal pin 2 of GizDuino.
    
After finishing the keypad connections, we will then proceed to the LCD connection:

    • Connect the Pin 1 from the LCD to the GND of GizDuino.
    • Pin 2 from the LCD to the 5V of GizDuino.
    • Pin 3 from the LCD to the pin 2(OUTPUT) of potentiometer.
    • Pin 4 from the LCD to the analog pin A0 of GizDuino.
    • Pin 5 from the LCD to the GND  of GizDuino.
    • Pin 6 from the LCD to the analog pin A1 of Gizduino.
    
Leave untouch the Pin 7,8,9,10 from the LCD and proceed to Pin 11.

    • Connect pin 11 from the LCD to the analog pin A2 of GizDuino.
    • Pin 12 from the LCD to the analog pin A3 of Gizduino.
    • Pin 13 from the LCD to the analog pin A4 of Gizduino.
    • Pin 14 from the LCD to the analog pin A5 of Gizduino.
    • Connect Pin 15 from the LCD to the 220 ohms Resistor and the other pin of the resistor will be connected to the 5V of         GizDuino(its better if you tap it to the pin 2 of the LCD or use breadboard).
    • Pin 16 of the LCD to the GND of Gizduino.
    
After the LCD connection is done.We will then connect the Potentiometer,Buzzer and Servo motor respectively.

    • Connect Pin 1(GROUND) from the Potentiometer to the GND of Gizduino(use breadboard).
    • Pin 2(OUTPUT) from the Potentiometer is already connected(Review Pin 3 from the LCD)
    • Pin 3(Vref) from the Potentiometer to the 5V of GizDuino. (use breadboard).
    • Connect ground pin from the Buzzer to the GND of Gizduino.(use breadboard).
    • Second pin from the Buzzer to the pin 11 of Gizduino.
    • Connect brown wire(GROUND) from the Servo to the GND of Gizduino(use breadboard).
    • Red wire(POWER) from the Servo to the 5V of GizDuino.(use breadboard).
    • Orange wire(SIGNAL) from the Servo to the pin 10 of GizDuino.
    
Secure all the connection is correct and check also if its tight enough to prevent loss connection.Then, open your Arduino IDE Software, connect the USB cable from your computer/laptop to your Gizduino and then,write the needed code. After that, compile the code and if there is no error, upload it(make sure you connect your GizDuino to a specific board and check serial port from the Arduino IDE Software to prevent error). Test your project. If its working and there is no error, your project is almost done and you only need to build a prototype for this project.
After making the prototype, used 9V/12V battery and connect it to the power port of GizDuino.

