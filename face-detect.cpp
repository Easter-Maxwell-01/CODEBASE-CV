/*
	Author : Easter Maxwell
	Date : 1st December, 2022
*/
/*
	Program : Image layout / display
	[this is my first computer vision project / program]
*/
/*
				           REQUIREMENTS
	opencv tool must be installed and setup before running this program. 
	To do so, watch this -> https://www.youtube.com/watch?v=unSce_GPwto.
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

using namespace std;

int main()
{
	cv::Mat image;

	image = cv::imread("C:\\Users\\MAX EASTER\\Downloads\\Tumblr.png");

	cv::putText(image, 
				"detected : orangutan",	/*text*/
				cv::Point(80, 400),	/*text position*/
				cv::FONT_HERSHEY_SIMPLEX,/*font type*/
				1.0, /*font scale*/
				0.0, /*text color (black)*/
				2.8	/*text thickness*/
		       );

	/*file not found!*/
	if (image.empty())
	{
		cout << "\n";
		cout << "`--> Error : image file not found!" << endl;
		cout << "`--> #Resolve : check file path / directory";
		cout << "\n";

		exit(100);
	}

	/*display image*/
	cv::imshow("Face Detection Application", image);

	/*set the window size*/
	cv::moveWindow("Face Detection Application", 0, 45);

	/*create the window layout*/
	namedWindow("Face Detection Application", WINDOW_AUTOSIZE);

	/*save image to project directory*/
	cv::imwrite("C:\\Users\\MAX EASTER\\Downloads\\Tumblr.png", image);

	/*wait for key press*/
	cv::waitKey(0);
	/*terminate the window*/
	cv::destroyAllWindows();

	return -1;

}
