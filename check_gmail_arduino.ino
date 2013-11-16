// led wired + to pin 12, resistor to positive +5v

int outPin = 12; // Output connected to digital pin 12
int mail = LOW; // Is there new mail?
int val; // Value read from the serial port

void setup()
{
 pinMode(outPin, OUTPUT); // sets the digital pin as output
 Serial.begin(9600);
 Serial.flush();
 mail = HIGH; // start off with lights out
}

void loop()
{
 // Read from serial port
 if (Serial.available())
 {
   val = Serial.read();
   Serial.println(val, BYTE);

   if (val == 110) // n = 110 in dec
   {
     mail = HIGH;  // HIGH is off because led is connected to +5v on the other side
   }

   else if (val == 109) //109 = m in dec
   {
     mail = LOW; // LOW is on because led is connected to +5v on the other side
   }
 }

 // Set the status of the output pin
 digitalWrite(outPin, mail);
}
