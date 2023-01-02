/*
        Author : Easter Maxwell
        Date : 2nd January, 2022

        Program : video recorder and saver
        
        Note : press 'q', 'Q' to exit the program.
        Note : Videos are stored in the projeect dir.
*/

#include <iostream>
#include <windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() 
{
    Mat frame;
    int codec;
    double fps;
    string file_name;
    VideoWriter writer;
    VideoCapture cap(0);

    /*frame rate*/
    fps = 60.0;

    /*didn't succeed*/
    if (!cap.isOpened())
    { 
        cerr << "`--> Error : Unable to open camera!" << endl;

        Sleep(2000);

        return -1;
    }

    /*select codec type [Motion JPEG codec]*/
    codec = VideoWriter::fourcc('M', 'J', 'P', 'G');

    /*output file*/
    file_name = "video_output.avi";

    /*get frame height and width*/
    Size frameSize(cap.get(cv::CAP_PROP_FRAME_WIDTH), 
                   cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    /*open video writer*/
    writer.open(file_name, codec, fps, frameSize, true);

    /*didn't succeed*/
    if (!writer.isOpened())
    {
        std::cerr << "`--> Error : Unable to open video writer!" << endl;

        Sleep(2000);

        return -1;
    }

    cout << "[:]Press 'q' to stop recording and exit." << endl;

    Sleep(3000);

    while (true)
    {
        /*get frame*/
        cap >> frame;

        /*write the frame*/
        writer.write(frame);

        /*display the frame*/
        cv::imshow("Frame", frame);

        /*check for user input*/
        char key = cv::waitKey(1);

        if (key == 'q' || key == 'Q')
        { 
            break;
        }
    }

    return 0;

}
