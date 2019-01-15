#ifndef STRV_DRAWSIXEL_HPP
#define STRV_DRAWSIXEL_HPP

#include <vector>
#include <string>
#include <iostream>

#include "sixel.hpp"

class SixelUtil{
    private:
        static const char DCS = '\220';
        static const char ST = '\234';

        static void startSixel() {
            std::cout << DCS << "0;0;8q" << "\"1;1" << std::endl;
        }

        static void endSixel() {
            std::cout << ST;
        }

    public:
        static void writeImage() {
            startSixel();
            endSixel();
        }

        static void newStream() {

        }

        static void endStream() {

        }

        static Sixel loadImageFromRaw() {
            Sixel ret;

            return ret;
        }

        static Sixel loadImage(std::string img_path) {
            Sixel ret;
            std::vector<cv::Mat> planes;

            cv::Mat img = cv::imread(img_path, cv::IMREAD_UNCHANGED);
            const int channels = img.channels();
            const int cols = img.cols;
            const int rows = img.rows;

            if (img.depth() != CV_8U) {
                img.convertTo(img, CV_8U, 1.0/255);
            }
            cv::split(img, planes);

            std::cout << planes[0] << std::endl;
            std::cout << planes[1] << std::endl;
            std::cout << planes[2] << std::endl;

            std::cout << img.depth() << CV_8U << std::endl;

            cv::imshow("image", img);
            cv::waitKey(0);

            return ret;
        }
};

#endif // STRV_DRAWSIXEL_HPP
