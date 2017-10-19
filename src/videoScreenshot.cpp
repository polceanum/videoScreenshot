#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char **argv)
{
    std::string path = argv[1];
    
    cv::VideoCapture cap(path);
    auto const pos=path.find_last_of('/');
    const auto vidName=path.substr(pos+1);
    if(!cap.isOpened())
    {
        std::cout << "Unable to open video " << path << "\n";
        return 0;
    }
    cv::Mat frame;

    bool playVideo = true;
    int crtFrame = 0;
    while (1)
    {
        if(playVideo)
        {
            cap >> frame;
            crtFrame++;
        }
        if(frame.empty())
        {
            break;
        }

        cv::imshow("Video", frame);
        char key = cv::waitKey(25);
        
        if(key == 'p')
        {
            playVideo = !playVideo;
        }

        if(key == 's')
        {
            //save
            std::vector<int> compression_params;
            compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
            compression_params.push_back(9);

            try
            {
                cv::imwrite("../screenshots/"+vidName+"_"+std::to_string(crtFrame-1)+".png", frame, compression_params);
            }
            catch (std::runtime_error& ex)
            {
                fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
                return 1;
            }
        }

        if(key == 'q')
        {
            playVideo = !playVideo;
            break;
        }

        //std::cerr << crtFrame-1 << "\n";
    }
    return 0;
}