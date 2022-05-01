# Nordic nRF24L01+ C Library.
```
.
├── examples
│   └── nRF24-raspberrypi
│       ├── list.txt
│       ├── main
│       ├── main.c
│       ├── main.o
│       ├── Makefile
│       ├── network.o
│       └── nRF24.o
├── network.c
├── network.h
├── nRF24
├── nRF24.c
├── nRF24.h
└── README.md
```

| File         |      Description
------------------------------------------------------------------------------------------------------------------------------------------------
| nRF24.c      |      Abstraction for data link layer. Contains implementation source for GPIO initialization / SPI / nRF24 register Operations.
| nRF24.h      |      nRF24.h Header files including nRF24L01+ macros.
| network.c    |      Abstraction for network layer. Contains implementation source for sending 32-byte packet similiar to BLE advertisement nodes.
| network.h    |      network.h Header file.

