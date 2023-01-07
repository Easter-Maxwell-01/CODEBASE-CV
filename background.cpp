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
    double frame_width;
    double frame_height;

    Ptr<BackgroundSubtractor> motion_detector;

    /*open default camera*/
    VideoCapture camera(0);

    /*didn't succeed*/
    if (!camera.isOpened())
    {
        cerr << "\n`--> Error : opening camera" << endl;

        Sleep(2000);

        return 1;
    }

    /*set up the motion detector*/
    motion_detector = createBackgroundSubtractorMOG2();

    /*get the width and height of the frame*/
    frame_width = camera.get(cv::CAP_PROP_FRAME_WIDTH);
    frame_height = camera.get(cv::CAP_PROP_FRAME_HEIGHT);

    /*  
        Define the codec and create a VideoWriter object. 
        The video output is stored in 'video_file.mp4v' file.
    */
    VideoWriter video("video_file.mp4v", cv::VideoWriter::fourcc
    ('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));

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

        /*save the video file*/
        video.write(foreground);

        /*check for user input*/
        key = (char)waitKey(30);

        /*escape key*/
        if (key == 27)
        {
            cout << "\n`--> Program terminated!" << endl;

            Sleep(2000);

            break;
        }
    }

    return 0;

}
