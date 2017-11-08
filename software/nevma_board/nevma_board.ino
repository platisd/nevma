#include <Keyboard.h>
#include <SparkFun_APDS9960.h>

SparkFun_APDS9960 gestureSensor;
const unsigned short GESTURE_INT_PIN = 1;

volatile boolean hasMovement = false;

/**
 * The main business logic. Translates gestures to keyboard events.
 */
void handleGesture() {
  if (gestureSensor.isGestureAvailable()) {
    switch (gestureSensor.readGesture()) {
      case DIR_UP:
        Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case DIR_DOWN:
        Keyboard.press(KEY_LEFT_ARROW);
        break;
      case DIR_LEFT:
        Keyboard.press(KEY_UP_ARROW);
        break;
      case DIR_RIGHT:
        Keyboard.press(KEY_DOWN_ARROW);
        break;
      case DIR_NEAR:
        Keyboard.press(KEY_F5);
        break;
      case DIR_FAR:
        Keyboard.press(KEY_ESC);
        break;
      default:
        break;
    }
    Keyboard.releaseAll();
  }
}

/**
 * Gets called whenever the gesture module signals there are new data to be sent
 */
void transmissionReady() {
  hasMovement = true;
}

void setup() {
  Keyboard.begin();
  attachInterrupt(digitalPinToInterrupt(GESTURE_INT_PIN), transmissionReady, FALLING);
  bool initializationSuccessful = gestureSensor.init() && gestureSensor.enableGestureSensor(true);
  // If ADPS sensor failed to initialize, block and send error messages via Serial
  if (!initializationSuccessful) {
    Serial.begin(9600);
    while(!initializationSuccessful) {
        Serial.println("Error while initializing the gesture sensor");
        delay(10000);
    }
  }
}

void loop() {
  if (hasMovement) {
    handleGesture();
    hasMovement = false;
  }
}
