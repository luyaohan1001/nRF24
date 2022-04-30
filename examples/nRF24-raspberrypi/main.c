#include <bcm2835.h>
#include <stdio.h>
#include <stdbool.h>
#include "nRF24.h"
#include "network.h"

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    // bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    nRF24_gpio_initialize();
    // nRF24_print_all_registers();
    // nRF24_tx_self_test();
    ble_struct ble;
    ble_begin(&ble, "nRF24_BLE");
    char buf[4] = {0xC0, 0xC0, 0xCA, 0xFE};

    char buffer[10] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99} ;
    int i = 0;
    // Blink
    while (1)
    {
        
	// printf("hello world\n");
	// read = SPI_READ_MISO();
 	// sprintf(buf, "read: %d\n", read);
	// serial_print(buf);
        if (i > 9) i = 0;
	ble_advertise(&ble, 0xff, (buffer+i), 1);
	// ble_advertise(&ble, 0xff, 0, 0);

        // bcm2835_delay(500);
	++i;

        ble_hopChannel(&ble);
        // bcm2835_delay(500);

        // turn it off

        // wait a bit

    }
    bcm2835_close();
    return 0;
}

