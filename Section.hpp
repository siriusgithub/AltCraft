#pragma once

#include <vector>
#include <map>
#include "Block.hpp"
#include "Field.hpp"

const int SECTION_WIDTH = 16;
const int SECTION_LENGTH = 16;
const int SECTION_HEIGHT = 16;

class Section {
    std::vector<unsigned short> m_palette;
    byte *m_dataBlocks = nullptr;
    size_t m_dataBlocksLen;
    byte *m_dataLight = nullptr;
    byte *m_dataSkyLight = nullptr;
    byte m_bitsPerBlock = 0;
    std::vector<Block> m_blocks;
public:
    void Parse();

    Section(byte *dataBlocks, size_t dataBlocksLength, byte *dataLight, byte *dataSky, byte bitsPerBlock,
            std::vector<unsigned short> palette);

    Section();

    ~Section();

    Block &GetBlock(PositionI pos);

    Section &operator=(Section other);

    void swap(Section &other);

    Section(const Section &other);

};