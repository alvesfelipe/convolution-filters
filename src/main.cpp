#include <utils.h>
#include <imagefunctions.h>

int stackFilters(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	
	//return stackFilters(argc, argv);

	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	if(strcmp(argv[1],"conv") == 0 || strcmp(argv[1],"conv_mean") == 0){
		cout << "conv:" << argv[1] << endl;
		Mat image, imageOut;
		Mat1f mask;

		if((ut->loadImage(argv[2], &image)) == false)
			return -1;
		
		mask = ut->loadCSV(argv[3]);

		if(strcmp(argv[1],"conv_mean") == 0){
			imf->applyConvolution(&image, &mask, &imageOut, true); ut->showImage(&imageOut);
		}else{
			imf->applyConvolution(&image, &mask, &imageOut); ut->showImage(&imageOut);
		}

	}else if(strcmp(argv[1],"stack") == 0){
		cout << "stack" << endl;
		return stackFilters(argc, argv);
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

	while (--argc)
	{	
		if(argc > 2){
			Mat* image = new Mat;

			if (ut->loadImage(argv[argc], image) == false)
				return -1;

			//ut->showImage(image);
			images.push_back(image);
		}
	}

	Mat imageOut;

	if(strcmp(argv[2],"mean") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MEAN); ut->showImage(&imageOut);
	
	if(strcmp(argv[2],"median") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MEDIAN); ut->showImage(&imageOut);

	if(strcmp(argv[2],"mode") == 0)
		imf->applyFilter(images, imageOut, ImageFunctions::MODE); ut->showImage(&imageOut);

	delete imf;
	delete ut;

	return 0;
}