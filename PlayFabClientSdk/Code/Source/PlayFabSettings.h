#pragma once

#include <PlayFabClientSdk/PlayFabError.h>

namespace PlayFabClientSdk
{
    class PlayFabSettings
    {
    public:
        static PlayFabSettings *playFabSettings; // Global settings for all Apis

        const AZStd::string playFabVersionString;
        const AZStd::string buildIdentifier;

        bool useDevelopmentEnvironment;
        AZStd::string developmentEnvironmentURL;
        AZStd::string productionEnvironmentURL;
        AZStd::string titleId; // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        ErrorCallback globalErrorHandler;
        AZStd::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        AZStd::string advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        bool disableAdvertising;
        const AZStd::string AD_TYPE_IDFA;
        const AZStd::string AD_TYPE_ANDROID_ID;

        PlayFabSettings();

        AZStd::string getURL(const AZStd::string& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://" + titleId + (useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }

    private:
        AZStd::string serverURL; // A cache of the constructed url string
    };
}
