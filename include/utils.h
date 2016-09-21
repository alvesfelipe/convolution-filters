#ifndef _UTILS_H
#define _UTILS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

class Utils{
	
	private:

	public:
		Utils();
		bool loadImage(string file, Mat *image);
		void showImage(Mat *image);
		Mat1f loadCSV(string file);
		Mat1f* genGaussianMask(float sigma, int n);
	
};

#endif
