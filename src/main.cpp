#include <utils.h>
#include <imagefunctions.h>

int stackFilters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	
	//return stackFilters(argc, argv);

	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	if(strcmp(argv[1],"stack") == 0){
		cout << "stack" << endl;
		return stackFilters(argc, argv);
	}
	else{
		cout << "conv:" << argv[1] << endl;
		Mat image, imageOut;
		Mat1f mask;

		if((ut->loadImage(argv[2], &image)) == false)
			return -1;

		if(strcmp(argv[1],"conv_mean") == 0){
			imf->applyConvolution(&image, &imageOut, atoi(argv[3]), atoi(argv[4]));
		}
		else if(strcmp(argv[1],"conv") == 0){
			mask = ut->loadCSV(argv[3]);
			imf->applyConvolution(&image, &mask, &imageOut);
		}
		else if(strcmp(argv[1],"conv_mean_optimum") == 0){
			imf->optimumMeanConvolution(&image, &imageOut, atoi(argv[3]), atoi(argv[4]));
		}
		else if(strcmp(argv[1],"gaussian") == 0){
			Mat1f* mask = ut->genGaussianMask(atof(argv[3]), atoi(argv[4]));
			imf->applyConvolution(&image, mask, &imageOut);
			delete mask;
		}
		else return -1;

		ut->showImage(&imageOut);
	}

	delete imf;
	delete ut;
    return 0;

}

int stackFilters(int argc, char* argv[])
{
	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	vector<Mat*> images;

	while (--argc >= 3)
	{	
		Mat* image = new Mat;

		if (ut->loadImage(argv[argc], image) == false)
			return -1;

		//ut->showImage(image);
		images.push_back(image);
	}

	Mat imageOut;

	if (strcmp(argv[2], "mean") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MEAN);
	
	else if (strcmp(argv[2], "median") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MEDIAN);

	else if (strcmp(argv[2], "mode") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MODE);

	ut->showImage(&imageOut);

	delete imf;
	delete ut;

	return 0;
}