#include "bitmaps.h"

const uint8_t BITMAP_PowerSave[8] = { 0x00, 0x26, 0x49, 0x49, 0x49, 0x49, 0x49, 0x32 };

const uint8_t BITMAP_BatteryLevel1[18] = { 0x0, 0x3e, 0x22, 0x63, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x7f };
const uint8_t BITMAP_BatteryLevel2[18] = { 0x0, 0x3e, 0x22, 0x63, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x5d, 0x5d, 0x41, 0x63 };
const uint8_t BITMAP_BatteryLevel3[18] = { 0x0, 0x3e, 0x22, 0x63, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x7f };
const uint8_t BITMAP_BatteryLevel4[18] = { 0x0, 0x3e, 0x22, 0x63, 0x41, 0x41, 0x41, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x7f };
const uint8_t BITMAP_BatteryLevel5[18] = { 0x0, 0x3e, 0x22, 0x63, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x5d, 0x5d, 0x41, 0x7f };
const uint8_t BITMAP_SettingsBatt[72] = {0xE0, 0x10, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x10, 0xE0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x7F, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0x7F};
const uint8_t BITMAP_SettingsBattCharging [] = {
	0x3f, 0x4f, 0x73, 0x7c, 0xfe, 0xfe, 0xde, 0xde, 0xce, 0x56, 0x9a, 0xfc, 0xfe, 0xfe, 0x0e, 0x72, 
	0xbc, 0xcf, 0xf7, 0xfb, 0xfb, 0xfd, 0xfe, 0xff, 0xff, 0xff
};

const uint8_t BITMAP_USB_C[9] = { 0x00, 0x1C, 0x27, 0x44, 0x44, 0x44, 0x44, 0x27, 0x1C };
const uint8_t BITMAP_KeyLock[9] = { 0x00, 0x7C, 0x46, 0x45, 0x45, 0x45, 0x45, 0x46, 0x7C };

const uint8_t BITMAP_F_Key[10] = { 0xFF, 0x81, 0xBD, 0x95, 0x95, 0x95, 0x95, 0x85, 0x81, 0xFF };

const uint8_t BITMAP_VOX[18] = { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x0, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 };

const uint8_t BITMAP_WX[12] = { 0x00, 0x7F, 0x20, 0x18, 0x20, 0x7F, 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 };
const uint8_t BITMAP_TDR[12] = { 0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x7F, 0x20, 0x18, 0x20, 0x7F };
const uint8_t BITMAP_VoicePrompt[9] = { 0x00, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0xFF, 0x18 };

#if defined(ENABLE_FMRADIO)
const uint8_t BITMAP_FM[12] = { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F };
#endif
#if defined(ENABLE_NOAA)
const uint8_t BITMAP_NOAA[12] = { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 };
#endif

const uint8_t BITMAP_Antenna[5] = { 0x03, 0x05, 0x7F, 0x05, 0x03 };
const uint8_t BITMAP_AntennaLevel1[3] = { 0x60, 0x60, 0x00 };
const uint8_t BITMAP_AntennaLevel2[3] = { 0x70, 0x70, 0x00 };
const uint8_t BITMAP_AntennaLevel3[3] = { 0x78, 0x78, 0x00 };
const uint8_t BITMAP_AntennaLevel4[3] = { 0x7C, 0x7C, 0x00 };
const uint8_t BITMAP_AntennaLevel5[3] = { 0x7E, 0x7E, 0x00 };
const uint8_t BITMAP_AntennaLevel6[3] = { 0x7F, 0x7F, 0x00 };

const uint8_t BITMAP_CurrentIndicator[8] = { 0xFF,  0xFF,  0x7E,  0x7E, 0x3C,  0x3C,  0x18,  0x18 };

const uint8_t BITMAP_VFO_Default[8] = { 0x00, 0x7F, 0x7F, 0x3E, 0x3E, 0x1C, 0x1C, 0x08 };
const uint8_t BITMAP_VFO_NotDefault[8] = { 0x00, 0x41, 0x41, 0x22, 0x22, 0x14, 0x14, 0x08 };

const uint8_t BITMAP_TX[16] = { 0x00, 0x01, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x01, 0x00, 0x63, 0x22, 0x14, 0x08, 0x14, 0x22, 0x63 };
const uint8_t BITMAP_RX[16] = { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x19, 0x29, 0x46, 0x00, 0x63, 0x22, 0x14, 0x08, 0x14, 0x22, 0x63 };

const uint8_t BITMAP_M[8] = { 0x00, 0x7F, 0x02, 0x04, 0x18, 0x04, 0x02, 0x7F };
const uint8_t BITMAP_F[8] = { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x01 };

const uint8_t BITMAP_ReverseMode[8] = { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x19, 0x29, 0x46 };

const uint8_t BITMAP_NarrowBand[8] = { 0x00, 0x7F, 0x02, 0x04, 0x08, 0x10, 0x20, 0x7F };

const uint8_t BITMAP_DTMF[24] = {
	0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x01,
	0x01, 0x7F, 0x01, 0x01, 0x00, 0x7F, 0x02, 0x0C,
	0x02, 0x7F, 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,
};

const uint8_t BITMAP_Scramble[18] = {
	0x00, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x3E,
	0x41, 0x41, 0x41, 0x22, 0x00, 0x7F, 0x09, 0x19,
	0x29, 0x46,
};

const uint8_t BITMAP_Add[8] = { 0x00, 0x18, 0x18, 0x7E, 0x7E, 0x7E, 0x18, 0x18 };
const uint8_t BITMAP_Sub[8] = { 0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C };

const uint8_t BITMAP_PowerHigh[8] = { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x7F };
const uint8_t BITMAP_PowerMid[8] = { 0x00, 0x7F, 0x02, 0x04, 0x18, 0x04, 0x02, 0x7F };
const uint8_t BITMAP_PowerLow[8] = { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40 };

const uint8_t BITMAP_AM[12] = { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F };

const uint8_t BITMAP_CT[12] = { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 };
const uint8_t BITMAP_DCS[18] = { 0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x26, 0x49, 0x49, 0x49, 0x32 };

const uint8_t BITMAP_ScanList[6] = { 0x08, 0x1C, 0x3E, 0x3E, 0x1C, 0x08 };
