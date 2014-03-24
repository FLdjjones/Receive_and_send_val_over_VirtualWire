#include <VirtualWire.h>
#include <DigiUSB.h>


void setup()
{
   vw_set_rx_pin(5);
   vw_setup(2000);
   vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	
	for (int i = 0; i < buflen; i++)
	{
	    DigiUSB.println(buf[i]);
	}
        DigiUSB.delay(500);
    }
}
