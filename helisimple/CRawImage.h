#ifndef CIMAGE_H
#define CIMAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

/**
@author Tom Krajnik
*/
//simple image class

class CRawImage
{
	public:

		CRawImage(int w,int h);
		~CRawImage();

		//saves the image to a file with bmp format
		void saveBmp(const std::string& name="%04i.bmp");

        void saveJPEG(const std::string& name);

		//checks if there are images in the directory and sets the saving number in order to avoid overwriting them
		int  getSaveNumber();

		//plots a vertical and horizontal line crossing at x,y position
		void plotLine(int x,int y);

		//plots a square in the center
		void plotCenter();

		//image parameters
		int width;
		int height;
		int palette;
		int size;
		int bpp;

		//the image data in 24bit RGB bitmap format
		unsigned char* data;
	private:
		//turns the image upside down, usefull for saving
		void swap();

        void swap_jpeg();

		int numSaved;
};

#endif