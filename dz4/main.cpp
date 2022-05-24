#include"httplib.h"
#include<iostream>

int main(int argc, char** argv) {
    int port = 8080;
    if(argc >=2) {
        if(std::sscanf(argv[1],"%d", &port) != 1) {
            return -1;
        }
    }

    std::cerr<< "Listening on port" << port << "..." << std::endl;

    httplib::Server svr;
    svr.set_read_timeout(60);
    svr.Get("/stop",[&](const httplib::Request &,httplib::Response &) {
        svr.stop();
    });
    svr.Get("/index", [&](const httplib::Request &, httplib::Response & resp) {
        resp.body = "Hi";
        resp.status = 200;
    });
    svr.Get("/about", [&](const httplib::Request &, httplib::Response & resp) {
        resp.headers.insert({"Content-Type", "text/html; charset=utf-8"});
        resp.body = R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My site.</title>
</head>
<body>
<h1>My site.<h1><br>
                <i>Iron</i><br>
                ldldld
</body>
</html>
)";
        resp.status = 200;
    });
    svr.listen("0.0.0.0", port);
    return 0; 
}
