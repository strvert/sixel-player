#ifndef STRV_SIXEL_HPP
#define STRV_SIXEL_HPP

#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

struct Palette {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

class Sixel {
    private:
        std::vector<unsigned char> rawdata;
        std::vector<Palette> palettes;
        int width;
        int height;

    public:
        Sixel& operator=(Sixel& other) {
            other.width = width;
            return *this;
        }

        void loadImageFromRaw() {
        }

        void loadImage() {
        }
};

#endif // STRV_SIXEL_HPP
