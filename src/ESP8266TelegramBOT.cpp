
/*
Copyright (c) 2015 Giancarlo Bacchio. All right reserved.

TelegramBot - Library to create your own Telegram Bot using
ESP8266 on Arduino IDE.
Ref. Library at https:github/esp8266/Arduino

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#include "ESP8266TelegramBOT.h"

ESP8266TelegramBOT::ESP8266TelegramBOT(String token) :TelegramBotCore(token) {
}

String ESP8266TelegramBOT::sendGetToTelegram(String command) {
	String mess="";
	long now;
	bool avail;
	// Connect with api.telegram.org
	if (client.connect(HOST, SSL_PORT)) {
		// Serial.println(".... connected to server");
		String a="";
		char c;
		int ch_count=0;
		client.println("GET /"+command);
		now=millis();
		avail=false;
		while (millis()-now<1500) {
			while (client.available()) {
				char c = client.read();
				//Serial.write(c);
				if (ch_count < maxMessageLength)  {
					mess=mess+c;
					ch_count++;
				}
				avail=true;
			}
			if (avail) {
				// Serial.println();
				// Serial.println(mess);
				// Serial.println();
				break;
			}
		}
	}
	return mess;
}
