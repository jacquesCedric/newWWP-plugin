#include <wups.h>
#include <string.h>

#include <nsysnet/socket.h>
#include <vpad/input.h>
#include <utils/logger.h>
#include <coreinit/title.h>
#include <curl/curl.h>
#include <curl/easy.h>

WUPS_PLUGIN_NAME("newWWP");
WUPS_PLUGIN_DESCRIPTION("");
WUPS_PLUGIN_VERSION("v0.1-Mod");
WUPS_PLUGIN_AUTHOR("Jacques");
WUPS_PLUGIN_LICENSE("GPL");


// Allows plugin access the sd card
WUPS_FS_ACCESS()


// Downloading the relevant XML file
bool voteForTitle(uint64_t titleID){
    CURL *curl;
    CURLcode res;

    char postString[] = "type=vote&titleID=";

    char title[50];
    snprintf(title, sizeof(title)-1, "%016llx", titleID);

    strcat(postString, title);

    /* get a curl handle */
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://webhook.site/92827cec-c395-40c4-b257-80cd0f92081f");
        /* Now specify the POST data */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    return false;
}


// We should log what title is started here
ON_APPLICATION_START(args){
    socket_lib_init();
    log_init();

    uint64_t titleID = OSGetTitleID();

    voteForTitle(titleID);

    DEBUG_FUNCTION_LINE("Init of newWWP!\n");
    DEBUG_FUNCTION_LINE("SD mounted? %d\n",args.sd_mounted);
}


// We should download a file and save it here
ON_APPLICATION_ENDING(){
    DEBUG_FUNCTION_LINE("app closing!\n");
}