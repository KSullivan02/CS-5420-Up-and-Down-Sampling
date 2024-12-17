#include "process.h"

// Downsample by removing alternate rows and columns
void downsamplePixelDeletion(const cv::Mat& src, cv::Mat& dst) {
    cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, cv::INTER_NEAREST);
}

// Upsample by pixel replication
void upsamplePixelReplication(const cv::Mat& src, cv::Mat& dst) {
    cv::resize(src, dst, cv::Size(src.cols * 2, src.rows * 2), 0, 0, cv::INTER_NEAREST);
}

// Downsample by averaging pixels
void downsampleAveraging(const cv::Mat& src, cv::Mat& dst) {
    cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, cv::INTER_AREA);
}

// Upsample using interpolation (bilinear by default)
void upsampleInterpolation(const cv::Mat& src, cv::Mat& dst) {
    cv::resize(src, dst, cv::Size(src.cols * 2, src.rows * 2), 0, 0, cv::INTER_LINEAR);
}

// Intensity Downsampling by reducing bits
void intensityDownsampling(const cv::Mat& src, cv::Mat& dst, int nBits) {
    dst = src.clone(); // Clone the source image to keep the same size and type

    int shiftAmount = 8 - nBits; // Calculate how much to shift
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            for (int c = 0; c < src.channels(); c++) {
                // Access each pixel value and apply bitwise shift
                dst.at<cv::Vec3b>(y, x)[c] = (src.at<cv::Vec3b>(y, x)[c] >> shiftAmount) << shiftAmount;
            }
        }
    }
}