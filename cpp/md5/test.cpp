#include <iostream>
#include "md5.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char** argv){

	// cv::Mat image = cv::imread("test_image.jpg");
  cv::Mat image;
  image.release();
	//std::cout << "md5 of grape is : " << md5("grape") << std::endl;	

	MD5 md;
  MD5 md2;
	//std::cout << MD5((char *) image.data) << std::endl;
  //MD5 md1 = MD5((char *)image.data);
  // std::string hex_test = md1.hexdigest();
	// std::cout << hex_test << std::endl;
  
  
  //std::cout << "total is " << image.total() << std::endl;
  //std::cout << "row is "  << image.rows << " cols is " << image.cols << std::endl;
	//std::cout << "element size is " << image.elemSize() << std::endl;
  // std::cout << "real is " <<sizeof(image.data) << std::endl;
  //std::cout << "we got " << image.elemSize() * image.total() << std::endl; 
  // md.update(image.data, 1000);
	md.update((char *)image.data, image.elemSize() * image.total());
	md2.update((char *)NULL,0);
  md.finalize();
  //std::string ss((char *)image.data, 20);
  //ss += "SUFT";
  //md2.update(image.data, 20);
  md2.finalize();
  std::string hex_test = md.hexdigest();

	//std::cout << md5(ss) << std::endl;
  std::cout << hex_test << std::endl;
  std::cout << md2.hexdigest() << std::endl;
	return 0;

}
