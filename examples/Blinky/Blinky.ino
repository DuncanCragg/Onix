// --------------------------------------------------------------------

int speed = 333;

static void serial_received(uint8_t ch)
{
  if(ch=='o') speed/=2;
  if(ch=='i') speed*=2;
}

const uint8_t leds_list[LEDS_NUMBER] = LEDS_LIST;

void setup()
{
  for(uint8_t l=0; l< LEDS_NUMBER; l++) pinMode(leds_list[l], OUTPUT);
  Serial.begin(9600);
  onix_serial_cb(serial_received);
  delay(2000);
  Serial.println("Type 'o' or 'i'");
}

void loop()
{
  Serial.print("millis: "); Serial.println(millis());
  for(uint8_t l=0; l< LEDS_NUMBER; l++){ onix_gpio_toggle(leds_list[l]); delay(speed); }
}

// --------------------------------------------------------------------

