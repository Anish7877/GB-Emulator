#ifndef PPU_HPP
#define PPU_HPP
#include <cstdint>
class PPU{
        public:
        private:
                std::uint16_t lcdc_addr{0xFF40};
                std::uint16_t stat_addr{0xFF41};
                std::uint16_t scx_addr{0xFF42};
                std::uint16_t scy_addr{0xFF43};
                std::uint16_t ly_addr{0xFF44};
                std::uint16_t lyc_addr{0xFF45};
                std::uint16_t bgp_addr{0xFF47};
                std::uint16_t wx_addr{0xFF4A};
                std::uint16_t wy_addr{0xFF4B};
};
#endif
