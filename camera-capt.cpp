/*
        Author : Easter Maxwell
        Date : 25th December, 2022

        program : camera initialization
*/

#include <iostream>
#include <windows.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() 
{

        Mat frame;
        VideoCapture cap;
       
        /*open default camera*/
        int device_id = 0;  

        /*autodetect default API*/
        int api_id = cv::CAP_ANY;
   
        cap.open(device_id, api_id);

        /*didn't succeed*/
        if (!cap.isOpened()) 
        {
            cerr << "`--> Error : Unable to open camera!";
            
            Sleep(2000);
            cout << endl;

            return -1;
        }

        /*succeeded*/
        cout << "`--> Capture initialized!" << endl;

        Sleep(2000);

        for (;;)
        {
            /*read from frame*/
            cap.read(frame);

            /*didn't succeed*/
            if (frame.empty()) 
            {
                cerr << "`--> Error : blank frame grabbed!";
                
                Sleep(2000);
                cout << endl;

                break;
            }
            
            /*succeeded*/
            imshow("Live", frame);

            if (waitKey(5) >= 0)
            {
                break;
            }
        }

        return 0;

}
