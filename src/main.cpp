#include <utils.h>
#include <imagefunctions.h>

int stackFilters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	
	return stackFilters(argc, argv);

	/*
	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	Mat image, imageOut;

	if((ut->loadImage(argv[1], &image)) == false){
		return -1;
	}
	
	//ut->showImage(&imageOut);
	//cout << image.channels();
	// imf->showPixelValue(&image, 0, 0);
	// imf->editPixel(&image, 0, 0, 2, 255);
	// imf->showPixelValue(&image, 0, 0);
	// cout << imf->getChannelValue(&image, 0, 0, 2) << endl;
	// ut->showImage(&image);
	Mat1f mask;
	mask = ut->loadCSV(argv[2]);
	// cout << mask.at<float>(2,2) << endl;
	// cout << mask.at<float>(1,1) << endl;
	// cout << mask.channels() << endl;
	//cout << mask.rows << mask.cols << endl;
	// imf->applyConvolution(&image, &mask, &imageOut);
	// ut->showImage(&imageOut);
	
	imf->applyConvolution(&image, &mask, &imageOut, true);
	ut->showImage(&imageOut);

	delete imf;
	delete ut;*/
    return 0;

}

int stackFilters(int argc, char* argv[])
{
	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	vector<Mat*> images;

	while (--argc)
	{
		Mat* image = new Mat;

		if (ut->loadImage(argv[argc], image) == false)
			return -1;

		//ut->showImage(image);
		images.push_back(image);
	}

	Mat imageOut;
	imf->applyFilter(images, imageOut, ImageFunctions::MEAN);
	ut->showImage(&imageOut);

	delete imf;
	delete ut;

	return 0;
}