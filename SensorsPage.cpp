
#include "SensorsPage.h"
#include <string>






std::string UsageSensors_CONVERT(int UsageID) { // generic destop page converter - more can be added if asked - also yes this could have been a switch case statment with a function to control the ranges (but I realized the reason to make it more efficent in that sense would matter little)

	std::string resultsID;

	if (UsageID == 0) {

		resultsID = "Undefined";

	}


	else if (UsageID == 1) {

		resultsID = "Sensor";

	}

	else if (UsageID == 112) {

		resultsID = "Motion";

	}

	else if (UsageID == 113) {

		resultsID = "Motion: Accelerometer 1D";

	}

	//////////////////////////
	else if (UsageID == 114) {

		resultsID = "Motion: Accelerometer 2D";

	}

	else if (UsageID == 115) {

		resultsID = "Motion: Accelerometer 3D";

	}

	else if (UsageID == 116) {

		resultsID = "Motion: Gyrometer 1D";

	}

	else if (UsageID == 117) {

		resultsID = "Motion: Gyrometer 2D";

	}

	else if (UsageID == 118) {

		resultsID = "Motion: Gyrometer 3D";

	}

	//////////////////////////
	else if (UsageID == 119) {

		resultsID = "Motion: Motion Detector";

	}

	else if (UsageID == 120) {

		resultsID = "Motion: Speedometer";

	}

	else if (UsageID == 221) {

		resultsID = "Motion: Accelerometer";

	}

	else if (UsageID == 222) {

		resultsID = "Motion: Gyrometer";

	}

	else if (UsageID == 223) {

		resultsID = "Motion: Gravity Vector";

	}

	else if (UsageID == 224) {

		resultsID = "Motion: Linear Accelerometer";

	}
	else {

		resultsID = "unimplemented Sensor... there are hundreds...";

	}
	return resultsID;
}