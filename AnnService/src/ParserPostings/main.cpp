#include "inc/Core/Common.h"
#include "inc/Core/VectorIndex.h"
#include "inc/Core/SPANN/ExtraFullGraphSearcher.h"
#include "inc/Core/SPANN/Options.h"
#include "inc/Helper/ArgumentsParser.h"
#include "inc/Core/VectorIndex.h"
#include "inc/Core/SPANN/Index.h"

#include <boost/program_options.hpp>
#include <iostream>

#define DEBUG(x) std::cout << x << std::endl

using namespace SPTAG;
namespace po = boost::program_options;

struct ListInfo
{
    std::size_t listTotalBytes = 0;

    int listEleCount = 0;

    std::uint16_t listPageCount = 0;

    std::uint64_t listOffset = 0;

    std::uint16_t pageOffset = 0;
};

class ParserOptions : public SPTAG::Helper::ArgumentsParser
{
public:
    ParserOptions()
    {
        AddRequiredOption(indexDir, "-i", "--input", "Index folder.");
        AddRequiredOption(valueType, "-v", "--value", "Value type.");
        AddOptionalOption(fullListFile, "-f", "--full", "Full list file");
        AddOptionalOption(headVectorIDsFile, "-h", "--head", "Head vector ids file");
        AddOptionalOption(outputFile, "-o", "--output", "Output file.");
    }

    ~ParserOptions() {}

public:
    std::string indexDir;
    SPTAG::VectorValueType valueType;
    std::string fullListFile;
    std::string headVectorIDsFile;
    std::string outputFile;
};

int main(int argc, char **argv)
{
    SPTAGLIB_LOG(Helper::LogLevel::LL_Info, "Begin parse postings!");

    std::shared_ptr<ParserOptions> options(new ParserOptions);
    if (!options->Parse(argc - 1, argv + 1))
    {
        exit(1);
    }

    std::shared_ptr<SPTAG::VectorIndex> headIndex;
    auto ret = SPTAG::VectorIndex::LoadIndex(options->indexDir + FolderSep + "HeadIndex", headIndex);
    if (SPTAG::ErrorCode::Success != ret || nullptr == headIndex)
    {
        SPTAGLIB_LOG(Helper::LogLevel::LL_Error, "Cannot open index configure file!");
        return -1;
    }

    std::shared_ptr<SPTAG::VectorIndex> fullIndex;
    ret = SPTAG::VectorIndex::LoadIndex(options->indexDir, fullIndex);
    if (SPTAG::ErrorCode::Success != ret || nullptr == fullIndex)
    {
        SPTAGLIB_LOG(Helper::LogLevel::LL_Error, "Cannot open index configure file!");
        return -1;
    }
    // fullIndex->GetDisk
    std::shared_ptr<SPTAG::SPANN::Index<float>> indexer = std::dynamic_pointer_cast<SPTAG::SPANN::Index<float>>(fullIndex);

    std::shared_ptr<SPTAG::SPANN::ExtraFullGraphSearcher<float>> diskIndex = (std::dynamic_pointer_cast<SPTAG::SPANN::ExtraFullGraphSearcher<float>>(indexer->GetDiskIndex()));

    diskIndex->ShowListings();

    // if (options->valueType == "float")
    // {
    //     searcher.reset(new SPTAG::SPANN::ExtraFullGraphSearcher<float>());
    // }
    // else if (options->valueType == "int")
    // {
    //     searcher.reset(new SPTAG::SPANN::ExtraFullGraphSearcher<int>());
    // }
    // SPTAG::SPANN::Options index_options;

    // index_options.m_indexDirectory = options->indexDir;
    // index_options.m_ssdIndex = options->fullListFile;

    // searcher->LoadIndex(index_options);

    /*
    1. Load BKT Options
    2. Call ExtraFullGraphSearcher::LoadingHeadInfo
 */

    // Options m_options;

    // SPTAGLIB_LOG(Helper::LogLevel::LL_Info, "Parse postings completed!");
    return 0;
}