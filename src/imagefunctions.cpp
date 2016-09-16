#include <imagefunctions.h>

ImageFunctions::ImageFunctions(){}

void ImageFunctions::editPixel(Mat *image, const int x, const int y, const int R, const int G, const int B){
	if(x <= image->rows && y <= image->cols){
		
		Vec3b intensity = image->at<Vec3b>(Point(x, y));
	    intensity.val[0] = B;
	    intensity.val[1] = G;
	    intensity.val[2] = R;
	    image->at<Vec3b>(Point(x,y)) = intensity;
	    
	    return;
	}

	cout << "ERROR, THIS PIXEL DOESN'T EXISTS" << endl;
}

void ImageFunctions::showPixelValue(Mat *image, const int x, const int y){
	
	if(x <= image->rows && y <= image->cols){

		Vec3b intensity = image->at<Vec3b>(x, y);
		int r = intensity.val[2];
		int g = intensity.val[1];
		int b = intensity.val[0];
    	cout << "R: " << r << " G: " << g << " B: " << b << endl;
		
		return;
	}

	cout << "ERROR, THIS PIXEL DOESN'T EXISTS" << endl;
}