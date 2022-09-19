#include "rectangle_descriptor_test.h"


QImage mat2img(cv::Mat& mat, int channels)
{
    if (channels == 1)
        cv::cvtColor(mat, mat, cv::COLOR_GRAY2BGR);
    QPixmap pix = QPixmap(mat.cols, mat.rows);
    std::vector<uchar> im_buf_arr;
    cv::imencode(".png", mat, im_buf_arr);
    QByteArray byte_im((char*)&im_buf_arr[0], im_buf_arr.size());
    pix.loadFromData(byte_im);
    return pix.toImage();
}

//def img2mat(qimag, channels_count):
//        outImg = np.zeros((qimag.height(), qimag.width() ,3), dtype=np.uint8)
//        bufersize = qimag.height() * qimag.width() * 4
//        b = qimag.bits()
//        b.setsize(qimag.height() * qimag.width() * channels_count)
//        outImg = np.frombuffer(b, np.uint8).reshape((qimag.height(), qimag.width(), channels_count))
//        return outImg

using namespace std;

RectangleDescriptorTest::RectangleDescriptorTest()
{

    vector<pair<string,string>> buttons = { make_pair("button_with_drawings.png","button.png"),
                                            make_pair("button_cropped.png", "button.png"),
                                            make_pair("button.png", "button_scaled_no_aspect.png"),
                                            make_pair("button_half_size.png", "button_scaled_no_aspect.png")};
    std::string path_to_images = "./images/rect_descriptor_tests/";
    cv::Mat mat;
    std::vector<cv::Mat> hstack;

    QString s = ("RectangleDescriptorTest: \n");
    for(auto i=buttons.begin(); i != buttons.end(); i++)
    {
        auto sample1 = cv::imread(path_to_images+i->first);
        auto sample2 = cv::imread(path_to_images+i->second);
        auto rd1 = RectangleDescriptor( sample1.size[1], sample1.size[0], sample1);
        auto rd2 = RectangleDescriptor( sample2.size[1], sample2.size[0], sample2);
        auto d = rd1.calculateDifference(rd1, rd2);
        s+=s.sprintf("%s and %s : d = %f \n\n", i->first.c_str(), i->second.c_str(), d);
        results_str+= s;
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
