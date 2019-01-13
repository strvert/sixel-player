#include "sixelutil.hpp"
#include "sixel.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv){
    using namespace std;
    using namespace cv;

    SixelUtil::writeImage();

    Mat image;
    image = imread(argv[1], IMREAD_COLOR);

    // for(int row = 0; row < image.rows; row++){
    //     for(int col = 0; col < image.rows; col++){
    //         cout << image.at<Vec3b>(row, col) << endl;
    //     }
    // }
}
