/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include <string.h>
#include "driver/st7565.h"
#include "external/printf/printf.h"
#include "font.h"
#include "ui/helper.h"
#include "ui/inputbox.h"

#ifndef ARRAY_SIZE
	#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#endif

void UI_GenerateChannelString(char *pString, uint8_t Channel)
{
	uint8_t i;

	if (gInputBoxIndex == 0) {
		sprintf(pString, "CH-%02d", Channel + 1);
		return;
	}

	pString[0] = 'C';
	pString[1] = 'H';
	pString[2] = '-';

	for (i = 0; i < 2; i++) {
		if (gInputBox[i] == 10) {
			pString[i + 3] = '-';
		} else {
			pString[i + 3] = gInputBox[i] + '0';
		}
	}

}

void UI_GenerateChannelStringEx(char *pString, bool bShowPrefix, uint8_t ChannelNumber)
{
	if (gInputBoxIndex) {
		uint8_t i;

		for (i = 0; i < 3; i++) {
			if (gInputBox[i] == 10) {
				pString[i] = '-';
			} else {
				pString[i] = gInputBox[i] + '0';
			}
		}
		return;
	}

	if (bShowPrefix) {
		sprintf(pString, "CH-%03d", ChannelNumber + 1);
	} else {
		if (ChannelNumber == 0xFF) {
			strcpy(pString, "NULL");
		} else {
			sprintf(pString, "%03d", ChannelNumber + 1);
		}
	}
}

void UI_PrintString(const char *pString, uint8_t Start, uint8_t End, uint8_t Line, uint8_t Width, bool bCentered)
{
	uint32_t i, Length;

	Length = strlen(pString);
	if (bCentered) {
		Start += (((End - Start) - (Length * Width)) + 1) / 2;
	}
	for (i = 0; i < Length; i++) {
		if (pString[i] >= ' ' && pString[i] < 0x7F) {
			uint8_t Index = pString[i] - ' ';
			memcpy(gFrameBuffer[Line + 0] + (i * Width) + Start, &gFontBig[Index][0], 8);
		}
	}
}

void UI_PrintStringSmall(const char *pString, uint8_t Start, uint8_t End, uint8_t Line)
{
	const size_t Length = strlen(pString);
	size_t       i;

	if (End > Start)
		Start += (((End - Start) - (Length * 8)) + 1) / 2;

	const unsigned int char_width   = ARRAY_SIZE(gFontSmall[0]);
	const unsigned int char_spacing = char_width + 0;
	uint8_t            *pFb         = gFrameBuffer[Line] + Start;
	for (i = 0; i < Length; i++)
	{
		if (pString[i] >= 32)
		{
			const unsigned int Index = (unsigned int)pString[i] - 32;
			if (Index < ARRAY_SIZE(gFontSmall))
				memmove(pFb + (i * char_spacing), &gFontSmall[Index], char_width);
		}
	}
}

void UI_DisplayFrequency(const char *pDigits, uint8_t X, uint8_t Y,
                         bool bDisplayLeadingZero, bool bFlag) {
  char String[8];
  char baseDigit = '0';
  uint8_t d;
  sprintf(String, "---.---");
  for (int i = 0; i < 3; i++) {
    d = pDigits[i];
    if (d < 10) {
      String[i] = d + baseDigit;
    }
  }
  for (int i = 0; i < 3; i++) {
    d = pDigits[i + 3];
    if (d < 10) {
      String[i + 4] = d + baseDigit;
    }
  }
  UI_PrintString(String, 8, 127, Y, 8, 1);
}

void UI_DisplaySmallDigits(uint8_t Size, const char *pString, uint8_t X, uint8_t Y)
{
	uint8_t i;

	for (i = 0; i < Size; i++) {
		memcpy(gFrameBuffer[Y] + (i * 7) + X, gFontSmallDigits[(uint8_t)pString[i]], 7);
	}
}

