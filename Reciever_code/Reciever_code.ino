#include <VirtualWire.h>
#include <DigiUSB.h>

#define receive_pin  5

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
	int i;
	DigiUSB.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    DigiUSB.print(buf[i]);
	    DigiUSB.print(' ');
	}
	DigiUSB.println();
    }
}
