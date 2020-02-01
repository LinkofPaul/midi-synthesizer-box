// List of buttons and potentiometer

// Switch for toggeling on and off
    const int on_off_switch = 2;

// Potentiometers
    // First
        const int first_pot = A0;
        int prev_status_first_pot = 0;
    // Second
        const int second_pot = A1;
        int prev_status_second_pot = 0;
    // Third
        const int third_pot = A2;
        int prev_status_third_pot = 0;

// Slide Potentiometers
    // First
        const int first_slide_pot = A3;
        int prev_status_first_slide_pot = 0;
    // Second
        const int second_slide_pot = A4;
        int prev_status_second_slide_pot = 0;
    // Third
        const int third_slide_pot = A5;
        int prev_status_third_slide_pot = 0;

// Rotary Encoder
    const int first_encoder_out = 3;
    const int second_encoder_out = 4;
    int prev_encoder_state = 0;
    int intensity_encoder = 64;
    int prev_intensity_encoder = 0;
    
// Buttons
    // Red
        const int red_btn = 5;
        int prev_status_red_btn = 0;
    // Yellow
        const int yellow_btn_led = 6;
        const int yellow_btn = 7;
        int prev_status_yellow_btn = 0;
    // Blue
        const int blue_btn_led = 8;
        const int blue_btn = 9;
        int prev_status_blue_btn = 0;
    // White
        const int white_btn_led = 10;
        const int white_btn = 11;
        int prev_status_white_btn = 0;
    // Green
        const int green_btn_led = 13;
        const int green_btn = 12;
        int prev_status_green_btn = 0;

// Blink LEDs at start-up
void leds_at_start();

void setup() { 
    // PinMode Configuration
    // Switch
    pinMode(on_off_switch, INPUT_PULLUP);
    // Potentiometers
    pinMode(first_pot, INPUT);
    pinMode(second_pot, INPUT);
    pinMode(third_pot, INPUT);
    // Slide Potentiometers
    pinMode(first_slide_pot, INPUT);
    pinMode(second_slide_pot, INPUT);
    pinMode(third_slide_pot, INPUT);
    // Rotary Encoder
    pinMode(first_encoder_out, INPUT);
    pinMode(second_encoder_out, INPUT);
    // Buttons
    pinMode(red_btn, INPUT_PULLUP);
    pinMode(yellow_btn_led, OUTPUT);
    pinMode(yellow_btn, INPUT_PULLUP);
    pinMode(blue_btn_led, OUTPUT);
    pinMode(blue_btn, INPUT_PULLUP);
    pinMode(white_btn_led, OUTPUT);
    pinMode(white_btn, INPUT_PULLUP);
    pinMode(green_btn_led, OUTPUT);
    pinMode(green_btn, INPUT_PULLUP);

    //Blink LEDs
    leds_at_start();

    // Start Serial Communication
    Serial.begin(115200);

    // Reads the initial state of the first encoder output
    prev_encoder_state = digitalRead(first_encoder_out);   
} 
 
void loop() {
    if(!digitalRead(on_off_switch)){
        // Potentiometers
        read_Potentiometer(first_pot, 102, &prev_status_first_pot);
        read_Potentiometer(second_pot, 103, &prev_status_second_pot);
        read_Potentiometer(third_pot, 104, &prev_status_third_pot);
        // Slide Potentiometers
        read_Potentiometer(first_slide_pot, 105, &prev_status_first_slide_pot);
        read_Potentiometer(second_slide_pot, 106, &prev_status_second_slide_pot);
        read_Potentiometer(third_slide_pot, 107, &prev_status_third_slide_pot);
        // Rotary Encoder
        read_Rotary_Encoder(108);
        // Buttons
        read_Button(red_btn, 109, &prev_status_red_btn);
        read_Button(yellow_btn, 110, &prev_status_yellow_btn);
        read_Button(blue_btn, 111, &prev_status_blue_btn);
        read_Button(white_btn, 112, &prev_status_white_btn);
        read_Button(green_btn, 113, &prev_status_green_btn);
    }
}

void leds_at_start(){
    return;
}