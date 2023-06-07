#include <cstdint>
#include <curl/curl.h>
#include <string>

using namespace std;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size < 2) {
        // Not enough data to do anything
        return 0;
    }

    string url(data + 1, data + size);

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Implement different HTTP methods
        switch (data[0] % 4) {
            case 0:
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
                break;
            case 1:
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
                break;
            case 2:
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
                break;
            case 3:
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
                break;
        }

        // Set random binary data
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data + 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, size - 1);

        // Set random binary data with flags
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return 0;
}
