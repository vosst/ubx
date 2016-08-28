#include <ubx/_8/receiver.h>

int main(int argc, char** argv)
{
    ubx::_8::Receiver::create(boost::filesystem::path(argv[1]))->run();
    return 0;
}
