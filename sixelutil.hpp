#ifndef STRV_DRAWSIXEL_HPP
#define STRV_DRAWSIXEL_HPP

#include <vector>
#include <string>
#include <algorithm>
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

        template <typename T>
        static int vectorFinder(std::vector<T> vec, T elm) {
            auto itr = std::find(vec.begin(), vec.end(), elm);
            size_t index = std::distance(vec.begin(), itr);
            if (index != vec.size()) {
                std::cout << 1;
                return 1;
            }else{
                std::cout << 0;
                return 0;
            }
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
            const int step = img.step;

            if (img.depth() != CV_8U) {
                img.convertTo(img, CV_8U, 1.0/255);
            }
            cv::split(img, planes);

            std::vector<cv::Vec3b> palettes;
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    palettes.push_back(img.at<cv::Vec3b>(row, col));
                }
            }

            std::cout << std::endl;
            for (auto p: palettes) {
                std::cout << p << std::endl;
            }

            //cv::imshow("image", img);
            //cv::waitKey(0);

            return ret;
        }
};

#endif // STRV_DRAWSIXEL_HPP
