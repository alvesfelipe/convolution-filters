#ifndef _UTILS_H
#define _UTILS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "opencv/cv.hpp"
//#include <opencv2/ml/ml.hpp>
// #include <opencv2/opencv_modules.hpp>
// #include <opencv2/opencv.hpp>
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
