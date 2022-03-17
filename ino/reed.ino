int reed_iter;
void reed_setup() {
  pinMode(REED_SWITCH_PIN, INPUT);
  reed_iter = 0;
}

bool reed_is_contact_to_magnet(){
  return digitalRead(REED_SWITCH_PIN) == LOW;
}

int reed_iterate_contact_to_magnet(){
  if(digitalRead(REED_SWITCH_PIN) == HIGH) { return 5; }
  reed_iter = (reed_iter+1)%3;
  return reed_iter;
}
