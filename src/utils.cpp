#include <utils.h>

Utils::Utils(){}

bool Utils::loadImage(string file, Mat *image){

    *image = imread(file, CV_LOAD_IMAGE_COLOR);

    if(! image->data )
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return false;
    }

    cout << "Image Loaded" << endl;
    return true;
}

void Utils::showImage(Mat *image){
	namedWindow("Display window", WINDOW_AUTOSIZE); imshow("Display window", *image); waitKey(0);
}

Mat1f Utils::loadCSV(string file){
	
	Mat1f mask;
	string line, aux;
  	ifstream myfile(file.c_str());
  	std::vector<float> v;
  	
  	if (myfile.is_open())
  	{
	    while (getline(myfile, line))
	    {	
	    	//cout << line << endl;
	    	istringstream ss(line);
	    	while(getline(ss, aux, ',')){
	    		v.push_back(atof(aux.c_str()));
	    	}
	    	
    		Mat1f m1(Mat1f(v).t());
    		mask.push_back(m1);
    		v.clear();
    		m1.release();
	    }
	    
	    myfile.close();
	
	}else cout << "Unable to open file"; 
	
	return mask;

}