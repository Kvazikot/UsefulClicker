#ifndef RECTANGLE_DESCRIPTOR_TEST_H
#define RECTANGLE_DESCRIPTOR_TEST_H

#include <opencv2/opencv.hpp>
#include <cv/rectangle_descriptor.h>
#include <QPlainTextEdit>

class RectangleDescriptorTest
{
    public:
       RectangleDescriptorTest(QPlainTextEdit* logger)
       {
           std::vector<std::string> buttons = {"button_cropped.png", "button.png", "button_half_size.png",
                                  "button_scaled_no_aspect.png", "button_with_drawings.png"};
           std::string path_to_images = "./images/rect_descriptor_tests/";
           for(int i=0; i < buttons.size()-1; i++)
           {
               auto sample1 = cv::imread(path_to_images+buttons[i]);
               auto sample2 = cv::imread(path_to_images+buttons[i+1]);
               auto rd1 = RectangleDescriptor( sample1.size[1], sample1.size[0], sample1);
               auto rd2 = RectangleDescriptor( sample2.size[1], sample2.size[0], sample2);
               auto d = rd1.calculateDifference(rd1, rd2);
               QString s = ("RectangleDescriptorTest: ");
               s+=s.sprintf("%s and %s : d = %f \n", buttons[i].c_str(), buttons[i+1].c_str(), d);
               logger->appendPlainText(s);
           }
       }



};

#endif // RECTANGLE_DESCRIPTOR_TEST_H
