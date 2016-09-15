#ifndef _UTILS_H
#define _UTILS_H

#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Utils{
	
	private:

	public:
		Utils();
		bool loadImage(string file, Mat image);
	
};

#endif