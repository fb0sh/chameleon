#ifndef CHAMELEON_HTTPTOOL
#define CHAMELEON_HTTPTOOL
#include <map>
#include <string>
#include <chrono>
#include <time.h>
using std::map;
using std::string;

const map<string, string> HttpCode = { {"100", "Continue"}, {"101", "Switching Protocols"}, {"102", "Processing"}, {"103", "Early Hints"}, {"200", "OK"}, {"201", "Created"}, {"202", "Accepted"}, {"203", "Non-Authoritative Information"}, {"204", "No Content"}, {"205", "Reset Content"}, {"206", "Partial Content"}, {"207", "Multi-Status"}, {"208", "Already Reported"}, {"226", "IM Used"}, {"300", "Multiple Choices"}, {"301", "Moved Permanently"}, {"302", "Found"}, {"303", "See Other"}, {"304", "Not Modified"}, {"305", "Use Proxy"}, {"307", "Temporary Redirect"}, {"308", "Permanent Redirect"}, {"400", "Bad Request"}, {"401", "Unauthorized"}, {"402", "Payment Required"}, {"403", "Forbidden"}, {"404", "Not Found"}, {"405", "Method Not Allowed"}, {"406", "Not Acceptable"}, {"407", "Proxy Authentication Required"}, {"408", "Request Timeout"}, {"409", "Conflict"}, {"410", "Gone"}, {"411", "Length Required"}, {"412", "Precondition Failed"}, {"413", "Request Entity Too Large"}, {"414", "Request-URI Too Long"}, {"415", "Unsupported Media Type"}, {"416", "Requested Range Not Satisfiable"}, {"417", "Expectation Failed"}, {"418", "I'm a Teapot"}, {"421", "Misdirected Request"}, {"422", "Unprocessable Entity"}, {"423", "Locked"}, {"424", "Failed Dependency"}, {"425", "Too Early"}, {"426", "Upgrade Required"}, {"428", "Precondition Required"}, {"429", "Too Many Requests"}, {"431", "Request Header Fields Too Large"}, {"451", "Unavailable For Legal Reasons"}, {"500", "Internal Server Error"}, {"501", "Not Implemented"}, {"502", "Bad Gateway"}, {"503", "Service Unavailable"}, {"504", "Gateway Timeout"}, {"505", "HTTP Version Not Supported"}, {"506", "Variant Also Negotiates"}, {"507", "Insufficient Storage"}, {"508", "Loop Detected"}, {"510", "Not Extended"}, {"511", "Network Authentication Required"} };
const map<string, string> MimeType = { {"aac",  "audio/aac"}, {"abw",  "application/x-abiword"}, {"arc",  "application/x-freearc"}, {"avi",  "video/x-msvideo"}, {"azw",  "application/vnd.amazon.ebook"}, {"bin",  "application/octet-stream"}, {"bmp",  "image/bmp"}, {"bz",  "application/x-bzip"}, {"bz2",  "application/x-bzip2"}, {"csh",  "application/x-csh"}, {"css",  "text/css"}, {"csv",  "text/csv"}, {"doc",  "application/msword"}, {"docx",  "application/vnd.openxmlformats-officedocument.wordprocessingml.document"}, {"eot",  "application/vnd.ms-fontobject"}, {"epub",  "application/epub+zip"}, {"gif",  "image/gif"}, {"htm",  "text/html"}, {"html",  "text/html"}, {"ico",  "image/vnd.microsoft.icon"}, {"ics",  "text/calendar"}, {"jar",  "application/java-archive"}, {"jpeg",  "image/jpeg"}, {"jpg",  "image/jpeg"}, {"js",  "text/javascript"}, {"json",  "application/json"}, {"jsonld",  "application/ld+json"}, {"mid",  "audio/midi"}, {"midi",  "audio/x-midi"}, {"mjs",  "text/javascript"}, {"mp3",  "audio/mpeg"}, {"mpeg",  "video/mpeg"}, {"mpkg",  "application/vnd.apple.installer+xml"}, {"odp",  "application/vnd.oasis.opendocument.presentation"}, {"ods",  "application/vnd.oasis.opendocument.spreadsheet"}, {"odt",  "application/vnd.oasis.opendocument.text"}, {"oga",  "audio/ogg"}, {"ogv",  "video/ogg"}, {"ogx",  "application/ogg"}, {"otf",  "font/otf"}, {"png",  "image/png"}, {"pdf",  "application/pdf"}, {"ppt",  "application/vnd.ms-powerpoint"}, {"pptx",  "application/vnd.openxmlformats-officedocument.presentationml.presentation"}, {"rar",  "application/x-rar-compressed"}, {"rtf",  "application/rtf"}, {"sh",  "application/x-sh"}, {"svg",  "image/svg+xml"}, {"swf",  "application/x-shockwave-flash"}, {"tar",  "application/x-tar"}, {"tif",  "image/tiff"}, {"tiff",  "image/tiff"}, {"ttf",  "font/ttf"}, {"txt",  "text/plain"}, {"vsd",  "application/vnd.visio"}, {"wav",  "audio/wav"}, {"weba",  "audio/webm"}, {"webm",  "video/webm"}, {"webp",  "image/webp"}, {"woff",  "font/woff"}, {"woff2",  "font/woff2"}, {"xhtml",  "application/xhtml+xml"}, {"xls",  "application/vnd.ms-excel"}, {"xlsx",  "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"}, {"xml",  "text/xml"}, {"xul",  "application/vnd.mozilla.xul+xml"}, {"zip",  "application/zip"}, {"3gp",  "audio/video "}, {"3g2",  "audio/video "}, {"7z",  "application/x-7z-compressed"} };

string GetHttpCode(string status_code) {
    if(HttpCode.count(status_code)) return HttpCode.find(status_code)->second;
    else return "No Status";
}

string GetMimeType(string suffix) {
    if(MimeType.count(suffix)) return MimeType.find(suffix)->second;
    else return MimeType.find("html")->second;
}
string gmt_time() {
    time_t now = time(0);
    tm *gmt = gmtime(&now);
    const char *fmt = "%a, %d %b %Y %H:%M:%S GMT";
    char tstr[30];
    strftime(tstr, sizeof(tstr), fmt, gmt);
    return tstr;
}
#endif