#include <cstdint>
#include <string>
#include <fstream>
#include <streambuf>
#include <curl/curl.h>

using namespace std;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    std::ifstream t(argv[1]);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    LLVMFuzzerTestOneInput((const uint8_t *)str.data(), str.size());
    return 0;
}
