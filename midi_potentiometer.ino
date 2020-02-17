/*
    Read Potentiometer and send MIDI message
*/

void read_Slide_Potentiometer(int pot_pin, int control_number, int *prev_intensity){
    int val_pot = analogRead(pot_pin);
    // Transform voltage number into number between 0 and 127
    int intensity_pot = 127.0 * val_pot / 1023;   
    int intensity_diff = intensity_pot - *prev_intensity;
    
    if(abs(intensity_diff) > 1){
        // Send MIDI message to end-device
        midi_control_change(0, control_number, intensity_pot);
    }
    *prev_intensity = intensity_pot;
    
    delay(2);
    return;
}

void read_Potentiometer(int pot_pin, int control_number, int *prev_intensity){
    int val_pot = analogRead(pot_pin);
    // Transform voltage number into number between 0 and 127
    int intensity_pot = 127 - (127.0 * val_pot / 1023);
    int intensity_diff = intensity_pot - *prev_intensity;
    
    if(abs(intensity_diff) > 1){
        // Send MIDI message to end-device
        midi_control_change(0, control_number, intensity_pot);
    }
    *prev_intensity = intensity_pot;
    
    delay(2);
    return;
}
