int reed_switchReed=6;

void reed_setup(int switchReed) {
    reed_switchReed = switchReed;
    pinMode(reed_switchReed, INPUT);
}

void reed_run(){
    if (digitalRead(reed_switchReed)==HIGH){
        Serial.println("Your Door is Closed");
    }
    else {
        Serial.println("Your Door is Open");
    }
}