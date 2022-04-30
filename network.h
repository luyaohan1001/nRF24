/**
  ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ********
  * @file      :     network.h
  * @author    :     Luyao Han
  * @email     :     luyaohan1001@gmail.com
  * @brief     :     Network layer (OSI) header for Nordic nRF24L01+ 2.4GHz wireless module.
  * @date      :     04-30-2022
  * Copyright (C) 2022-2122 Luyao Han. The following code may be shared or modified for personal use / non-commercial use only.
  ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ******** ********  */

/* Macro to prevent recursive inclusion ----------------------------------------------------------------------------------------*/
#ifndef __NETWORK_H
#define __NETWORK_H

#define BCM2835

/* Includes --------------------------------------------------------------------------------------------------------------------*/
#if defined STM32F4xx
#include "stm32f4xx_hal.h"
#elif defined BCM2835
#include "bcm2835.h"
#endif 

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* Struct Definitions -----------------------------------------------------------------------------------------------------------*/
/* Packet Width = 32 bytes */
/*
typedef struct nRF24_packet
{
  uint8_t preamble;
  uint8_t address[2];
} nRF24_packet_t;
*/


/* Function Prototypes -------------------------------------------------------------------------------------------------------*/

// advertisement PDU
__attribute__((packed)) struct btle_adv_pdu {

	// packet header
	uint8_t pdu_type; // PDU (Protocal Data Unit) type
	uint8_t payload_size;  // payload size 负载大小，包括6字节的mac

	// MAC address
	uint8_t mac[6];

	// payload (including 3 bytes for CRC)
	uint8_t payload[24];
};

typedef struct btle_adv_pdu btle_adv_pdu;

// payload chunk in advertisement PDU payload
__attribute__((packed)) struct btle_pdu_chunk {
	uint8_t size;
	uint8_t type;
	uint8_t data[];
};

typedef struct
{
	struct btle_adv_pdu buffer;
	char *name;
	uint8_t current;   // current channel index
}ble_struct;



// Initialize nRF24 as ble node
void ble_begin( ble_struct *ble,char* _name ) ;

// advertisement
int ble_advertise( ble_struct *ble,uint8_t data_type, void* buf, uint8_t buflen ) ;

// bluetooth frequency hopping.
void ble_hopChannel(ble_struct *ble);

int ble_addChunk(ble_struct *ble,uint8_t chunk_type, uint8_t buflen, const void* buf);

void ble_preparePacket(ble_struct *ble);

void ble_transmitPacket(ble_struct *ble);

// change buffer contents to "wire bit order"
void ble_swapbuf( ble_struct *ble,uint8_t len );

// see BT Core Spec 4.0, Section 6.B.3.2
void ble_whiten( ble_struct *ble,uint8_t len );
void ble_crc( ble_struct *ble,uint8_t len, uint8_t* dst );






#endif /* __NETWORK_H */


