/*******************************************************
 * SANTRONIX <info@santronix.in>
 * 
 * This file is part of SANTRONIX Particle Photon IoT Tutorials.
 * 
 * SANTRONIX Particle Photon Tutorials Project can not be copied and/or distributed without the express
 * permission of SANTRONIX
 *******************************************************/
 
Servo servo;
int counter = 0;
bool schedule = false;

void setup() {
    Serial.begin(9600);
    servo.attach(D0);
    Particle.function("switch", switchToggle);
}

void loop() {
    if(schedule){
        delay(1000);
        counter++;
        if(counter == 10){
            servo.write(0);
            counter = 0;
            schedule = false;
        }
    }
}

int switchToggle(String command){
    if(command == "on"){
        servo.write(170);
    }
    else if(command == "off"){
        servo.write(0);
    }
    else if(command == "schedule"){
        schedule = true;
        servo.write(170);
    }
}
