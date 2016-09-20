#include <imagefunctions.h>

ImageFunctions::ImageFunctions(){}

void ImageFunctions::editPixel(Mat *image, const int x, const int y, const int channel, const int value)
{

	if(0<=x && x<=image->rows && 0<=y && y<=image->cols)
	{
		
		Vec3b intensity = image->at<Vec3b>(Point(x, y));
	    if(channel == 0)
	    	intensity.val[0] = value;
	    if(channel == 1)
	    	intensity.val[1] = value;
	    if(channel == 2)
	    	intensity.val[2] = value;
	    image->at<Vec3b>(Point(x,y)) = intensity;
	    
	    return;
	}

	cout << "ERROR, THIS PIXEL DOESN'T EXISTS" << endl;
}

void ImageFunctions::showPixelValue(Mat *image, const int x, const int y)
{
	
	if(0<=x && x<=image->rows && 0<=y && y<=image->cols)
	{

		Vec3b intensity = image->at<Vec3b>(x, y);
		int r = intensity.val[2];
		int g = intensity.val[1];
		int b = intensity.val[0];
    	cout << "R: " << r << " G: " << g << " B: " << b << endl;
		
		return;
	}

	cout << "ERROR, THIS PIXEL DOESN'T EXISTS" << endl;
}

int ImageFunctions::getChannelValue(Mat *image, const int x, const int y, const int channel){

	if(0<=x && x<=image->rows && 0<=y && y<=image->cols)
	{	
		int r, g, b;

		Vec3b intensity = image->at<Vec3b>(x, y);
		if(channel == 2)
			return r = intensity.val[2];
		if(channel == 1)
			return g = intensity.val[1];
		if(channel == 0)
			return b = intensity.val[0];
		
	}
	return -1;
	cout << "ERROR, THIS PIXEL DOESN'T EXISTS" << endl;
}

void ImageFunctions::applyConvolution(Mat *image, Mat1f *mask, Mat *imageOut){

	float gx, gy, gz;
	float maskCenter, norm = 0;
	int g = 0, auxI, auxJ;

	*imageOut = image->clone();

	maskCenter = mask->rows/2;	
	//cout << "MASK CENTER: " << maskCenter << endl;
	for(int imageHeight = 0; imageHeight < image->rows; imageHeight++)
	{
		for(int imageWidth = 0; imageWidth < image->cols; imageWidth++)
		{
			for (int channel = 0; channel <= 2; channel++)
			{	//cout << "I/J- " << imageHeight << " " << imageWidth << endl;
				auxI = imageHeight - maskCenter; auxJ = imageWidth - maskCenter;
				//cout << "INITIAL AUXI/J " << auxI << " " << auxJ << endl;
				//cout << "CHANNEL: " << channel << endl; 
				for(int maskHeight = mask->rows - 1; maskHeight >= 0 ; maskHeight--)
				{
					for(int maskWidth = mask->cols - 1; maskWidth >= 0; maskWidth--)
					{	
						//cout << "auxI: " << auxI  << " auxJ: " << auxJ << endl;
						if((auxI) >= 0 && (auxJ) >= 0)
						{
							// int chann = this->getChannelValue(image, auxI - maskCenter , 
							// 					 auxJ - maskCenter, channel);
							g += (this->getChannelValue(image, auxI, auxJ, channel) * 
														mask->at<float>(maskHeight, maskWidth));
							//cout << "G: " << g << endl;
							//cout << "img Height: " << auxI << " img Width: " << auxJ << " Mask: " << mask->at<float>(maskHeight, maskWidth) << " Channel: " << this->getChannelValue(image, auxI, auxJ, channel) << endl;
							norm += mask->at<float>(maskHeight, maskWidth);
						}
						auxJ ++;
					}
					auxJ = imageWidth - maskCenter;
					auxI ++;
				}

				if (norm > 0)
					g /= norm;

				g = abs(g);

				//if (g < 0){g = 0;}
				if (g > 255){g = 255;}

				this->editPixel(imageOut, imageWidth, imageHeight, channel, g);
				
				auxI = 0; auxJ = 0; g = 0, norm = 0;
			}
		}
	}
}

void ImageFunctions::applyConvolution(Mat *image, Mat1f *mask, Mat *imageOut, bool mean){

	float gx, gy, gz;
	float maskCenter, g = 0, result;
	int auxI, auxJ;

	*imageOut = image->clone();

	result = (1.0/(mask->cols * mask->rows));
	
	maskCenter = mask->rows/2;	
	//cout << "MASK CENTER: " << maskCenter << endl;
	for(int imageHeight = 0; imageHeight < image->rows; imageHeight++)
	{
		for(int imageWidth = 0; imageWidth < image->cols; imageWidth++)
		{
			for (int channel = 0; channel <= 2; channel++)
			{	//cout << "I/J- " << imageHeight << " " << imageWidth << endl;
				auxI = imageHeight - maskCenter; auxJ = imageWidth - maskCenter;
				//cout << "INITIAL AUXI/J " << auxI << " " << auxJ << endl;
				//cout << "CHANNEL: " << channel << endl; 
				for(int maskHeight = mask->rows - 1; maskHeight >= 0 ; maskHeight--)
				{
					for(int maskWidth = mask->cols - 1; maskWidth >= 0; maskWidth--)
					{	
						//cout << "auxI: " << auxI  << " auxJ: " << auxJ << endl;
						if((auxI) >= 0 && (auxJ) >= 0)
						{
							g += (this->getChannelValue(image, auxI, auxJ, channel) * result);
							//cout << "G: " << g << endl;
							//cout << "img Height: " << auxI << " img Width: " << auxJ << " Mask: " << mask->at<float>(maskHeight, maskWidth) << " Channel: " << this->getChannelValue(image, auxI, auxJ, channel) << endl;
							//norm += mask->at<float>(maskHeight, maskWidth);
						}
						auxJ ++;
					}
					auxJ = imageWidth - maskCenter;
					auxI ++;
				}

				// if (norm > 0)
				// 	g /= norm;

				g = abs(g);

				//if (g < 0){g = 0;}
				if (g > 255){g = 255;}

				this->editPixel(imageOut, imageWidth, imageHeight, channel, g);
				
				auxI = 0; auxJ = 0; g = 0;
			}
		}
	}
}