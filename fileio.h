#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <fstream>

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long ull;

class FileIO
{

public:
    FileIO(const std::string &filepath);
    FileIO(std::string &&filepath);
    ~FileIO();
    void setFilePath(const std::string &_path);
    void setFilePath(std::string &&_path);
    void setPosition(ull position);
    ull getFileSize();
    byte* readBytes(ull length);
    void writeBytes(byte* data, ull length);
    void flush();

protected:

private:
    std::string path;
    ull size;
    ull pos;
    FileIO();
    std::fstream fs;

};

#endif // FILEIO_H
