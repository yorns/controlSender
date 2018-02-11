#include <snc/client.h>
#include <iostream>

int main(int argc, char* argv[])
{

    if (argc != 2) {
        std::cerr << "usage "<<argv[0]<<" [ forward | left | right | stop ]\n";
    }
    std::string command = argv[1];
    std::string sendId;

    boost::asio::io_service service;
    snc::Client client("controlSender", service, "127.0.0.1", 12001);

    if (command == "forward")
        sendId = "i";

    if (command == "left")
        sendId = "u";

    if (command == "right")
        sendId = "o";

    if (command == "stop")
        sendId = "k";

    if (!sendId.empty())
        client.send(snc::Client::SendType::cl_send, "steeringContmakerol", sendId);

    service.run_one();

    return 0;
}
