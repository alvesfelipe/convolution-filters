#include <utils.h>

Utils::Utils(){}

bool Utils::loadImage(string file, Mat image){

    image = imread(file, CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return false;
    }

    return true;
}