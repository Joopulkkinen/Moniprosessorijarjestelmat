#include <lodepng.cpp>
#include <lodepng.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



unsigned char* decodeOneStep(const char* filename)
{
	unsigned error;
	unsigned char* image;
	unsigned width, height;

	error = lodepng_decode32_file(&image, &width, &height, filename);
	if (error) printf("error %u: %s\n", error, lodepng_error_text(error));


	
	return image ;
	free(image);
}

/*
The image argument has width * height RGBA pixels or width * height * 4 bytes
*/
void encodeOneStep(const char* filename, const unsigned char* image, unsigned width, unsigned height)
{
	/*Encode the image*/
	unsigned error = lodepng_encode32_file(filename, image, width, height);

	/*if there's an error, display it*/
	if (error) printf("error %u: %s\n", error, lodepng_error_text(error));
}


unsigned char* downsize(unsigned char* image) {

	unsigned char* testi = (unsigned char*)malloc((735 * 504 * 4) * sizeof(unsigned char));


	for (int h = 0, h1 = 0; h1 < 2017; h++, h1 = h1 + 4) {
			for (int w = 0, w1 = 0; w1 < 2929; w1 = w1 + 16, w = w + 4) {

				testi[(h * 504) + w + 0] = image[h1 * 2016 + w1 + 0];
				testi[(h * 504) + w + 1] = image[h1 * 2016 + w1 + 1];
				testi[(h * 504) + w + 2] = image[h1 * 2016 + w1 + 2];
				testi[(h * 504) + w + 3] = image[h1 * 2016 + w1 + 3];
			}
			
	}
	return testi;
}

void main() {

	unsigned char* image2;
	unsigned char* image3;
	image2 = decodeOneStep("test.png");


	

	image3 = downsize(image2);
	


	for (int i = 0; i < 4; i++) {
		std::cout << int(image2[i]) << std::endl;
	}
	std::cout << int(23423432424) << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << int(image3[i]) << std::endl;
	}
	std::cout << int(image3[370440]) << std::endl;



	lodepng_encode32_file("test2.png", image3, 735, 504);


	




}