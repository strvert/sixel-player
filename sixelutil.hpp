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
};

#endif // STRV_DRAWSIXEL_HPP
