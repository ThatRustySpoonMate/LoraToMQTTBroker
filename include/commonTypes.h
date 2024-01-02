#pragma once

#include "Arduino.h"

#pragma pack(1)
//above line tells compiler not to pad structs
typedef union {
    float    data_fp [2];
    uint8_t  data_u8 [8];
    int8_t   data_s8 [8];
    uint16_t data_u16[4];
    int16_t  data_s16[4];
    uint32_t data_u32[2];
    int32_t  data_s32[2];
    uint64_t data_u64;
    int64_t  data_s64;
    double	 data_dbl;
} PayloadType;

typedef struct {
    PayloadType data;
    uint32_t timestamp;
    char MQTT_Topic[64];
} LORAMsgType;