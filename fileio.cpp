#include "fileio.h"

FileIO::FileIO(const std::string &filepath)
{
    fs.open(filepath, std::ios::out | std::ios::in | std::ios::app);
    if(!fs)
    {
        fs.open(filepath, std::ios::out | std::ios::in | std::ios::trunc);
        // !! ?? is it a right method
    }
    std::fstream::sync_with_stdio(0);
    fs.tie(0);
    fs.seekg(0, std::ios::end);
    size = fs.tellg();
    fs.seekg(0, std::ios::beg);
    pos = 0;
}

FileIO::FileIO(std::string &&filepath)
{

}

FileIO::~FileIO()
{
    fs.close();
}

void FileIO::setFilePath(const std::string &_path)
{

}

void FileIO::setFilePath(std::string &&_path)
{

}

void FileIO::setPosition(ull position)
{
   pos = position;
}

byte *FileIO::readBytes(ull length)
{
    fs.seekg(pos, std::ios::beg);

    byte* res = new byte[length];
    fs.read((char*)res, length);

    pos += length;

    return res;
}

void FileIO::writeBytes(byte *data, ull length)
{
    fs.seekp(pos, std::ios::beg);

    fs.write((char*)data, length);

    pos += length;
}

void FileIO::flush()
{
    fs.flush();
}

FileIO::FileIO()
{

}
