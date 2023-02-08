#include <assert.h> 
#include <stdio.h> 
#include <sys/timeb.h> 
#include <memory.h> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//============================================================================= 
//OpenCV includes 
//============================================================================= 
#include <Opencv2/core/core.hpp>
#include <Opencv2/highgui/highgui.hpp>
#include <Opencv2/imgproc/imgproc.hpp>
//============================================================================= 
// Project Includes 
//============================================================================= 
#include <FlyCapture2.h>
#include <tchar.h>
using namespace cv;

float entropyof(cv::Mat img)
{
	cv::Mat grey_image;
	cvtColor(img, grey_image, cv::COLOR_BGRA2GRAY);
	float probability_array[256] = { 0 };
	int rows = grey_image.rows;
	int cols = grey_image.cols;
	//cout<<grey_image.at<uchar>(0,26);
	// counting pixel differences.
	for (int i = 0; i < grey_image.rows; i++)
	{
		for (int j = 1; j < grey_image.cols; j++)
		{
			//cout<<i<<" "<<j<<" "<<(int)grey_image.at<uchar>(i,j)<<endl;
			int a = (int)grey_image.at<uchar>(i, j);
			int b = (int)grey_image.at<uchar>(i, j - 1);
			int x = a - b;
			if (x < 0)
				x = 0 - x;
			probability_array[x]++;
			//grey_image.at<uchar>(i,j) = 255;
		}
	}
	//calculating probability
	int n = rows * cols;
	for (int i = 0; i < 256; i++)
	{
		probability_array[i] /= n;
		//cout<<probability_array[i]<<endl;
	}
	// galeleo team formula
	float entropy = 0;
	for (int i = 0; i < 256; i++)
	{
		if (probability_array[i] > 0)
		{
			float x = probability_array[i] * log(probability_array[i]);
			entropy += x;
		}
	}
	return 0 - entropy;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
