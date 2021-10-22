#include "CVWindow.cpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MyExperiment : public CVWindow {
  public:
    MyExperiment() : CVWindow("My Experiment") {}
    ~MyExperiment() {}

  private:
    cv::Mat &buildFrame(cv::Mat &frame) override final {

        // auto kernel = Mat::ones(3, 3, CV_32F) / 9;

        // Sharpen:

        // int values[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
        // Mat kernel(cv::Size2i(3, 3), CV_32SC1, values);
        // cv::filter2D(frame, frame, -1, kernel);

        cv::GaussianBlur(frame, frame, cv::Size2i(3, 3), 0);

        // int values[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
        // Mat kernel(cv::Size2i(3, 3), CV_32SC1, values);
        // cv::filter2D(frame, frame, -1, kernel);

        // cv::fastNlMeansDenoisingColored(frame, frame);

        return frame;
    }
};

int main(int argc, char *argv[]) {

    MyExperiment window;
    window.open();

    return 0;
}
