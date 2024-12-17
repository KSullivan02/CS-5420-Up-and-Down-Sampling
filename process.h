// Kanaan Sullivan
// This is the header file for the processing functions because I felt that they took up too much space in the main

#ifndef PROCESS_H
#define PROCESS_H

#include <opencv2/opencv.hpp>

// Downsample by removing alternate rows and columns
void downsamplePixelDeletion(const cv::Mat& src, cv::Mat& dst);

// Upsample by pixel replication
void upsamplePixelReplication(const cv::Mat& src, cv::Mat& dst);

// Downsample by averaging pixels
void downsampleAveraging(const cv::Mat& src, cv::Mat& dst);

// Upsample using interpolation
void upsampleInterpolation(const cv::Mat& src, cv::Mat& dst);

// Intensity downsampling by reducing bits
void intensityDownsampling(const cv::Mat& src, cv::Mat& dst, int nBits);


#endif