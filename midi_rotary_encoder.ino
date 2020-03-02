/*
    Read Rotary Encoder and send MIDI message
*/

void read_Rotary_Encoder(int control_number){
  encoder.tick();
  long newPosition = encoder.getPosition();
  if(oldPosition < newPosition){
    if(intensity_encoder > 0){
      intensity_encoder--;
      // Send MIDI message to end-device
      midi_control_change(0, control_number, intensity_encoder);
    }
    oldPosition = newPosition;
  } else if(oldPosition > newPosition){
    if(intensity_encoder < 127){
      intensity_encoder++;
      // Send MIDI message to end-device
      midi_control_change(0, control_number, intensity_encoder);
    }
    oldPosition = newPosition;
  }
  delay(2);
  return;
}
