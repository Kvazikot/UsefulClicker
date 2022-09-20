#ifndef RECTANGLE_DESCRIPTOR_TEST_H
#define RECTANGLE_DESCRIPTOR_TEST_H

#include <opencv2/opencv.hpp>
#include <cv/rectangle_descriptor.h>
#include <QImage>

QImage mat2img(cv::Mat& mat, int channels);
void img2mat(QImage& img, cv::Mat3b& outImg, int format);

class RectangleDescriptorTest
{
    public:
    QString results_str;
    QImage results_pixmap;
    std::vector<cv::Mat> matrices;
    std::vector<std::pair<std::string,std::string>> buttons;
    std::string path_to_images;

    RectangleDescriptorTest();
    void compressionTest();
    void compareTest();



};

#endif // RECTANGLE_DESCRIPTOR_TEST_H
