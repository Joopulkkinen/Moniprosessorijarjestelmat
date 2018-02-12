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

	unsigned char *testi = (unsigned char*)malloc((2940 * 2016 * 4) * sizeof(unsigned char));

	for (int h = 0, h1 = 0, height = 0; h <= 2016; h = h + 4, h1++) {
		height = h * 2016;
		for (int w = 0, w1 = 0; w <= 2490; w = w + 16, w1++) {
			testi[(h1 * 504) + w1 + 0] = image[height + w + 0];
			testi[(h1 * 504) + w1 + 1] = image[height + w + 1];
			testi[(h1 * 504) + w1 + 2] = image[height + w + 2];
			testi[(h1 * 504) + w1 + 3] = image[height + w + 3];
		}
	}



	return testi;
}

void main() {

	unsigned char* image2;
	unsigned char* image3;
	image2 = decodeOneStep("test.png");


	

	image3 = downsize(image2);
	lodepng_encode32_file("test2.png", image3, 2940, 2016);
	std::cout << int(image2[0]);
	std::cout << int(image2[1]) << std::endl;

	std::cout << int(image3[0]);
	std::cout << int(image3[1]);



	




}