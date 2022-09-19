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

RectangleDescriptorTest::RectangleDescriptorTest()
{
    std::vector<std::string> buttons = {"button_cropped.png", "button.png", "button_half_size.png",
                           "button_scaled_no_aspect.png", "button_with_drawings.png","button.png"};
    std::string path_to_images = "./images/rect_descriptor_tests/";
    cv::Mat mat, sample11, res, res2;
    std::vector<cv::Mat> hstack;

    for(int i=0; i < buttons.size()-1; i++)
    {
        auto sample1 = cv::imread(path_to_images+buttons[i]);
        auto sample2 = cv::imread(path_to_images+buttons[i+1]);
        auto rd1 = RectangleDescriptor( sample1.size[1], sample1.size[0], sample1);
        auto rd2 = RectangleDescriptor( sample2.size[1], sample2.size[0], sample2);
        auto d = rd1.calculateDifference(rd1, rd2);
        QString s = ("RectangleDescriptorTest: \n");
        s+=s.sprintf("%s and %s : d = %f \n\n", buttons[i].c_str(), buttons[i+1].c_str(), d);
        results_str+= s;

        sample1.copyTo(mat);
        sample2.copyTo(sample11);
        cv::resize(sample1, sample11, cv::Size(sample2.size[1], sample2.size[0]), cv::INTER_LINEAR);
//        //= {sample1, sample1};
        cv::hconcat(sample11, sample2, mat );
        cv::Mat* m = new cv::Mat(mat.rows, mat.cols, mat.type());
        mat.copyTo(*m);
        hstack.push_back(*m);
    }

    cv::Mat tmp, tmp2;
    hstack[0].copyTo(tmp);
    hstack[0].copyTo(tmp2);
    for( auto it=hstack.begin(); it!=hstack.end()-1; it++)
        cv::resize(*it, *it, cv::Size(hstack[0].size[1], hstack[0].size[0]), cv::INTER_LINEAR);

    hstack[0].copyTo(tmp);
    for( auto it=hstack.begin(); it!=hstack.end()-1; it++)
    {
        cv::vconcat(*it, tmp, tmp2);
        tmp2.copyTo(tmp);
    }

    results_pixmap = mat2img(tmp2, 3);



}
