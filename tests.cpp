#include <string>
#include "gtest/gtest.h"
#include "base64.h"

using namespace std;

TEST(base64_encode, expectedTrueEncode) {
    string len = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is "
           "a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation "
           "of knowledge, exceeds the short vehemence of any carnal pleasure.";

    const char* expectedEncode = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZ"
        "nJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZG"
        "VsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHR"
        "oZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4";

    ASSERT_STREQ(expectedEncode, base64_encode4(len).c_str());
}

TEST(decodeBase64, expectedTrueDecode) {
    string s = "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2NpbmcgZWxpdCwgc2VkIGRvIGVpdXNtb2"
                  "QgdGVtcG9yIGluY2lkaWR1bnQgdXQgbGFib3JlIGV0IGRvbG9yZSBtYWduYSBhbGlxdWEuIFV0IGVuaW0gYWQgbWluaW0g"
                  "dmVuaWFtLCBxdWlzIG5vc3RydWQgZXhlcmNpdGF0aW9uIHVsbGFtY28gbGFib3JpcyBuaXNpIHV0IGFsaXF1aXAgZXggZW"
                  "EgY29tbW9kbyBjb25zZXF1YXQuIER1aXMgYXV0ZSBpcnVyZSBkb2xvciBpbiByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0"
                  "ZSB2ZWxpdCBlc3NlIGNpbGx1bSBkb2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlhdHVyLiBFeGNlcHRldXIgc2ludCBvY2"
                  "NhZWNhdCBjdXBpZGF0YXQgbm9uIHByb2lkZW50LCBzdW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2VydW50IG1vbGxp"
                  "dCBhbmltIGlkIGVzdCBsYWJvcnVtLg";

    const char* expectedDecodeLen = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor i"
                                     "ncididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostru"
                                     "d exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aut"
                                     "e irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat n"
                                     "ulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui"
                                     " officia deserunt mollit anim id est laborum.";

    ASSERT_STREQ(expectedDecodeLen, decodingBase64(s).c_str());
}

TEST(base64_encode, expectedTrueRusDecode) {
    string len = "Съешь ещё этих мягких французских булок да выпей чаю!";

    const char* expectedDecodeLen = "0KHRitC10YjRjCDQtdGJ0ZEg0Y3RgtC40YUg0LzRj9Cz0LrQuNGFINGE0YDQsNC90YbRg9C30YHQutC4"
                                     "0YUg0LHRg9C70L7QuiDQtNCwINCy0YvQv9C10Lkg0YfQsNGOIQ";

    ASSERT_STREQ(expectedDecodeLen, base64_encode(len).c_str());
}

TEST(base64_decode, expectedTrueRusDecode) {
    string s = "0KHRitC10YjRjCDQtdGJ0ZEg0Y3RgtC40YUg0LzRj9Cz0LrQuNGFINGE0YDQsNC90YbRg9C30YHQutC4"
                  "0YUg0LHRg9C70L7QuiDQtNCwINCy0YvQv9C10Lkg0YfQsNGOIQ";

    const char* expectedDecodeLen = "Съешь ещё этих мягких французских булок да выпей чаю!";

    ASSERT_STREQ(expectedDecodeLen, base64_decode(s).c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
