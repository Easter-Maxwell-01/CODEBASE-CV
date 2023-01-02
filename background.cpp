/*
       Author : Easter Maxwell
       Date : 28th December, 2022
       
       Program : background subtractor
       
       Note : use the esc key to exit the program
*/

#include <iostream>
#include <windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    char key;
    Mat frame;
    Mat foreground;

    /*open default camera*/
    VideoCapture camera(0);

    /*didn't succeed*/
    if (!camera.isOpened())
    {
        cerr << " `--> Error : opening camera" << endl;

        Sleep(2000);

        return 1;
    }

    Ptr<BackgroundSubtractor> motion_detector;

    /*set up the motion detector*/
    motion_detector = createBackgroundSubtractorMOG2();

    while (true)
    {
        /*capture a frame*/
        camera >> frame;

        if (frame.empty())
        {
            cerr << "`--> Error : capturing frame" << endl;

            Sleep(2000);

            break;
        }

        /*detect motion in the frame*/
        motion_detector->apply(frame, foreground);

        /*display the frame and foreground*/
        imshow("Surveillance", frame);
        imshow("Foreground", foreground);

        /*check for user input*/
        key = (char)waitKey(30);

        /*escape key*/
        if (key == 27)
        {
            cout << "`--> Program terminated!" << endl;

            Sleep(2000);

            break;
        }
    }

    return 0;

}
