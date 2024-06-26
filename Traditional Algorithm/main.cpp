#include "kmeans.h"
int main()
{
    vector<vector<vector<int>>> input = {{{167, 149, 149, 133, 157, 154, 155, 180, 184, 159, 159, 149, 143, 25, 35, 62},
                                          {145, 28, 41, 171, 175, 148, 167, 176, 155, 148, 133, 135, 155, 18, 56, 46},
                                          {26, 41, 42, 126, 130, 153, 147, 155, 154, 152, 137, 134, 84, 113, 14, 15},
                                          {18, 22, 18, 122, 128, 126, 126, 128, 133, 136, 137, 130, 95, 14, 41, 13},
                                          {21, 8, 14, 107, 117, 111, 109, 111, 120, 128, 133, 14, 24, 41, 30, 19},
                                          {103, 12, 30, 16, 78, 27, 107, 108, 116, 120, 121, 15, 19, 34, 43, 15},
                                          {16, 14, 41, 46, 22, 31, 113, 119, 123, 133, 13, 12, 26, 54, 18, 16},
                                          {10, 12, 20, 18, 19, 23, 157, 49, 191, 150, 11, 10, 23, 64, 16, 11},
                                          {11, 16, 15, 9, 12, 31, 179, 16, 22, 54, 23, 9, 12, 79, 13, 17},
                                          {10, 8, 27, 16, 23, 28, 25, 19, 51, 24, 20, 26, 16, 13, 18, 21},
                                          {11, 9, 24, 20, 17, 17, 24, 16, 43, 14, 14, 28, 38, 12, 17, 19},
                                          {8, 17, 22, 18, 25, 22, 17, 22, 28, 38, 30, 30, 11, 27, 26, 19},
                                          {19, 23, 26, 27, 26, 23, 19, 13, 14, 42, 16, 23, 11, 24, 21, 20},
                                          {19, 18, 24, 18, 20, 17, 20, 13, 15, 11, 12, 16, 26, 19, 20, 17},
                                          {20, 21, 21, 17, 16, 19, 19, 10, 10, 11, 10, 10, 14, 19, 16, 16},
                                          {18, 17, 17, 17, 18, 15, 16, 14, 11, 65, 75, 74, 14, 10, 4, 6}},
                                         {{194, 181, 179, 160, 182, 184, 184, 204, 207, 181, 182, 172, 166, 36, 38, 66},
                                          {174, 29, 59, 194, 199, 173, 188, 197, 175, 169, 157, 155, 174, 20, 72, 57},
                                          {30, 44, 43, 151, 152, 176, 169, 175, 175, 173, 157, 155, 104, 128, 21, 16},
                                          {23, 23, 19, 145, 150, 147, 148, 151, 152, 159, 158, 150, 110, 15, 56, 16},
                                          {23, 11, 14, 119, 137, 134, 128, 132, 143, 150, 153, 15, 33, 50, 38, 23},
                                          {123, 12, 33, 16, 97, 31, 126, 127, 133, 141, 138, 18, 20, 42, 53, 16},
                                          {16, 14, 47, 51, 23, 32, 133, 137, 141, 149, 17, 13, 29, 67, 19, 17},
                                          {10, 12, 20, 18, 19, 27, 168, 63, 201, 166, 12, 10, 32, 76, 16, 11},
                                          {11, 19, 16, 9, 13, 38, 193, 19, 26, 72, 31, 9, 13, 101, 14, 21},
                                          {10, 8, 28, 17, 24, 31, 25, 28, 71, 32, 25, 34, 17, 17, 20, 28},
                                          {11, 9, 24, 20, 17, 24, 25, 16, 48, 17, 17, 38, 53, 13, 18, 27},
                                          {8, 17, 22, 18, 26, 25, 20, 31, 32, 39, 35, 40, 11, 35, 34, 24},
                                          {20, 24, 32, 33, 30, 31, 24, 16, 18, 53, 20, 31, 12, 33, 26, 25},
                                          {24, 19, 28, 17, 26, 30, 28, 19, 16, 15, 13, 20, 31, 27, 27, 25},
                                          {24, 25, 27, 23, 21, 24, 24, 11, 11, 12, 11, 11, 22, 23, 21, 17},
                                          {19, 18, 22, 18, 21, 18, 19, 15, 16, 95, 105, 105, 17, 10, 4, 5}},
                                         {{200, 192, 200, 173, 192, 201, 199, 207, 210, 190, 190, 178, 158, 32, 62, 103},
                                          {189, 21, 70, 200, 201, 187, 194, 198, 183, 175, 167, 163, 178, 20, 89, 60},
                                          {27, 34, 35, 163, 162, 185, 175, 182, 181, 181, 165, 163, 106, 138, 24, 20},
                                          {18, 21, 15, 153, 158, 154, 156, 160, 164, 165, 166, 158, 118, 19, 62, 21},
                                          {24, 10, 13, 126, 143, 138, 137, 140, 149, 153, 158, 15, 32, 56, 47, 22},
                                          {133, 12, 28, 14, 104, 33, 133, 133, 138, 144, 143, 19, 23, 49, 60, 16},
                                          {16, 15, 47, 48, 21, 33, 133, 135, 139, 146, 16, 13, 34, 72, 21, 17},
                                          {10, 12, 18, 16, 19, 26, 161, 73, 191, 159, 14, 12, 38, 77, 17, 13},
                                          {11, 18, 14, 9, 13, 37, 184, 25, 31, 91, 37, 9, 15, 99, 16, 22},
                                          {10, 8, 28, 17, 24, 32, 26, 36, 86, 38, 32, 36, 19, 16, 24, 32},
                                          {11, 11, 24, 20, 17, 26, 32, 21, 57, 23, 23, 46, 57, 17, 18, 31},
                                          {8, 17, 22, 18, 30, 31, 28, 41, 32, 32, 40, 51, 13, 39, 40, 29},
                                          {20, 26, 34, 33, 33, 35, 29, 22, 21, 60, 23, 37, 12, 34, 31, 30},
                                          {25, 23, 31, 19, 31, 35, 32, 21, 20, 18, 17, 23, 36, 31, 31, 29},
                                          {25, 26, 30, 25, 24, 29, 29, 13, 13, 14, 13, 13, 26, 29, 26, 21},
                                          {21, 20, 24, 22, 27, 24, 27, 18, 17, 115, 135, 135, 31, 12, 4, 7}}};
    kMeans kmeans;
    int width, height;
    vector<kMeans::RGBPixel> rgb_image = kmeans.load_image(input, width, height);
    kmeans.kMeansClustering(rgb_image,3,100);
    kmeans.saveImage("test1.ppm",rgb_image,width, height);
}