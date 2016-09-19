#ifndef _IMAGEFUNCTIONS_H
#define _IMAGEFUNCTIONS_H

#include <utils.h>
#include <iso646.h>

class ImageFunctions{
	
	private:

	public:
		ImageFunctions();
		void editPixel(Mat *image, const int x, const int y, const int channel, const int value);
		void showPixelValue(Mat *image, const int x, const int y);
		int getChannelValue(Mat *image, const int x, const int y, const int channel);
		void applyConvolution(Mat *image, Mat1f *mask);
};

#endif