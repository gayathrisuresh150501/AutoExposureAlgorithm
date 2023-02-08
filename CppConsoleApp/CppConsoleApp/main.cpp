/*
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main()
{
    cv::Mat img = cv::imread("C:/Users/gayat/Downloads/Gojo/g1.jpg");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
*/

#include "stdafx.h"

#include <assert.h> 
#include <stdio.h> 
#include <sys/timeb.h> 
#include <memory.h> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <uchar.h>

#include <FlyCapture2.h>

using namespace FlyCapture2;

float entropyof(Mat img)
{
	cv::Mat grey_image;
	cv::cvtColor(img, grey_image, CV_BGR2GRAY);
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