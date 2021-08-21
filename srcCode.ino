/*
 * The following code is written in accordance to IR Proximity Sensor.
 * Under the circumstance some other sensor is in use, make necessary changes.
 */

const int ProxSensor = A1;      //Proximity Sensor pin
int inputVal = 0, n;

void setup() 
{                
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:  
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
/*
 * Series of Actions:
 * 1. Detect Proximity
 * 2. count the number of seconds in use
 * 3. Average human time of loo is 21s, thus if time > 15s 
 * 4. Wait until person finishes use
 * 5. Execute a serice of flushing actions
 * 6. Pull the flush to empty tank
 * 7. Wait for the tank to refill
 * 8. check if pan is clean
 * 9. Continue sequence until pan clean
 */
  
  while((inputVal = analogRead(ProxSensor)) < 800)      //Loop 
  {
    delay(1000);
    n++;
    Serial.print("< 800:");
    Serial.println(inputVal); 
  }

  if(n > 15)
  {
    while((inputVal = analogRead(ProxSensor)) > 800)
    {
      digitalWrite(13, HIGH);
      delay(10000);
      digitalWrite(13, LOW);
      delay(30000);
      Serial.print("> 800:");
      Serial.println(inputVal); 
    }
  }

Serial.println(inputVal); 
}
