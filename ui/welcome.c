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
#include "driver/eeprom.h"
#include "driver/st7565.h"
#include "external/printf/printf.h"
#include "helper/battery.h"
#include "settings.h"
#include "ui/helper.h"
#include "ui/welcome.h"
#include "version.h"
#include "driver/system.h"
#include "audio.h"

void UI_DisplayWelcome(void)
{
	char WelcomeString0[16];
	char WelcomeString1[16];

	memset(gStatusLine, 0, sizeof(gStatusLine));
	memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
	UI_SelfTest();
	ST7565_FillScreen(0x00);

	if (gEeprom.POWER_ON_DISPLAY_MODE == POWER_ON_DISPLAY_MODE_FULL_SCREEN) {
		ST7565_FillScreen(0xFF);
	} else {
		memset(WelcomeString0, 0, sizeof(WelcomeString0));
		memset(WelcomeString1, 0, sizeof(WelcomeString1));
		if (gEeprom.POWER_ON_DISPLAY_MODE == POWER_ON_DISPLAY_MODE_VOLTAGE) {
			sprintf(WelcomeString0, "VOLTAGE");
			sprintf(WelcomeString1, "%d.%02dV", gBatteryVoltageAverage / 100, gBatteryVoltageAverage % 100);
		} else {
			EEPROM_ReadBuffer(0x0EB0, WelcomeString0, 16);
			EEPROM_ReadBuffer(0x0EC0, WelcomeString1, 16);
		}
		UI_PrintString(WelcomeString0, 0, 127, 1, 10, true);
		UI_PrintString(WelcomeString1, 0, 127, 3, 10, true);
		UI_PrintString(Version, 0, 127, 5, 10, true);
		ST7565_BlitStatusLine();
		ST7565_BlitFullScreen();
	}
}

void UI_SelfTest(void)
{
	UI_PrintString("SELF TEST", 0, 127, 0, 10, true);
	ST7565_BlitFullScreen();
	SYSTEM_DelayMs(500);
	UI_PrintString("BATTERY [OK]", 0, 127, 1, 10, true);
	ST7565_BlitFullScreen();
	SYSTEM_DelayMs(100);
	UI_PrintString("DISPLAY [OK]", 0, 127, 2, 10, true);
	ST7565_BlitFullScreen();
	SYSTEM_DelayMs(100);
	AUDIO_PlayFreq(1000,50);
	SYSTEM_DelayMs(50);
	AUDIO_PlayFreq(1000,50);
	UI_PrintString("AUDIO [OK]", 0, 127, 3, 10, true);
	ST7565_BlitFullScreen();
	SYSTEM_DelayMs(50);
}

