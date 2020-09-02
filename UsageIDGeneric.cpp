#include <windows.h>
#include <setupapi.h>
#include <Hidclass.h>
#include <Sensors.h>
#include <sensorsapi.h>
#include <SensorsDef.h>
#include <iostream>
#include <stdio.h> 
#include <combaseapi.h>
#include <Devpkey.h>
#include <hidsdi.h>
#include <Devguid.h>
#include <vector>
#include <exception>
#include "UsageIDGeneric.h"






std::string UsageIDG_CONVERT(int UsageID) { // generic destop page converter - more can be added if asked - also yes this could have been a switch case statment with a function to control the ranges (but I realized the reason to make it more efficent in that sense would matter little)

	std::string resultsID;

	if (UsageID == 0) {

		resultsID = "Undefined";

	}


	else if (UsageID == 1) {

		resultsID = "Pointer";

	}

	else if (UsageID == 2) {

		resultsID = "Mouse";

	}

	else if (UsageID == 3) {

		resultsID = "Reserved";

	}

	else if (UsageID == 4) {

		resultsID = "Joystick";

	}

	else if (UsageID == 5) {

		resultsID = "Gamepad";

	}

	else if (UsageID == 6) {

		resultsID = "Keyboard";

	}

	else if (UsageID == 7) {

		resultsID = "Keypad";

	}

	else if (UsageID == 8) {

		resultsID = "Multi-axis Controller";

	}

	else if (UsageID == 9) {

		resultsID = "Tablet PC System Controls";

	}

	else if (UsageID == 10) {

		resultsID = "Water Cooling Device";

	}

	else if (UsageID == 11) {

		resultsID = "Computer Chassis Device";

	}

	else if (UsageID == 12) {

		resultsID = "Wireless Radio Controls";

	}

	else if (UsageID == 13) {

		resultsID = "Portable Device Control";

	}

	else if (UsageID == 14) {

		resultsID = "System Multi-Axis Controller";

	}

	else if (UsageID == 15) {

		resultsID = "Spatial Controller";

	}

	else if (UsageID == 16) {

		resultsID = "Assistive Control";

	}

	else if (UsageID == 17) {

		resultsID = "Device Dock";

	}

	else if (UsageID == 18) {

		resultsID = "Dockable Device ";

	}

	else if (UsageID >= 19 && UsageID <= 47) {

		resultsID = "Reserved";

	}

	else if (UsageID == 48) {

		resultsID = "X";

	}

	else if (UsageID == 49) {

		resultsID = "Y";

	}

	else if (UsageID == 50) {

		resultsID = "Z";

	}

	else if (UsageID == 51) {

		resultsID = "Rx"; // right stick x

	}

	else if (UsageID == 52) {

		resultsID = "Ry"; // right stick y

	}

	else if (UsageID == 53) {

		resultsID = "Rz"; // right stick z

	}

	else if (UsageID == 54) {

		resultsID = "Slider";

	}

	else if (UsageID == 55) {

		resultsID = "Dial";

	}

	else if (UsageID == 56) {

		resultsID = "Wheel";

	}

	else if (UsageID == 57) {

		resultsID = "Hat Switch ";

	}

	else if (UsageID == 58) {

		resultsID = "Counted Buffer";

	}

	else if (UsageID == 59) {

		resultsID = "Byte Count";

	}

	else if (UsageID == 60) {

		resultsID = "Motion Wakeup";

	}

	else if (UsageID == 61) {

		resultsID = "Start";

	}

	else if (UsageID == 62) {

		resultsID = "Select";

	}

	else if (UsageID == 63) {

		resultsID = "Reserved";

	}

	else if (UsageID == 64) {

		resultsID = "Vx";

	}

	else if (UsageID == 65) {

		resultsID = "Vy";

	}

	else if (UsageID == 66) {

		resultsID = "z";

	}

	else if (UsageID == 67) {

		resultsID = "Vbrx";

	}

	else if (UsageID == 68) {

		resultsID = "Vbry";

	}

	else if (UsageID == 69) {

		resultsID = "Vbrz";

	}

	else if (UsageID == 70) {

		resultsID = "Vno";

	}

	else if (UsageID == 71) {

		resultsID = "Feature Notification";

	}

	else if (UsageID == 72) {

		resultsID = "Resolution Multiplier";

	}

	else if (UsageID == 73) {

		resultsID = "Qx";

	}

	else if (UsageID == 74) {

		resultsID = "Qy";

	}

	else if (UsageID == 75) {

		resultsID = "Qz";

	}

	else if (UsageID == 76) {

		resultsID = "Qw";

	}

	else if (UsageID >= 77 && UsageID <= 127) {

		resultsID = "Reserved";

	}

	else if (UsageID == 128) {

		resultsID = "System Control";

	}

	else if (UsageID == 129) {

		resultsID = "System Power Down";

	}

	else if (UsageID == 130) {

		resultsID = "System Sleep";

	}

	else if (UsageID == 131) {

		resultsID = "System Wake Up";

	}

	else if (UsageID == 132) {

		resultsID = "System Context Menu";

	}

	else if (UsageID == 133) {

		resultsID = "System Main Menu";

	}

	else if (UsageID == 134) {

		resultsID = "System App Menu";

	}

	else if (UsageID == 135) {

		resultsID = "System Menu Help";

	}

	else if (UsageID == 136) {

		resultsID = "System Menu Exit";

	}

	else if (UsageID == 137) {

		resultsID = "System Menu Select";

	}

	else if (UsageID == 138) {

		resultsID = "System Menu Right";

	}

	else if (UsageID == 139) {

		resultsID = "System Menu Left";

	}

	else if (UsageID == 140) {

		resultsID = "System Menu Up";

	}

	else if (UsageID == 141) {

		resultsID = "System Menu Down";

	}

	else if (UsageID == 142) {

		resultsID = "System Cold Restart";

	}

	else if (UsageID == 143) {

		resultsID = "System Warm Restart";

	}

	else if (UsageID == 144) {

		resultsID = "D-pad Up";

	}

	else if (UsageID == 145) {

		resultsID = "D-pad Down";

	}

	else if (UsageID == 146) {

		resultsID = "D-pad Right";

	}

	else if (UsageID == 147) {

		resultsID = "D-pad Left ";

	}

	else if (UsageID == 148) {

		resultsID = "Index Trigger";

	}

	else if (UsageID == 149) {

		resultsID = "Palm Trigger";

	}

	else if (UsageID == 150) {

		resultsID = "Thumbstick";

	}

	else if (UsageID == 151) {

		resultsID = "System Function Shift";

	}

	else if (UsageID == 152) {

		resultsID = "System Function Shift Lock";

	}

	else if (UsageID == 153) {

		resultsID = "System Function Shift Lock Indicator";

	}

	else if (UsageID == 154) {

		resultsID = "System Dismiss Notification";

	}

	else if (UsageID == 155) {

		resultsID = "System Do Not Disturb";

	}

	else if (UsageID >= 156 && UsageID <= 159) {

		resultsID = "Reserved";

	}

	else if (UsageID == 160) {

		resultsID = "System Dock ";

	}

	else if (UsageID == 161) {

		resultsID = "System Undock ";

	}

	else if (UsageID == 162) {

		resultsID = "System Setup";

	}

	else if (UsageID == 163) {

		resultsID = "System Break";

	}

	else if (UsageID == 164) {

		resultsID = "System Debugger Break";

	}

	else if (UsageID == 165) {

		resultsID = "Application Break";

	}

	else if (UsageID == 166) {

		resultsID = "Application Debugger Break";

	}

	else if (UsageID == 167) {

		resultsID = "System Speaker Mute";

	}

	else if (UsageID == 168) {

		resultsID = "System Hibernate";

	}

	else if (UsageID >= 169 && UsageID < 175) {

		resultsID = "Reserved";

	}

	else if (UsageID == 176) {

		resultsID = "System Display Invert";

	}

	else if (UsageID == 177) {

		resultsID = "System Display Internal";

	}

	else if (UsageID == 178) {

		resultsID = "System Display External";

	}

	else if (UsageID == 179) {

		resultsID = "System Display Both";

	}

	else if (UsageID == 180) {

		resultsID = "System Display Dual";

	}

	else if (UsageID == 181) {

		resultsID = "System Display Toggle Int/Ext Mode";

	}

	else if (UsageID == 182) {

		resultsID = "System Display Swap Primary/Secondary";

	}

	else if (UsageID == 183) {

		resultsID = "System Display Toggle LCD Autoscale";

	}

	else if (UsageID >= 184 && UsageID <= 191) {


		resultsID = "Reserved";
	}

	else if (UsageID == 192) {

		resultsID = "Sensor Zone";

	}

	else if (UsageID == 193) {

		resultsID = "RPM";

	}

	else if (UsageID == 194) {

		resultsID = "Coolant Level";

	}

	else if (UsageID == 195) {

		resultsID = "Coolant Critical Level";

	}

	else if (UsageID == 196) {

		resultsID = "Coolant Pump";

	}

	else if (UsageID == 197) {

		resultsID = "Chassis Enclosure";

	}

	else if (UsageID == 198) {

		resultsID = "Wireless Radio Button";

	}

	else if (UsageID == 199) {

		resultsID = "Wireless Radio LED";

	}

	else if (UsageID == 200) {

		resultsID = "Wireless Radio Slider Switch";

	}

	else if (UsageID == 201) {

		resultsID = "System Display Rotation Lock Button";

	}

	else if (UsageID == 202) {

		resultsID = "System Display Rotation Lock Slider Switch";

	}

	else if (UsageID == 203) {

		resultsID = "Control Enable";

	}

	else if (UsageID >= 204 && UsageID < 207) {

		resultsID = "Reserved";

	}

	else if (UsageID == 208) {

		resultsID = "Dockable Device Unique ID";

	}

	else if (UsageID == 209) {

		resultsID = "Dockable Device Vendor ID";

	}

	else if (UsageID == 210) {

		resultsID = "Dockable Device Primary Usage Page";

	}

	else if (UsageID == 211) {

		resultsID = "Dockable Device Primary Usage ID";

	}

	else if (UsageID == 212) {

		resultsID = "Dockable Device Docking State";

	}

	else if (UsageID == 213) {

		resultsID = "Dockable Device Display Occlusion";

	}

	else if (UsageID == 214) {

		resultsID = "Dockable Device Object Type";

	}

	else if (UsageID >= 215 && UsageID <= 65535) {

		resultsID = "Reserved";

	}

	else {

		resultsID = "Unknown Desktop Page ID";

	}

	return resultsID;

}
