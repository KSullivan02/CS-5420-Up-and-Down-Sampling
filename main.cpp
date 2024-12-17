// Kanaan Sullivan
// Main file for Project 3
// Last edit: 10/09/2024

#include <opencv2/opencv.hpp>
#include <iostream>
#include "process.h"

const std::string keys =
    "{h help      |            | Print help message. }"
    "{s sampling  | 1          | Sampling method: 1 for pixel deletion/replication, 2 for averaging/interpolation. }"
    "{d depth     | 1          | Number of levels for downsampling. }"
    "{i intensity | 1          | Intensity levels for downsampling, between 1 and 7. }"
    "{@image      |            | Image file to process. }";

int main(int argc, char** argv) {
    // Parse command-line arguments using OpenCV CommandLineParser
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Image Sampling Program");

    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    int samplingMethod = parser.get<int>("sampling");
    int depth = parser.get<int>("depth");
    int intensity = parser.get<int>("intensity");
    std::string imageFile = parser.get<std::string>("@image");

    if (!parser.check()) {
        parser.printErrors();
        return -1;
    }

    if (intensity < 1 || intensity > 7) {
        std::cerr << "Error: Intensity must be between 1 and 7.\n";
        return -1;
    }

    // Load the input image
    cv::Mat src = cv::imread(imageFile, cv::IMREAD_COLOR);
    if (src.empty()) {
        std::cerr << "Error: Could not open or find the image!\n";
        return -1;
    }

    cv::Mat dst = src.clone();

    // Perform downsampling and upsampling for each level of depth
    for (int level = 0; level < depth; ++level) {
        if (samplingMethod == 1) {
            // Pixel deletion/replication
            downsamplePixelDeletion(dst, dst);
            std::cout << "Downsampled at level " << level + 1 << " using pixel deletion.\n";
        } else if (samplingMethod == 2) {
            // Pixel averaging/interpolation
            downsampleAveraging(dst, dst);
            std::cout << "Downsampled at level " << level + 1 << " using pixel averaging.\n";
        }

        // Apply intensity downsampling
        intensityDownsampling(dst, dst, intensity);
        std::cout << "Applied intensity downsampling with " << (1 << intensity) << " levels.\n";

        // Display the result at each depth level
        cv::imshow("Downsampled Image - Level " + std::to_string(level + 1), dst);
        cv::waitKey(0);  // Wait for key press to proceed
    }

    // Perform upsampling for each level of depth
    for (int level = 0; level < depth; ++level) {
        if (samplingMethod == 1) {
            // Pixel replication
            upsamplePixelReplication(dst, dst);
            std::cout << "Upsampled at level " << level + 1 << " using pixel replication.\n";
        } else if (samplingMethod == 2) {
            // Pixel interpolation
            upsampleInterpolation(dst, dst);
            std::cout << "Upsampled at level " << level + 1 << " using interpolation.\n";
        }

        // Display the result at each depth level
        cv::imshow("Upsampled Image - Level " + std::to_string(level + 1), dst);
        cv::waitKey(0);  // Wait for key press to proceed
    }

    return 0;
}