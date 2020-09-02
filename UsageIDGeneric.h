#pragma once

#include <windows.h>
#include <setupapi.h>
#include <Hidclass.h>
#include <iostream>
#include <stdio.h> 
#include <hidsdi.h>
#include <exception>

#define WIN32_LEAN_AND_MEAN //remove the unneeded


std::string UsageIDG_CONVERT(int UsageID); // generic destop page converter - more can be added if asked


