#include <Wire.h>
#include <rgb_lcd.h>
#include <TimeLib.h>

//Set up the Grove-LCD RBG Backlight
rgb_lcd lcd;

const int touchpadPin = 2; //Set the Touchpad with the Grove Shield
const int buttonPin = 3; //Set the Button  with the Grove Shield

//Variables for the time
int usec = 0;
int tsec = 0;
int umin = 0;
int tmin = 0;
int uhrs = 0;
int thrs = 0;
 

//Create the setup
void setup() {
  lcd.begin (16,2); //Set LCD with 16 col &2 rows
  lcd.setRGB (255, 255, 255); //Set to white background

  pinMode(touchpadPin, INPUT); //Set touchpad pin as input

  //Welcome message
  lcd.setCursor(4,0);
  lcd.print("Welcome");
  lcd.setCursor(2,1);
  lcd.print("to WellRise!");

  delay(5000); //Display message for 5sec

  //Set 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time:00:00:0");
  lcd.print(usec);
}


void loop() {
  // Read button and touchpad states
  bool boolean_button = (digitalRead(buttonPin) == HIGH);
  bool boolean_touch = (digitalRead(touchpadPin) == HIGH);

  // Only enter the loop if button is not pressed and touch is pressed
  //Unit-secondes
  while (!boolean_button) {
    // Increment usec
      if (boolean_touch) {
        usec++;
        if (usec > 9) {
          usec = 0;
        }
      }
    

    // Format and display the time string
    lcd.setCursor(0, 0);
    lcd.print("Time:00:00:0");
    lcd.print(usec);

    delay(500); // Update every second

    // Check button and touchpad states again
    if (boolean_button = (digitalRead(buttonPin) == HIGH)){
      lcd.setRGB (255, 0, 0); //Red
      delay(500);
    };
    boolean_touch = (digitalRead(touchpadPin) == HIGH);
  }

    boolean_button = false;
    boolean_button = (digitalRead(buttonPin) == HIGH);
    boolean_touch = (digitalRead(touchpadPin) == HIGH);

  //Ten-secondes
  while (!boolean_button){
    // Increment tsec
    if (boolean_touch) {
        tsec++;
        if (tsec > 9) {
          tsec = 0;
        }
    }
    // Format and display the time string
    lcd.setCursor(0, 0);
    lcd.print("Time:00:00:");
    lcd.print(tsec);
    lcd.print(usec);

    delay(500); // Update every second

    // Check button and touchpad states again
    if (boolean_button = (digitalRead(buttonPin) == HIGH)){
      lcd.setRGB (0, 255, 0); //Lime
      delay(500);
    };
    boolean_touch = (digitalRead(touchpadPin) == HIGH); 
  }

    boolean_button = false;
    boolean_button = (digitalRead(buttonPin) == HIGH);
    boolean_touch = (digitalRead(touchpadPin) == HIGH);


  //Unit-minutes
  while (!boolean_button){
    // Increment tsec
    if (boolean_touch) {
        umin++;
        if (umin > 9) {
          umin = 0;
        }
    }
    // Format and display the time string
    lcd.setCursor(0, 0);
    lcd.print("Time:00:0");
    lcd.print(umin);
    lcd.print(":");
    lcd.print(tsec);
    lcd.print(usec);

    delay(500); // Update every second

    // Check button and touchpad states again
    if (boolean_button = (digitalRead(buttonPin) == HIGH)){
      lcd.setRGB (0, 0, 255); //Blue
      delay(500);
    };
    boolean_touch = (digitalRead(touchpadPin) == HIGH); 
  }

    boolean_button = false;
    boolean_button = (digitalRead(buttonPin) == HIGH);
    boolean_touch = (digitalRead(touchpadPin) == HIGH);

  //Ten-minutes
  while (!boolean_button){
      // Increment tsec
      if (boolean_touch) {
          tmin++;
          if (tmin > 9) {
            tmin = 0;
          }
      }
      // Format and display the time string
      lcd.setCursor(0, 0);
      lcd.print("Time:00:");
      lcd.print(tmin);
      lcd.print(umin);
      lcd.print(":");
      lcd.print(tsec);
      lcd.print(usec);

      delay(500); // Update every second

      // Check button and touchpad states again
      if (boolean_button = (digitalRead(buttonPin) == HIGH)){
        lcd.setRGB (255, 165, 0); // Orange
        delay(500);
      };
      boolean_touch = (digitalRead(touchpadPin) == HIGH); 
    }

    boolean_button = false;
    boolean_button = (digitalRead(buttonPin) == HIGH);
    boolean_touch = (digitalRead(touchpadPin) == HIGH);

  //Unit-hours
  while (!boolean_button){
      // Increment tsec
      if (boolean_touch) {
          uhrs++;
          if (uhrs > 9) {
            uhrs = 0;
          }
      }
      // Format and display the time string
      lcd.setCursor(0, 0);
      lcd.print("Time:0");
      lcd.print(uhrs);
      lcd.print(":");
      lcd.print(tmin);
      lcd.print(umin);
      lcd.print(":");
      lcd.print(tsec);
      lcd.print(usec);

      delay(500); // Update every second

      // Check button and touchpad states again
      if (boolean_button = (digitalRead(buttonPin) == HIGH)){
        lcd.setRGB (0, 128, 0); //Green
        delay(500);
      };
      boolean_touch = (digitalRead(touchpadPin) == HIGH); 
    }

        boolean_button = false;
    boolean_button = (digitalRead(buttonPin) == HIGH);
    boolean_touch = (digitalRead(touchpadPin) == HIGH);

  //Ten-hours
  while (!boolean_button){
      // Increment tsec
      if (boolean_touch) {
          thrs++;
          if (thrs > 9) {
            thrs = 0;
          }
      }
      // Format and display the time string
      lcd.setCursor(0, 0);
      lcd.print("Time:");
      lcd.print(thrs);
      lcd.print(uhrs);
      lcd.print(":");
      lcd.print(tmin);
      lcd.print(umin);
      lcd.print(":");
      lcd.print(tsec);
      lcd.print(usec);

      delay(500); // Update every second

      // Check button and touchpad states again
      if (boolean_button = (digitalRead(buttonPin) == HIGH)){
        lcd.setRGB (255, 0, 255); //Fuchsia
        delay(500);
      };
      boolean_touch = (digitalRead(touchpadPin) == HIGH); 
    }

}
