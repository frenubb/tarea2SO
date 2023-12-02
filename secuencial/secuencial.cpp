#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int maint(int argc, char** argv){
	if(argc != 3){
		cout << "Uso: " << argv[0] << " <imagen_entrada> <imagen_salida>" << endl;
		return -1;
	}

	Mat image = imread(argv[1], IMREAD_COLOR);
	if(image.empty()){
		cout << "La imagen no se puede leer" << endl;
		return -1
	}

	// metodo conversion
	for(int f=0; f<image.rows; f++){
		for(int c=0; c<image.cols; c++){
			Vec3b pixel = image.at<Vec3b>(f, c);
			int gris_val = 0.299*pixel[2] + 0.587*pixel[1] + 0.114*pixel[0];

			pixel[0] = pixel[1] = pixel[2] = gris_val

			image.at<Vec3b>(f, c) = pixel;
		}
	}

	imwrite(arg[2], image);
	return 0;
}
