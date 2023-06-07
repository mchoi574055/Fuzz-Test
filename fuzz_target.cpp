#include <cstdint>
#include <curl/curl.h>
#include <string>

using namespace std;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    
    string url(reinterpret_cast<const char*>(data), size);

    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return 0;
}
