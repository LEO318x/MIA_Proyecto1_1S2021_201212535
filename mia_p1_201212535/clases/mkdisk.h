#ifndef MKDISK_H
#define MKDISK_H
#include <string>

class mkdisk
{
public:
    mkdisk();
    void test(int tam, const std::string& ruta, const std::string& mkid1 = "", const std::string& mkid2 = "");
};

#endif // MKDISK_H
