#include "inc/Core/SPANN/ExtraFullGraphSearcher.h"
#include "inc/Core/Common.h"
#include "inc/Core/VectorIndex.h"
#include "IExtraSearcher.h"
#include "Options.h"

#include <boost/program_options.hpp>
#include <iostream>

using namespace SPTAG;
namespace po = boost::program_options;


int main(int argc, char** argv){
    SPTAGLIB_LOG(Helper::LogLevel::LL_Info, "Begin parse postings!");

    std::string inputFile;
    std::string valueType;
    std::string fullListFile;
    std::string headVectorIDsFile;
    std::string outputFile;

    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("input-file,i", po::value<std::string>(&inputFile), "Input file (e.g., msmarco_1)")
            ("value-type,v", po::value<std::string>(&valueType), "Type of values (e.g., float)")
            ("full-list-file,f", po::value<std::string>(&fullListFile), "Full list binary file (e.g., SPTAGFullList.bin)")
            ("head-vector-ids,h", po::value<std::string>(&headVectorIDsFile), "Head vector IDs binary file (e.g., SPTAGHeadVectorIDs.bin)")
            ("output-file,o", po::value<std::string>(&outputFile), "Output file (e.g., output.txt)")
            ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }
    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    } catch(...) {
        std::cerr << "Unknown error!\n";
        return 1;
    }
    std::cout << "Input File: " << inputFile << std::endl;
    std::cout << "Value Type: " << valueType << std::endl;
    std::cout << "Full List File: " << fullListFile << std::endl;
    std::cout << "Head Vector IDs File: " << headVectorIDsFile << std::endl;
    std::cout << "Output File: " << outputFile << std::endl;
    

    std::shared_ptr<IExtraSearcher> m_extraSearcher;
    Options m_options;
    

    SPTAGLIB_LOG(Helper::LogLevel::LL_Info, "Parse postings completed!");
    return 0;
}