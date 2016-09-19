#include <utils.h>
#include <imagefunctions.h>

int main(int argc, char* argv[]){
	
	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	Mat image;

	if((ut->loadImage(argv[1], &image)) == false){
		return -1;
	}
	//cout << image.channels();
	// imf->showPixelValue(&image, 0, 0);
	// imf->editPixel(&image, 0, 0, 2, 255);
	// imf->showPixelValue(&image, 0, 0);
	// cout << imf->getChannelValue(&image, 0, 0, 2) << endl;
	// ut->showImage(&image);
	Mat1f test;
	test = ut->loadCSV(argv[2]);
	// cout << test.at<float>(2,2) << endl;
	// cout << test.at<float>(1,1) << endl;
	// cout << test.channels() << endl;
	//cout << test.rows << test.cols << endl;

	imf->applyConvolution(&image, &test);
	ut->showImage(&image);
	delete imf;
	delete ut;	
    return 0;
}