#ifndef _IMAGEFUNCTIONS_H
#define _IMAGEFUNCTIONS_H

#include <algorithm>
#include <math.h>
#include <utils.h>
#include <iso646.h>

class ImageFunctions{
	
	private:

	public:
		static const int MEAN = 0;
		static const int MEDIAN = 1;
		static const int MODE = 2;

		ImageFunctions();
		void editPixel(Mat *image, const int x, const int y, const int channel, const int value);
		void showPixelValue(Mat *image, const int x, const int y);
		int getChannelValue(Mat *image, const int x, const int y, const int channel);
		void applyConvolution(Mat *image, Mat1f *mask, Mat *imageOut);
		void applyConvolution(Mat *image, Mat *imageOut, int m, int n);
		void optimumMeanConvolution(Mat *image, Mat *imageOut, int m, int n);

		int meanApplication(vector<int>& pixels);
		int medianApplication(vector<int>& pixels);
		int modeApplication(vector<int>& pixels);
		void applyFilter(const vector<Mat*>& images, Mat& imageOut, int method);

};

#endif