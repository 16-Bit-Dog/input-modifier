//Ariel Glasroth
//break points (f9) saved my life in this program... wow was it good
// also this is a program filed under the liscene of apache license 2.0

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
#include "buttonPage.h"
#include "GameControlPage0x05.h"
#include "HapticsPage.h"
#include "SensorsPage.h"



#define WIN32_LEAN_AND_MEAN //remove the unneeded

std::vector <int> ProperDevice = {};

int numberOfDevice;

GUID hidGUID = GUID_DEVCLASS_HIDCLASS;

HDEVINFO handle;

const size_t DEVICE_DETAILS_SIZE = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA) + MAX_PATH;

SP_DEVINFO_DATA type;
PSP_INTERFACE_DEVICE_DETAIL_DATA typePath; // person on stack overflow helped with this issue of delcaring the var
SP_DEVICE_INTERFACE_DATA typePathData;


DEVPROPTYPE name; //name

DWORD length = 0;

bool good = true;

PVOID productN;//get name var
HANDLE product;
LPWSTR namePrintp;

//get buttons vars

HANDLE hHeap = GetProcessHeap(); // to allow me to allocate space to the PHIDP button caps struct and preparsed data
PHIDP_PREPARSED_DATA preparsed;
HIDP_CAPS capsStruct; // has all device essential info
PHIDP_BUTTON_CAPS buttons; // get capability of device (buttons wise)
PHIDP_VALUE_CAPS valueCaps;

ULONG SimpleInputCount; // holds simple input number

DWORD i = 0;

//report input
UCHAR report;
ULONG reportLength;



std::string UsagePage_CONVERT(int UsagePage) { //        ;(   not the most fun if ever, plus I frogot about the constant expression requirment, and how vs code has no ..., so I remade a switch case statment

	std::string resultPage;

	if (UsagePage == 0) {

		resultPage = "undefined";

	}

	else if (UsagePage == 1) {

		resultPage = "Generic Desktop";

	}

	else if (UsagePage == 2) {

		resultPage = "Simulation Controls";

	}
	else if (UsagePage == 3) {

		resultPage = "VR Controls";
	}
	else if (UsagePage == 4) {

		resultPage = "Sport Controls";
	}
	else if (UsagePage == 5) {

		resultPage = "GameControls";
	}
	else if (UsagePage == 6) {

		resultPage = "Game Device Controls";

	}
	else if (UsagePage == 7) {

		resultPage = "Keyboard/Pad";

	}
	else if (UsagePage == 8) {

		resultPage = "LED";

	}
	else if (UsagePage == 9) {

		resultPage = "Button";
	}
	else if (UsagePage == 10) {

		resultPage = "Ordinal";
	}
	else if (UsagePage == 11) {

		resultPage = "Telephony Device";
	}
	else if (UsagePage == 12) {

		resultPage = "Consumer";

	}
	else if (UsagePage == 13) {

		resultPage = "Digitizers";

	}
	else if (UsagePage == 14) {

		resultPage = "Haptics";

	}
	else if (UsagePage == 15) {

		resultPage = "PID";
	}
	else if (UsagePage == 16) {

		resultPage = "Unicode";
	}
	else if (UsagePage == 17) {

		resultPage = "Reserved";
	}
	else if (UsagePage == 18) {

		resultPage = "Eye/Head Tracker";
	}
	else if (UsagePage == 19) {

		resultPage = "Reserved";
	}
	else if (UsagePage == 20) {

		resultPage = "Auxilairy Display";
	}
	else if (UsagePage >= 21 && UsagePage <= 31) { // could have used a function for this in a switch case


		resultPage = "Reserved";
	}

	else if (UsagePage == 32) {

		resultPage = "Sensors";

	}
	else if (UsagePage >= 33 && UsagePage <= 63) {

		resultPage = "Haptics";

	}

	else {
		resultPage = "Unknown/Unlisted (if a request about a device being unlisted is posted, I will add more identifiers";
	}

	return resultPage;

}

void GetState(PHIDP_PREPARSED_DATA preparsed, PCHAR report, ULONG reportLength) {



	// HERE LIES ME PRINTING OUT -data-

		//Sleep(1000);


}



void setup() {
	system("RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters 1, True"); //update

	std::cout << "\nif you see nothing after a while, click enter and everything will load\n\n"; // print number in HID thing to later extract packets from it and look at avaible buttons ect...

	typePathData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	type.cbSize = sizeof(SP_DEVINFO_DATA);

	HidD_GetHidGuid(&hidGUID);

	handle = SetupDiGetClassDevs(&hidGUID, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);


	if (handle == INVALID_HANDLE_VALUE) // test handle
	{
		std::cout << GetLastError() << "\noof, handle info was done wrong\n\n";

	}



	for (i = 0; i == i; i++) { // used the for loop format from Dan77062, Thanks for the neat code format ;)
		good = true;

		SetupDiEnumDeviceInfo(handle, i, &type);

		std::cout << "\nnumber: " << i << "\n\n";
		// get name property

		SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_NAME, &name, NULL, NULL, &length, NULL);
		if (length > 0) {
			namePrintp = (LPWSTR)malloc(length);
			SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_NAME, &name, (PBYTE)namePrintp, length, &length, 0);
			wprintf(L"\nname: %s\n\n", namePrintp);

		}

		// get name
		SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_Device_Manufacturer, &name, NULL, NULL, &length, NULL);
		if (length > 0)
		{

			LPWSTR namePrint = (LPWSTR)malloc(length);
			SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_Device_Manufacturer, &name, (PBYTE)namePrint, length, &length, 0);

			wprintf(L" \nCreator of Device: %s\n\n", namePrint);
			free(namePrint);

			if (GetLastError() != 0) {
				std::cout << "\n property collection is not a success:" << GetLastError() << "\n\n";
				good = false;
			}

		}

		SetupDiEnumDeviceInterfaces(handle, 0, &hidGUID, i, &typePathData);
		if (GetLastError() != 0) {
			std::cout << "\n interface handling is not a success:" << GetLastError() << "\n\n";
		}


		if (GetLastError() == ERROR_NO_MORE_ITEMS) {
			std::cout << "\n interface failed\n\n";
			good = false;
		}

		DWORD size = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA) + MAX_PATH;


		typePath = (PSP_INTERFACE_DEVICE_DETAIL_DATA)malloc(size);
		typePath->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);

		SetupDiGetDeviceInterfaceDetail(handle, &typePathData, typePath, size, &size, NULL);

		printf("\n\nMaking Device Handle: %ls \n\n", typePath->DevicePath); //breaking convention of printing due to data not being user important --> but may have use if someone wants a quick easy debug for their own program


		product = CreateFileW(typePath->DevicePath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

		if (GetLastError() == 0) {
			//std::cout << "\n file handle creation is a success\n\n";
		}
		else {

			std::cout << "\n file handle collection is not a success (or final value is reached):" << GetLastError() << "\n\n";

		}

		if (product == INVALID_HANDLE_VALUE) {
			std::cout << "Handle is invalid \n";
			good = false;
		}


		//get buttons avaible for use

		if (HidD_GetPreparsedData(product, &preparsed)) {

			if (preparsed == NULL) {
				std::cout << "\n preparsed data collection FAILED: " << GetLastError() << "\n\n";
				good = false;
			}



			if (HidP_GetCaps(preparsed, &capsStruct)) {

				std::cout << "\n\n Usage Page: " << UsagePage_CONVERT((int)capsStruct.UsagePage) << "\n\n";

				if ((int)capsStruct.UsagePage == 1) {
					std::cout << "\n\n Usage ID (generic device pages only): " << UsageIDG_CONVERT((int)capsStruct.Usage) << "\n\n";
				}

				hHeap = GetProcessHeap();

				buttons = (PHIDP_BUTTON_CAPS)HeapAlloc(hHeap, 0, sizeof(HIDP_BUTTON_CAPS) * capsStruct.NumberInputButtonCaps);

				HidP_GetButtonCaps(HidP_Input, buttons, &capsStruct.NumberInputButtonCaps, preparsed); // thank you random person on MSDN forums, I had no idea I did not need to use a report type var!


				std::cout << "\n Number of Inputs found:  " << buttons->Range.UsageMax - buttons->Range.UsageMin + 1 << "\n\n\n\n\n\n\n\n";

				if ((buttons->Range.UsageMax - buttons->Range.UsageMin + 1) > 0 && good == true) {

					ProperDevice.push_back(i);
				}
				else {

					std::cout << "\n INVALID INPUT COUNT \n\n";


				}

				CloseHandle(product);

			}
			HidD_FreePreparsedData(preparsed);
		}
		else {

			std::cout << "\n\n\npreparsed data not retrived\n\n\n\n\n\n\n\n";

		}





		if (good == false) {
			break;
		}

	}
























	std::cout << "Possibley Good Devices: \n\n\n\n\n\n\n";
	for (int x = 0; x < ProperDevice.size(); x++) { // game controller

		std::cout << "\n" << ProperDevice[x] << "\n";

	}

	std::cout << "\nchose which device you want to look at (enter number + enter) -> incorrect numbers may cause unexpected results\n"; // remove keyboard and mouse devices
	std::cin >> numberOfDevice;

	// DEVICE CHOSEN

	SetupDiDestroyDeviceInfoList(handle);

	HDEVINFO handle;

	handle = SetupDiGetClassDevs(&hidGUID, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);

	SetupDiEnumDeviceInfo(handle, numberOfDevice, &type);

	std::cout << "\n\n\n\n\n\n\n\nnnumber: " << numberOfDevice << "\n\n";
	// get name property

	SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_NAME, &name, NULL, NULL, &length, NULL);
	if (length > 0) {
		namePrintp = (LPWSTR)malloc(length);
		SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_NAME, &name, (PBYTE)namePrintp, length, &length, 0);
		wprintf(L"\nname: %s\n\n", namePrintp);



	}

	// get name
	SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_Device_Manufacturer, &name, NULL, NULL, &length, NULL);
	if (length > 0)
	{

		LPWSTR namePrint = (LPWSTR)malloc(length);
		SetupDiGetDeviceProperty(handle, &type, &DEVPKEY_Device_Manufacturer, &name, (PBYTE)namePrint, length, &length, 0);

		wprintf(L" \nCreator of Device: %s\n\n", namePrint);
		free(namePrint);

		//reset type path since it is a mess

		typePathData.cbSize = 0;



		typePathData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

		SetupDiEnumDeviceInterfaces(handle, 0, &hidGUID, numberOfDevice, &typePathData);



		DWORD size = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA) + MAX_PATH;


		typePath = (PSP_INTERFACE_DEVICE_DETAIL_DATA)malloc(size);
		typePath->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);





		SetupDiGetDeviceInterfaceDetail(handle, &typePathData, typePath, size, &size, NULL);



		printf("\n\nMaking Device Handle: %ls \n\n", typePath->DevicePath); //breaking convention of printing due to data not being user important --> but may have use if someone wants a quick easy debug for their own program


		product = CreateFileW(typePath->DevicePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

		std::cout << GetLastError();

		if (HidD_GetPreparsedData(product, &preparsed)) {



			if (HidP_GetCaps(preparsed, &capsStruct)) {

				hHeap = GetProcessHeap();
				//pre-fill most needed items

				buttons = (PHIDP_BUTTON_CAPS)HeapAlloc(hHeap, 0, sizeof(HIDP_BUTTON_CAPS) * capsStruct.NumberInputButtonCaps);
				//

				HidP_GetButtonCaps(HidP_Input, buttons, &capsStruct.NumberInputButtonCaps, preparsed); // thank you random person on MSDN forums, I had no idea I did not need to use a report type var

				//SimpleInputCount = buttons->Range.UsageMax - buttons->Range.UsageMin + 1;

				//std::cout << "\n Number of Inputs found:  " << buttons->Range.UsageMax - buttons->Range.UsageMin + 1 << "\n\n";

				int arrayButton; // gets button array item for remote if any exists
				int arraySensor; // gets sensor array item for remote if any exists

				std::string page;

				std::cout << "\n\n USAGEPAGES:\n";
				for (int i = 0; i < sizeof(buttons); i++) { // sift to find buttons usage
					page = UsagePage_CONVERT((int)buttons[i].UsagePage);

					std::cout << "\n\n" << page << "\n\n\n";

					if (page == "Button") {
						std::cout << "\n\n\t\t" << UsageButton_CONVERT(buttons[i].UsagePage)<< "\n\n\n";
						

					}

					else if (page == "Haptics") {
						std::cout << "\n\n\t\t" << UsageHaptic_CONVERT(buttons[i].UsagePage)<< "\n\n\n";
						

					}
										
					else if (page == "GameControls") {
						std::cout << "\n\n\t\t" << UsageGameControl_CONVERT(buttons[i].UsagePage)<< "\n\n\n";
						
						

					}

					else if (page == "Sensors") {
						std::cout << "\n\n\t\t" << UsageSensors_CONVERT(buttons[i].UsagePage)<< "\n\n\n";
						

					}
										
					
				}
				std::cout << "\n---\n";

				//PHIDP_BUTTON_CAPS SButtons = (PHIDP_BUTTON_CAPS)HeapAlloc(hHeap, 0, sizeof(HIDP_BUTTON_CAPS) * capsStruct.NumberInputButtonCaps);// spesific buttons

				//HidP_GetSpecificButtonCaps(HidP_Input, USAGE(0x09), NULL, NULL, SButtons, &capsStruct.NumberInputButtonCaps, preparsed); // get array of spesific button caps - that I identify with usage - funny stuff here, most emu's say button 1 when mapping controllers because thats how HID usage is handdled for the button usage page




				PHIDP_DATA data;
				data = (PHIDP_DATA)malloc(sizeof(PHIDP_DATA));



				ULONG dataLength = HidP_MaxDataListLength(HidP_Input, preparsed);



				UCHAR ID = (UCHAR)malloc(capsStruct.InputReportByteLength);

				try {


				}
				catch (...) {

					std::cout << ("This device does not have buttons");
					abort();
				}

				// gotten the idea from some site on egmont.com
				DWORD dwRead;
				BOOL fWaitingOnRead = FALSE;
				OVERLAPPED osReader = { 0 };
				osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

				PVOID buffer = new PVOID;

				HidD_GetInputReport(product, buffer, capsStruct.InputReportByteLength + 1);

				//	PCHAR Report;


				//	if (ReadFile(product, &Report, capsStruct.InputReportByteLength, &dwRead, &osReader)) {

				//		HidP_InitializeReportForID(HidP_Input,(Report), preparsed, Report, capsStruct.InputReportByteLength);

				//		std::cout << "LEE ROY!!!";
				///		
				//	}

				//	else {

				//		std::cout << GetLastError();

			//		}

					//HidP_GetData(HidP_Input, data, &dataLength, preparsed, Report, capsStruct.InputReportByteLength+1);



					//NTSTATUS hi = HidP_GetData(HidP_Input, data, &dataLength, preparsed, (PCHAR)buffer[0], capsStruct.InputReportByteLength); // returns only buttons in selected usage - now it works!

				USAGE usageList[128]; // max button count

				for (int i = 0; i < 100; i++) {
					usageList[i] = 0;
				}

				ULONG ul = buttons[0].Range.UsageMax - buttons[0].Range.UsageMin + 1;

				USAGE usageListOLD[128];

				USAGE BreakUsageList[128];

				USAGE MakeUsageList[128];

				while (true) {

				again:

					if (!fWaitingOnRead) {
						//ReadFile(product, Report, capsStruct.InputReportByteLength, &dwRead, &osReader);


						//HidP_GetData(HidP_Input, data, &dataLength, preparsed, Report, capsStruct.InputReportByteLength + 1);


						HidP_GetUsages(HidP_Input, buttons->UsagePage, 0, usageList, &ul, preparsed, PCHAR(buffer), capsStruct.InputReportByteLength + 1);


						HidP_UsageListDifference(usageListOLD, usageList, BreakUsageList, MakeUsageList, capsStruct.InputReportByteLength);
					}

					Sleep(100);

					//	if (GetLastError() != ERROR_IO_PENDING) {
//
				//		std::cout << "waiting";

						//	}

				//	}


				}

				CloseHandle(product);



				//HidP_GetUsages(HidP_Input, buttons->UsagePage, 0, usage, &rl, preparsed, report, reportLength);//get button states, thanks to https://www.codeproject.com/Articles/185522/Using-the-Raw-Input-API-to-Process-Joystick-Input
				// now I have all buttons on the usage page --> that are on or off state (so not analog triggers for example)


				//GetState(preparsed,report,reportLength);


			}


		}


	}

	CloseHandle(product);
}





int main() {

	setup();



}


// THIS BELOW CODE HELPS GET ADVANCED BUTTONS LIKE TRIGGERS, and their values!!! --> anything that is not on or off, like sensors (I think)
/*if (&capsStruct.NumberInputValueCaps > 0) {

	valueCaps = (PHIDP_VALUE_CAPS)HeapAlloc(hHeap, 0, SimpleInputCount * sizeof(HIDP_VALUE_CAPS));

	HidP_GetValueCaps()
}*/
