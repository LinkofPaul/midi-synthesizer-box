/*
    Read Button and send MIDI message
*/

void read_Button(int btn_pin, int control_number, int *prev_status){
    int status_btn = 0;
    if(digitalRead(btn_pin)){
        status_btn = 0;
    }else{
        status_btn = 127;
    }

    if(status_btn != *prev_status){
        // Send MIDI message to end-device
        midi_control_change(0, control_number, status_btn);
        *prev_status = status_btn;
    }

    delay(2);
    return;
}