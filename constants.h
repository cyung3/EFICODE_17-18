#ifndef constants_h
#define constants_h

#include "Arduino.h"
#include "SdFat.h"

//Sensor Pin Definitions
#define ECT_PIN A21
#define SENSOR_PIN A0
#define IAP_PIN A22
const int MAP_PIN = 34; 
const int TPS_PIN = 33; 
const int FPS_PIN = 38; 
const int IAT_PIN = 39; 
const int IVO_PIN = 20;
const int IVC_PIN = 21; //Pin 22 has the same behavior
const int MAP_IVO_PIN = 23;
const int INJ_PIN = 0;
const int LED_PIN = 11;

// 16 KiB buffer.
const size_t BUF_DIM = 16384;

// Sampling rate
const uint32_t sampleIntervalMicros = 100;
// 40 us interval = 25 kHz


// Use total of four buffers.
const uint8_t BUFFER_BLOCK_COUNT = 4;

// Number of data points per record
const uint8_t ADC_DIM = 7;

// Format for one data record
struct data_t {
  bool newcycle = false;
  uint32_t time;
  uint32_t adc[ADC_DIM];
};
// Warning! The Teensy allocates memory in chunks of 4 bytes!
// sizeof(data_t) will always be a multiple of 4. For example, the following
// data record will have a size of 12 bytes, not 9:
// struct data_t {
//   uint32_t time; // 4 bytes
//   uint8_t  adc[5]; // 5 bytes
// }


// Number of data records in a block.
const uint16_t DATA_DIM = (BUF_DIM - 4)/sizeof(data_t);

//Compute fill so block size is BUF_DIM bytes.  FILL_DIM may be zero.
const uint16_t FILL_DIM = BUF_DIM - 4 - DATA_DIM*sizeof(data_t);

// Format for one block of data
struct block_t {
  uint16_t count;
  uint16_t overrun;
  data_t data[DATA_DIM];
  uint8_t fill[FILL_DIM];
};

// Intialize all buffers


// Initialize full queue
const uint8_t QUEUE_DIM = BUFFER_BLOCK_COUNT + 1;

// Index of last queue location.
const uint8_t QUEUE_LAST = QUEUE_DIM - 1;

//Dummy function for interrupts to attach to upon initialization
void dummy();

#endif
