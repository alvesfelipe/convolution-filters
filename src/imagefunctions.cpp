#include <imagefunctions.h>

ImageFunctions::ImageFunctions(){}

void ImageFunctions::editPixel(Mat *image, const int x, const int y, const int channel, const int value)
{

	if(0<=x && x<=image->rows && 0<=y && y<=image->cols)
	{
		
		Vec3b intensity = image->at<Vec3b>((x, y));
	    if(channel == 0)
	    	intensity.val[0] = value;
	    if(channel == 1)
	    	intensity.val[1] = value;
	    if(channel == 2)
	    	intensity.val[2] = value;
	    image->at<Vec3b>((x,y)) = intensity;
	    
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

				this->editPixel(imageOut, imageHeight, imageWidth, channel, g);
				
				auxI = 0; auxJ = 0; g = 0, norm = 0;
			}
		}
	}
}

void ImageFunctions::applyConvolution(Mat *image, Mat *imageOut, int m, int n){

	float maskCenter, g = 0, result, norm;
	int auxI, auxJ;

	*imageOut = image->clone();

	result = (1.0/(n * m));
	cout << "result " << result << endl;
	maskCenter = m/2.0;
	cout << "maskCenter " << maskCenter << endl;

	for(int imageHeight = 0; imageHeight < image->rows; imageHeight++)
	{
		for(int imageWidth = 0; imageWidth < image->cols; imageWidth++)
		{
			for (int channel = 0; channel <= 2; channel++)
			{
				auxI = imageHeight - maskCenter; auxJ = imageWidth - maskCenter;

				for(int maskHeight = m - 1; maskHeight >= 0 ; maskHeight--)
				{
					for(int maskWidth = n - 1; maskWidth >= 0; maskWidth--)
					{	
						if((auxI) >= 0 && (auxJ) >= 0)
						{
							g += (this->getChannelValue(image, auxI, auxJ, channel) * result);
						}
						auxJ ++;
					}
					auxJ = imageWidth - maskCenter;
					auxI ++;
				}

				g = abs(g);
				if (g > 255){g = 255;}

				this->editPixel(imageOut, imageHeight, imageWidth, channel, g);
				
				auxI = 0; auxJ = 0; g = 0;
			}
		}
	}
}

void ImageFunctions::optimumMeanConvolution(Mat *image, Mat *imageOut, int m, int n){
	Mat imageOutAux;

	this->applyConvolution(image, imageOut, m, 1);
	this->applyConvolution(imageOut, &imageOutAux, 1, n);

	*imageOut = imageOutAux.clone();
}

int ImageFunctions::meanApplication(vector<int>& pixels)
{
	int sum = 0;

	for (vector<int>::iterator it = pixels.begin(); it != pixels.end(); it++)
		sum += *it;

	return sum / pixels.size();
}

int ImageFunctions::medianApplication(vector<int>& pixels)
{
	sort(pixels.begin(), pixels.end());
	return pixels.size() % 2 ? pixels[pixels.size() / 2] : (pixels[pixels.size() / 2] + pixels[pixels.size() / 2 + 1]) / 2;
}


int ImageFunctions::modeApplication(vector<int>& pixels)
{
	sort(pixels.begin(), pixels.end());

	vector<int> mode;
	mode.push_back(pixels[0]);

	int max = 1;
	int count = 1;

	for (int i = 1; i < pixels.size(); i++)
	{
		if (pixels[i] == pixels[i - 1])
			count++;
		else
			count = 1;
		
		if (count == max)
			mode.push_back(pixels[i]);
		
		else if (count > max)
		{
			max = count;

			if (mode.size() > 1)
			{
				mode.clear();
				mode.push_back(pixels[i]);
			}
		}
	}

	return meanApplication(mode);
}

void ImageFunctions::applyFilter(const vector<Mat*>& images, Mat& imageOut, int method)
{
	imageOut = images[0]->clone();

	for(int i = 0; i < images[0]->rows; i++) {
		for(int j = 0; j < images[0]->cols; j++) {
			for (int channel = 0; channel <= 2; channel++)
			{
				vector<int> pixels;

				for (int img = 0; img < images.size(); img++)
					pixels.push_back(this->getChannelValue(images[img], i, j, channel));

				if (method == ImageFunctions::MEAN)
					this->editPixel(&imageOut, i, j, channel, meanApplication(pixels));

				else if (method == ImageFunctions::MEDIAN)
					this->editPixel(&imageOut, i, j, channel, medianApplication(pixels));

				else if (method == ImageFunctions::MODE)
					this->editPixel(&imageOut, i, j, channel, modeApplication(pixels));
			}
		}
	}
}

void ImageFunctions::histogramEqualization(Mat *image, Mat *imageOut){

	*imageOut = image->clone();
	
	int occurrence[256]{0}, cumulative[256]{0}, scale[256]{0};
	int channel = 0;

	int sizeImage = image->rows * image->cols;
	float alpha = 255.0/sizeImage;

	for(int imageHeight = 0; imageHeight < image->rows; imageHeight++)
	{
		for(int imageWidth = 0; imageWidth < image->cols; imageWidth++)
		{
			occurrence[this->getChannelValue(image, imageHeight, imageWidth, 0)]++;
		}
	}

	for (int i = 1; i < 256; i++)
	{
		cumulative[i] = occurrence[i] + cumulative[i-1];
	}

	for (int i = 0; i < 256; i++)
	{ 	
		scale[i] = cvRound((double)cumulative[i] * alpha);
	}

	for(int imageHeight = 0; imageHeight < image->rows; imageHeight++)
	{
		for(int imageWidth = 0; imageWidth < image->cols*4; imageWidth++)
		{	
			imageOut->at<uchar>(imageHeight, imageWidth) = saturate_cast<uchar>(scale[image->at<uchar>(imageHeight, imageWidth)]);
		}
	}
	cout << getChannelValue(image, 0, 0, 0) << endl;
	cout << getChannelValue(imageOut, 0, 0, 0) << endl;
}