# Arduino-Uno---Smart-blind-stick
code for Arduino Uno to make a smart blind stick Using Arduino Uno and the ultrasonic sensor with buzzer and vibration motor
// How it works

1. The Setup Phase (Initialization)
When you power on the Arduino, it runs the setup() block exactly once.

It tells the Arduino which pins are sending signals out (OUTPUT) and which are listening for signals coming in (INPUT).

The Trig pin, Buzzer, and Vibration Motor are set as OUTPUT because the Arduino sends commands to them.

The Echo pin is set as INPUT because the Arduino receives data from it.

2. Sending the "Ping" (The Trigger)
Once the setup is done, the Arduino enters the loop() block, which repeats endlessly.

The Arduino sends a tiny, 10-microsecond electrical pulse to the Trig pin (digitalWrite(trigPin, HIGH)).

This tells the ultrasonic sensor to blast out a short burst of high-frequency sound waves (ultrasound) into the air. These waves are too high-pitched for humans to hear.

3. Listening for the Echo
After sending the sound wave, the system waits for it to bounce off an object and return.

The sensor's receiver catches the bouncing sound wave.

The Arduino uses the pulseIn(echoPin, HIGH) command. This function acts like a stopwatch; it measures the exact time (in microseconds) it took for the sound wave to leave the sensor, hit an object, and bounce back to the receiver. This time is stored in the duration variable.

4. Calculating the Distance
The Arduino now knows how long the sound was traveling, but it needs to convert time into distance. It uses this formula:
distance = duration * 0.034 / 2;

Why 0.034? Sound travels through the air at roughly 340 meters per second, which equals 0.034 centimeters per microsecond. Multiplying the duration by this speed gives the total distance the sound traveled.

Why divide by 2? The sound wave had to travel to the object and then bounce back. We only want the distance to the object, so we cut the total distance in half.

5. The Alert Logic (Making Decisions)
Now that the Arduino has a precise distance measurement in centimeters, it checks the rules you programmed:

The 50cm Check (Early Warning): It asks, "Is the distance 50 cm or less?" If yes, it sends power to the Buzzer (digitalWrite(buzzerPin, HIGH)). If no, it turns the Buzzer off.

The 20cm Check (Urgent Warning): It asks, "Is the distance 20 cm or less?" If yes, it also sends power to the Vibration Motor (digitalWrite(motorPin, HIGH)). If no, it turns the motor off.

6. Reset and Repeat
Finally, the system pauses for a tiny fraction of a second (delay(50)) to stabilize and prevent the sensor signals from overlapping, and then the entire loop starts over again, constantly scanning the environment.

Below is an interactive simulation of this logic. You can drag the obstacle to see how your Arduino processes the distance and triggers the different alerts.
