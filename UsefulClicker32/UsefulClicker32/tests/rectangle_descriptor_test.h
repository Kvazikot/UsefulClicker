#ifndef RECTANGLE_DESCRIPTOR_TEST_H
#define RECTANGLE_DESCRIPTOR_TEST_H

#include <opencv2/opencv.hpp>
#include <cv/rectangle_descriptor.h>

class RectangleDescriptorTest
{
    public:
    QString results_str;
    QImage results_pixmap;
    std::vector<cv::Mat> matrices;

    RectangleDescriptorTest();



};

#endif // RECTANGLE_DESCRIPTOR_TEST_H
