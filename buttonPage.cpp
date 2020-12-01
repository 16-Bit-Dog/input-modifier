
#include "buttonPage.h"
#include <string>




std::string UsageButton_CONVERT(int UsageID) { // generic destop page converter - more can be added if asked - also yes this could have been a switch case statment with a function to control the ranges (but I realized the reason to make it more efficent in that sense would matter little)

	std::string resultsID;

	resultsID = "Button " + std::to_string(UsageID);

	if (UsageID == 0) {

		resultsID = "No Button Pressed";

	}


		
	return resultsID;
}



