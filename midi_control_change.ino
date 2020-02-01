/*
    MIDI-Function to send MIDI-message to the end-device.
    Channel approximately defines the device where the messages are sent from
    Control number is a slot defined for a knob or fader 
    Intensity defines change from knob or fader which is sent to the end-device
*/

void midi_control_change(byte channel, byte control_number, byte intensity){
    Serial.write(B10110000 | (channel & B00001111));
    Serial.write(control_number & B01111111);
    Serial.write(intensity & B01111111);
}
 