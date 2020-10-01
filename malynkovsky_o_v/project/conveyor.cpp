#include <opencv\cv.h>
#include <opencv2\opencv.hpp>
#include <opencv\highgui.h>
#include <opencv\cxcore.h>
#include "jsoncpp-master\dist\json\json.h"
#include "jsoncpp-master\dist\json\json-forwards.h"
#include <iostream>
#include <filesystem>

namespace fs = std::experimental::filesystem;
typedef std::map <const std::string, int> ImageMap;
class Conveyor
{
public:
    Conveyor() = default;
    Conveyor(std::string pathJSON) {
        Processing(pathJSON);
    }
    ~Conveyor()=default;
    void Processing(std::string pathJSON);
    void Erosion(const char* source,const char* save,const int& erosion_elem,const int& erosion_size, const int& iterate);
    void Dilation(const char* source, const char* save, const int& dilation_elem, const int& dilation_size, const int& iterate);
    void Smoothing(const char* source, const char* save, const int& size1, const int& size2, const int& smtype);
    void Resize(const char* source, const char* save, const int& interpolation, const int& size1, const int& size2);
    bool IsImage(const std::string source);
    std::string GetFileName(const char* source,const char* save);
private:
    ImageMap IM{ { "Erosion",0 },{ "Dilation",1 },{ "Smoothing",2 },{ "Resize",3 }};
};
void Conveyor::Processing(std::string pathJSON)
{
    std::ifstream config_doc(pathJSON, std::ifstream::binary);
    Json::Value root;
    config_doc >> root;
    for (int i(0); i < root.size(); i += 1) {
        std::vector<std::string> ref_to_files;
        for (auto& p : fs::directory_iterator(root[i]["src"].asString())) {
            if (IsImage(p.path().string()))
                ref_to_files.insert(ref_to_files.end(), p.path().string());
        }
        std::cout << root[i]["action"].asString() << " for:" << std::endl;
        switch (IM.at(root[i]["action"].asString()))
        {
        case 0:
            for (int index(0); index < ref_to_files.size(); index += 1)
                Erosion(ref_to_files[index].c_str(), root[i]["dst"].asCString(), root[i]["settings"]["erosion_elem"].asInt(), root[i]["settings"]["erosion_size"].asInt(), root[i]["settings"]["num_iteration"].asInt());
            break;
        case 1:
            for (int index(0); index < ref_to_files.size(); index += 1)
                Dilation(ref_to_files[index].c_str(), root[i]["dst"].asCString(), root[i]["settings"]["dilation_elem"].asInt(), root[i]["settings"]["dilation_size"].asInt(), root[i]["settings"]["num_iteration"].asInt());
            break;
        case 2:
            for (int index(0); index < ref_to_files.size(); index += 1)
                Smoothing(ref_to_files[index].c_str(), root[i]["dst"].asCString(), root[i]["settings"]["size1"].asInt(), root[i]["settings"]["size2"].asInt(), root[i]["settings"]["type"].asInt());
            break;
        case 3:
            for (int index(0); index < ref_to_files.size(); index += 1)
                Resize(ref_to_files[index].c_str(), root[i]["dst"].asCString(), root[i]["settings"]["interpolation"].asInt(), root[i]["settings"]["size1"].asInt(), root[i]["settings"]["size2"].asInt());
            break;
        default:
            break;
        }
    }
    std::cout << "Done!" << std::endl;
}
void Conveyor::Erosion(const char* source,const char* save,const int& erosion_elem,const int& erosion_size, const int& iterate)
{
    using namespace cv;
    std::cout << source << std::endl;
    IplImage* input = cvLoadImage(source, 1);
    int erosion_type;
    if (erosion_elem == 0) { erosion_type = CV_SHAPE_RECT; }
    else if (erosion_elem == 1) { erosion_type = CV_SHAPE_CROSS; }
    else if (erosion_elem == 2) { erosion_type = CV_SHAPE_ELLIPSE; }
    IplConvKernel *structure_element;
    structure_element = cvCreateStructuringElementEx((2 * erosion_size + 1), (2 * erosion_size + 1), erosion_size, erosion_size, erosion_type);
    IplImage* input1(input);
    cvErode(input, input1, structure_element, iterate);
    cvSaveImage(GetFileName(source,save).c_str(), input1);
    std::cout << "Success!" << std::endl;
}
void Conveyor::Dilation(const char* source, const char* save, const int& dilation_elem, const int& dilation_size, const int& iterate)
{
    using namespace cv;
    std::cout << source << std::endl;
    IplImage* input = cvLoadImage(source, 1);
    int dilation_type;
    if (dilation_elem == 0) { dilation_type = CV_SHAPE_RECT; }
    else if (dilation_elem == 1) { dilation_type = CV_SHAPE_CROSS; }
    else if (dilation_elem == 2) { dilation_type = CV_SHAPE_ELLIPSE; }
    IplConvKernel *structure_element;
    structure_element = cvCreateStructuringElementEx((2 * dilation_size + 1), (2 * dilation_size + 1), dilation_size, dilation_size, dilation_type);
    IplImage* input1(input);
    cvSaveImage(GetFileName(source,save).c_str(), input1);
    std::cout << "Success!" << std::endl;
}
void Conveyor::Smoothing(const char* source, const char* save, const int& size1, const int& size2, const int& smtype)
{
    using namespace cv;
    std::cout << source << std::endl;
    IplImage* input = cvLoadImage(source, 1);
    int smooth_type;
    switch (smtype) {
    case 0:
        smooth_type = CV_BLUR_NO_SCALE;
        break;
    case 1:
        smooth_type = CV_BLUR;
        break;
    case 2:
        smooth_type = CV_GAUSSIAN;
        break;
    case 3:
        smooth_type = CV_MEDIAN;
        break;
    case 4:
        smooth_type = CV_BILATERAL;
        break;
    default:
        break;
        }
    IplImage* input1(input);
    cvSmooth(input, input1, smooth_type, size1, size2);
    cvSaveImage(GetFileName(source, save).c_str(), input1);
    std::cout << "Success!" << std::endl;
}
void Conveyor::Resize(const char * source, const char * save, const int & interpolation, const int& size1, const int& size2)
{
    using namespace cv;
    std::cout << source << std::endl;
    IplImage* input = cvLoadImage(source, 1);
    int interpol(0);
    switch (interpol) {
    case 0:
        interpol = CV_INTER_NN;
        break;
    case 1:
        interpol = CV_INTER_LINEAR;
        break;
    case 2:
        interpol = CV_INTER_CUBIC;
        break;
    case 3:
        interpol = CV_INTER_AREA;
        break;
    default:
        break;
    }
    IplImage* input1 = cvCreateImage(Size(size1, size2), input->depth, input->nChannels);
    cvResize(input, input1, interpol);
    cvSaveImage(GetFileName(source, save).c_str(), input1);
    std::cout << "Success!" << std::endl;
}
bool Conveyor::IsImage(const std::string source) {
    size_t found;
    found = source.find_last_of(".");
    /*std::cout << source.substr(found + 1) <<std:: endl;*/
    if (source.substr(found + 1) == "jpg" || source.substr(found + 1) == "jpeg" || source.substr(found + 1) == "png" || source.substr(found + 1) == "gif")
        return true;
    else
        return false;
}
std::string Conveyor::GetFileName(const char* source,const char* save)
{
    std::string fileName("");
    int i = std::string(source).length() - 1;
    while (std::string(source)[i--] != '\\');
    while (i++ != std::string(source).length())
        fileName += std::string(source)[i];
    if (std::string(save).empty())
        save = "save\\";
    if (!fs::exists(std::string(save)))
        fs::create_directory(std::string(save));
    return std::string(save)+fileName;
}

int main(int argc, char* argv[])
{
    std::cout << "Welcome to Conveyor. Type 0 to exit" << std::endl;
    std::string pathJSON;

    if (argc > 1) {
        std::cout << "Enter a path to JSON: " << argv[1] << "\n";
        pathJSON = argv[1];
        Conveyor work(pathJSON);
    }
    else {
        while (1) {
            std::cout << "Enter a path to JSON: " << "\n";
            std::cin >> pathJSON;
            if (pathJSON == "0")
                break;
            Conveyor work(pathJSON);
        }
    }
    return 0;
}

