#include <utils.h>
#include <imagefunctions.h>

int main(int argc, char* argv[]){
	
	Utils *ut = new Utils();
	ImageFunctions *imf = new ImageFunctions();

	Mat image;

	if(ut->loadImage("/home/felipe/Downloads/Passarinho.jpg", &image));
		ut->showImage(&image);

	imf->showPixelValue(&image, 0, 0);
	imf->editPixel(&image, 0, 0, 0, 0, 0);
	imf->showPixelValue(&image, 0, 0);

	delete imf;
	delete ut;	
    return 0;
}