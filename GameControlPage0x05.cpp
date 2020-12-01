
#include "GameControlPage0x05.h"
#include <string>


std::string UsageGameControl_CONVERT(int UsageID) { // generic destop page converter - more can be added if asked - also yes this could have been a switch case statment with a function to control the ranges (but I realized the reason to make it more efficent in that sense would matter little)

	std::string resultsID;

	resultsID = "Button " + std::to_string(UsageID);

	if (UsageID == 0) {

		resultsID = "Undefined";

	}


	else if (UsageID == 1) {

		resultsID = "3d Game Controller";

	}

	else if (UsageID == 2) {

		resultsID = "Pinball Device";

	}

	else if (UsageID == 3) {

		resultsID = "Gun device";

	}
	///
	else if (UsageID == 1) {

		resultsID = "3d Game Controller";

	}

	else if (UsageID == 2) {

		resultsID = "Pinball Device";

	}

	else if (UsageID == 3) {

		resultsID = "Gun device";

	}
	///
	else if (UsageID >=4 && UsageID <=31) {

		resultsID = "Reserved";

	}
	////////////////////////////////////////////////////////////////////
	else if (UsageID == 32) {

		resultsID = "Point of View";

	}

	else if (UsageID == 33) {

		resultsID = "Turn Right/Left";

	}
	else if (UsageID == 34) {

		resultsID = "Pitch Forward/Backward";

	}

	else if (UsageID == 35) {

		resultsID = "Roll Right/Left";

	}
	else if (UsageID == 36) {

		resultsID = "Move Right/Left";

	}

	else if (UsageID == 37) {

		resultsID = "Move Forward/Backward";

	}

	else if (UsageID == 38) {

		resultsID = "Mobe Up/Down";

	}
	else if (UsageID == 39) {

		resultsID = "Lean Right/Left";

	}

	else if (UsageID == 40) {

		resultsID = "Lean Forward/Backward";

	}




	else {

		resultsID = "Unknown gamecontrol page item";

	}


	return resultsID;
}