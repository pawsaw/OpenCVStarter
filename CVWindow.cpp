#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

class CVWindow {
  public:
    CVWindow(std::string name, int camera = 0);
    virtual ~CVWindow();
    virtual void open() final;

  protected:
    virtual cv::Mat &buildFrame(cv::Mat &frame);

  private:
    std::string _name;
    int _camera;
};

CVWindow::CVWindow(std::string name, int camera)
    : _name(name), _camera(camera) {}

CVWindow::~CVWindow() {}

void CVWindow::open() {
    // Open the default video camera
    cv::VideoCapture cap(0);

    // if not success, exit program
    if (cap.isOpened() == false) {
        std::cout << "Cannot open the video camera" << std::endl;
        std::cin.get(); // wait for any key press
        return;
    }

    double dWidth = cap.get(
        cv::CAP_PROP_FRAME_WIDTH); // get the width of frames of the video
    double dHeight = cap.get(
        cv::CAP_PROP_FRAME_HEIGHT); // get the height of frames of the video

    std::cout << "Resolution of the video : " << dWidth << " x " << dHeight
              << std::endl;

    cv::namedWindow(_name); // create a window called "My Camera Feed"

    while (true) {
        cv::Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video

        // Breaking the while loop if the frames cannot be captured
        if (bSuccess == false) {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get(); // Wait for any key press
            break;
        }

        // show the frame in the created window
        cv::imshow(_name, buildFrame(frame));

        // wait for for 10 ms until any key is pressed.
        // If the 'Esc' key is pressed, break the while loop.
        // If the any other key is pressed, continue the loop
        // If any key is not pressed withing 10 ms, continue the loop
        if (cv::waitKey(10) == 27) {
            std::cout << "Esc key is pressed by user. Stoppig the video"
                      << std::endl;
            break;
        }
    }
}

cv::Mat &CVWindow::buildFrame(cv::Mat &frame) { return frame; }
