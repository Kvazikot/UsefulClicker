#include <cv/rectangle_descriptor.h>


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

cv::Mat qimage_to_mat_ref(QImage &img, int format) { return cv::Mat(img.height(), img.width(), format, img.bits(), img.bytesPerLine());
}
cv::Mat img2mat(QImage& img)
{
    //outImg = cv::Mat(img.height(), img.width(), format, const_cast<uchar*>(img.bits()), img.bytesPerLine()).clone();
    QImage temp = img.copy();
    cv::Mat res(temp.height(),temp.width(),CV_8UC3,(uchar*)temp.bits(),temp.bytesPerLine());
    cvtColor(res, res, cv::COLOR_BGR2RGB);
    return res;
}
