/*
    Read Rotary Encoder and send MIDI message
*/

void read_Rotary_Encoder(int control_number){
    int encoder_state = digitalRead(first_encoder_out);
    // Check if pulse has occured
    if(encoder_state != prev_encoder_state){
        // Check for direction of the rotation
        if(digitalRead(second_encoder_out) != encoder_state){
            if(intensity_encoder > 0){
                intensity_encoder--;
            }
        } else{
            if(intensity_encoder < 127){
                intensity_encoder++;
            }
        }
    }
    prev_encoder_state = encoder_state;

    if(intensity_encoder != prev_intensity_encoder){
        // Send MIDI message to end-device
        midi_control_change(0, control_number, intensity_encoder);
    }
    prev_intensity_encoder = intensity_encoder;

    delay(2);
    return;
}
