

// set all moisture sensors PIN ID

int moisture2 = 36;
int moisture1 = 39;

//int moisture3 = A2;
//int moisture4 = A3;

// declare moisture values
int moisture1_value = 0;
int moisture2_value = 0;
//int moisture3_value = 0;
//int moisture4_value = 0;

// set water relays
int relay1 = 17;
int relay2 = 5;
//int relay3 = 9;
//int relay4 = 10;

// set water pump
int pump = 16;

//pump state    1:open   0:close
int pump_state_flag = 1;

//relay1 state    1:open   0:close
int relay1_state_flag = 0;

//relay2 state   1:open   0:close
int relay2_state_flag = 0;

//relay3 state  1:open   0:close
//int relay3_state_flag = 0;

//relay4 state   1:open   0:close
//int relay4_state_flag = 0;

static unsigned long currentMillis_send = 0;
static unsigned long  Lasttime_send = 0;

void setup()
{
  
  Serial.begin(9600);
  // declare capacitive moisture sensors as input pins.
  pinMode(moisture1, INPUT);
  pinMode(moisture2, INPUT);
  //pinMode(moisture3,INPUT);
  //pinMode(moisture4,INPUT);
  
  // declare relay as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  //pinMode(relay3, OUTPUT);
  //pinMode(relay4, OUTPUT);
  
  // declare pump as output
  pinMode(pump, OUTPUT);
  
}
  void loop()
{
  // read the value from the moisture sensors:
  read_value();
  water_flower();
  Serial.println(moisture1_value);
  Serial.println(moisture2_value);
  
  delay(500);
  
}

//Set moisture value
void read_value()
{
  float value1 = analogRead(36);
  moisture1_value = (value1 * 120) / 1023; delay(20);
  float value2 = analogRead(39);
  moisture2_value = (value2 * 120) / 1023; delay(20);
  //float value3 = analogRead(A2);
  //moisture3_value = (value3 * 120) / 1023; delay(20);
  //float value4 = analogRead(A3);
  //moisture4_value = (value4 * 120) / 1023; delay(20);
}

void water_flower()
{
  if (moisture1_value > 280) // Treshold Hoger is droger lager is natter. (210 glas water <-> 400 luchtdroog)
  {
    digitalWrite(relay1, LOW);
    relay1_state_flag = 0;
    delay(50);
    if (pump_state_flag == 1)
    {
      digitalWrite(pump, LOW);
      pump_state_flag = 0;
      delay(50);
    }
  }
  else if (moisture1_value < 310) // Treshold Hoger is droger lager is natter. (210 glas water <-> 400 luchtdroog)
  {
    digitalWrite(relay1, HIGH);
    relay1_state_flag = 1;
    delay(50);
    if ((relay1_state_flag == 1) && (relay2_state_flag == 1)) // && (relay3_state_flag == 1) && (relay4_state_flag == 0))
    {
      digitalWrite(pump, HIGH);
      pump_state_flag = 1;
      delay(50);
    }
  }

  if (moisture2_value > 280)
  {
    digitalWrite(relay2, LOW);
    relay2_state_flag = 0;
    delay(50);
    if (pump_state_flag == 1)
    {
      digitalWrite(pump, LOW);
      pump_state_flag = 0;
      delay(50);
    }
  }
  
  else if (moisture2_value < 310)
  {
    digitalWrite(relay2, HIGH);
    relay2_state_flag = 1;
    delay(50);
    if ((relay1_state_flag == 1) && (relay2_state_flag == 1))// && (relay3_state_flag == 1) && (relay4_state_flag == 0))
    {
      digitalWrite(pump, HIGH);
      pump_state_flag = 1;
      delay(50);
    }
  }
/*
  if (moisture3_value < 30)
  {
    digitalWrite(relay3, HIGH);
    relay3_state_flag = 1;
    delay(50);
    if (pump_state_flag == 0)
    {
      digitalWrite(pump, HIGH);
      pump_state_flag = 1;
      delay(50);
    }
  }
  else if (moisture3_value > 55)
  {
    digitalWrite(relay3, LOW);
    relay3_state_flag = 0;
    delay(50);
    if ((relay1_state_flag == 0) && (relay2_state_flag == 0) && (relay3_state_flag == 0) && (relay4_state_flag == 0))
    {
      digitalWrite(pump, LOW);
      pump_state_flag = 0;
      delay(50);
    }
  }

  if (moisture4_value < 30)
  {
    digitalWrite(relay4, HIGH);
    relay4_state_flag = 1;
    delay(50);
    if (pump_state_flag == 0)
    {
      digitalWrite(pump, HIGH);
      pump_state_flag = 1;
      delay(50);
    }
  }
  else if (moisture4_value > 55)
  {
    digitalWrite(relay4, LOW);
    relay4_state_flag = 0;
    delay(50);
    if ((relay1_state_flag == 0) && (relay2_state_flag == 0) && (relay3_state_flag == 0) && (relay4_state_flag == 0))
    {
      digitalWrite(pump, LOW);
      pump_state_flag = 0;
      delay(50);
      */
}

  
