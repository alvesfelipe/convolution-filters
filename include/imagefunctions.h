#ifndef _IMAGEFUNCTIONS_H
#define _IMAGEFUNCTIONS_H

#include <utils.h>

class ImageFunctions{
	
	private:

	public:
		ImageFunctions();
		void editPixel(Mat *image, const int x, const int y, const int R, const int G, const int B);
		void showPixelValue(Mat *image, const int x, const int y);
};

#endif