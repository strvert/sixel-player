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

        }

        static Sixel loadImage(std::string img_path) {
            cv::Mat img = cv::imread(img_path, IMREAD_COLOR);
            const int channels = img.channels();
            const int cols = img.cols;
            const int rows = img.rows;
            unsigned char *pixel_ptr = image.data;

            for (int row = 0; i < rows; row++) {
                for (int col = 0; i < cols; col++) {
                    const int pi = row*cols*channels + col*channels;
                }
            }

        }
};

#endif // STRV_DRAWSIXEL_HPP
