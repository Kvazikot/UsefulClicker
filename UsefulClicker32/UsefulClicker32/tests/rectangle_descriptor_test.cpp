#include "rectangle_descriptor_test.h"
#include <QDebug>

using namespace std;



RectangleDescriptorTest::RectangleDescriptorTest()
{
    buttons = { make_pair("button.png","button.png"),
                make_pair("button_with_drawings.png","button.png"),
                make_pair("button_cropped.png", "button.png"),
                make_pair("button.png", "button_scaled_no_aspect.png"),
                make_pair("button_half_size.png", "button_scaled_no_aspect.png")};

    path_to_images = "./images/rect_descriptor_tests/";

}

void RectangleDescriptorTest::compareTest()
{
    cv::Mat mat;
    std::vector<cv::Mat> hstack;

    QString s = ("RectangleDescriptorTest::compareTest: \n");
    for(auto i=buttons.begin(); i != buttons.end(); i++)
    {
        auto sample1 = cv::imread(path_to_images+i->first);
        auto sample2 = cv::imread(path_to_images+i->second);
        if(sample2.rows==0 | sample1.rows==0)
        {
            results_str="FAILED! check test images";
            return;
        }
        //qDebug() << sample2.cols << "x" << sample2.rows;
        RectangleDescriptor* rd1 = new RectangleDescriptor( sample1.size[1], sample1.size[0], sample1);
        RectangleDescriptor* rd2 = new RectangleDescriptor( sample2.size[1], sample2.size[0], sample2);
        auto d = rd1->calculateDifference(*rd1, *rd2);
        s="";
        s.sprintf("%s and %s : d = %f \n", i->first.c_str(), i->second.c_str(), d);
        results_str+=s;
        cv::resize(sample1, sample1, cv::Size(sample2.size[1], sample2.size[0]), cv::INTER_LINEAR);
        cv::hconcat(sample1, sample2, mat );
        cv::Mat* m = new cv::Mat(mat.rows, mat.cols, mat.type());
        mat.copyTo(*m);
        hstack.push_back(*m);
    }

    cv::Mat tmp, tmp2;
    hstack[0].copyTo(tmp);
    hstack[0].copyTo(tmp2);
    for( auto it=hstack.begin(); it!=hstack.end(); it++)
        cv::resize(*it, *it, cv::Size(hstack[0].size[1], hstack[0].size[0]), cv::INTER_LINEAR);

    cv::Mat combined;
    cv::vconcat(hstack, combined);

    results_pixmap = mat2img(combined, 3);

}

void RectangleDescriptorTest::compressionTest()
{
    QString s = ("RectangleDescriptorTest::compressionTest: \n");
    for(auto i=buttons.begin(); i != buttons.end(); i++)
    {
        auto sample1 = cv::imread(path_to_images+i->first);
        auto sample2 = cv::imread(path_to_images+i->second);
        if(sample2.rows==0 | sample1.rows==0)
        {
            results_str="FAILED! check test images";
            return;
        }
        //qDebug() << sample2.cols << "x" << sample2.rows;
        RectangleDescriptor* rd1 = new RectangleDescriptor( sample1.size[1], sample1.size[0], sample1);
        RectangleDescriptor* rd2 = new RectangleDescriptor( sample2.size[1], sample2.size[0], sample2);
        s+="\n"+rd1->toString()+"\n";
        s+="\n"+rd2->toString()+"\n";
    }
    results_str=s;
}
