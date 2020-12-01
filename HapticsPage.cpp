
#include "HapticsPage.h"
#include <string>






std::string UsageHaptic_CONVERT(int UsageID) { // generic destop page converter - more can be added if asked - also yes this could have been a switch case statment with a function to control the ranges (but I realized the reason to make it more efficent in that sense would matter little)

	std::string resultsID;

	if (UsageID == 0) {

		resultsID = "Undefined";

	}


	else if (UsageID == 1) {

		resultsID = "Simple Haptic Controller";

	}

	else if (UsageID >= 2 && UsageID <= 15) {

		resultsID = "Reserved";

	}

	else if (UsageID == 16) {

		resultsID = "Waveform List";

	}

	//////////////////////////
	else if (UsageID == 17) {

		resultsID = "Duration List";

	}

	else if (UsageID >= 18 && UsageID <= 31) {

		resultsID = "Reserved";

	}

	else if (UsageID == 32) {

		resultsID = "Auto Trigger";

	}

	else if (UsageID == 33) {

		resultsID = "Manual Trigger";

	}

	else if (UsageID == 34) {

		resultsID = "Auto Trigger Associated Control";

	}

	else if (UsageID == 35) {

		resultsID = "Intensity";

	}


	else if (UsageID == 36) {

		resultsID = "Repeat Count";

	}

	//////////////////////////
	else if (UsageID == 37) {

		resultsID = "Retrigger Period";

	}

	else if (UsageID == 38) {

		resultsID = "Waveform Vendor Page";

	}

	else if (UsageID == 39) {

		resultsID = "Waveform Vendor ID";

	}

	else if (UsageID == 40) {

		resultsID = "Waveform Cutoff Time";

	}

	else if (UsageID >= 41 && UsageID <= 4096) {

		resultsID = "Reserved";

	}

	else if (UsageID == 4097) {

		resultsID = "Waveform None";

	}


	else if (UsageID == 4098) {

		resultsID = "Waveform Stop";

	}


	//////////////////////////
	else if (UsageID == 4099) {

		resultsID = "Waveform Click";

	}

	else if (UsageID == 4100) {

		resultsID = "Waveform Buzz Continuous";

	}

	else if (UsageID == 4101) {

		resultsID = "Waveform Rumble Continuous";

	}

	else if (UsageID == 4102) {

		resultsID = "Waveform Press";

	}

	else if (UsageID == 4103) {

		resultsID = "Waveform Release";

	}

	else {

		resultsID = "Reserved - 2001 - 2FFF is vendor Waveforms";

	}

	return resultsID;
}