/*
	Author : Easter Maxwell
	Date : 7th December, 2022

	Program : change given image to gray
*/

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat image;
	cv::Mat gray_image;

	/*place image here!*/
	image = cv::imread("");

	/*file not found*/
	if (image.empty())
	{
		/*error sound*/
		cout << "\a";
		cout << "\n";

		cout << "`--> image path not found!" << endl;
		cout << "`--> #Resolve : check image path / directory";

		cout << "\n\n";

		exit(100);
	}

	/*change image color to gray*/
	cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

	cv::imshow("colored image : ", image);
	cv::imshow("Grayed image : ", gray_image);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return -1;

}
