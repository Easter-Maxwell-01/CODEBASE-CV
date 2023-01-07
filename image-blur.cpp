/*
       Author : Easter Maxwell
       Date : 28th December, 2022

       Program : Blur image using Gaussian blur
*/

#include <iostream>
#include <windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat gray;
    Mat blur;
    Mat image;
    Mat edges;
    const int ratio = 1;
    int low_threshold = 50;

    /*higher threshold -> more blur*/

    /*image source [fill-in an image path!]*/
    image = imread("");

    if (image.empty())
    {
        cerr << endl
             << "\a`--> Error : loading image!"
             << endl;

        Sleep(2000);

        return -1;
    }

    
    /*convert image color to grayscale*/
    cvtColor(image, gray, COLOR_BGR2GRAY);

    /*
      lower number -> less blur
      larger number -> more blur
      note: must be an odd number
    */
    Size kernel_size(5, 5);

    /*GBlur(inputImage, outputImage, size, 0)*/
    GaussianBlur(gray, blur, kernel_size, 0);

    /*
      detect edges in the image using canny edge detector
      canny(grayscale image, detector's output, lowthreshold, lowthreshold * 1)
    */
    Canny(blur, edges, low_threshold, low_threshold * ratio);

    /*diplay images*/
    imshow("original", image);
    imshow("Processed", edges);

    waitKey();

    destroyAllWindows();

    return 0;

}
