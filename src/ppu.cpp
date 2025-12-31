#include "../include/ppu.hpp"
#include "../include/bus.hpp"

void PPU::connect_to_bus(const std::shared_ptr<Bus>& bus){
        this->bus = bus;
}

void PPU::update_stat_mode(std::uint8_t mode){
        current_mode = mode;
        std::uint8_t stat{bus->read(stat_addr)};

        stat &= 0xFC;

        stat |= (mode & 0x03);

        bus->write(stat_addr, stat);

        // stat interrupts
}

void PPU::compare_ly_lyc(){
        std::uint8_t ly{bus->read(ly_addr)};
        std::uint8_t lyc{bus->read(lyc_addr)};
        std::uint8_t stat{bus->read(stat_addr)};

        if(lyc == ly){
                stat |= 0x04;

                if(stat & 0x04){
                        bus->request_interrupt(1);
                }
        }
        else{
                stat &= ~(0x04);
        }
        bus->write(stat_addr, stat);
}

void PPU::tick(unsigned int cycles){
        std::uint8_t lcdc{bus->read(lcdc_addr)};

        if(!(lcdc & 0x80)){
                internal_cycles = 0;
                current_mode = 0;
                bus->write(ly_addr, 0);

                std::uint8_t stat{bus->read(stat_addr)};
                stat &= 0xFC;
                bus->write(stat_addr, stat);
                return;
        }

        internal_cycles += cycles;

        switch (current_mode){
                case 2:
                        if(internal_cycles >= 80){
                                internal_cycles -= 80;
                                update_stat_mode(3);
                        }
                        break;
                case 3:
                        if(internal_cycles >= 172){
                                internal_cycles -= 172;
                                update_stat_mode(0);

                                // render scan line
                        }
                        break;
                case 0:
                        if(internal_cycles >= 204){
                                internal_cycles -= 204;
                                update_stat_mode(1);

                                std::uint8_t current_ly{bus->read(ly_addr)};
                                bus->write(ly_addr, current_ly+1);

                                compare_ly_lyc();

                                if(bus->read(ly_addr) == 144){
                                        update_stat_mode(1);
                                        bus->request_interrupt(0);
                                }
                                else{
                                        update_stat_mode(2);
                                }
                        }
                        break;
                case 1:
                        if(internal_cycles >= 456){
                                internal_cycles -= 456;

                                std::uint8_t current_ly{bus->read(ly_addr)};

                                if(current_ly < 153){
                                        bus->write(ly_addr, current_ly+1);
                                        compare_ly_lyc();
                                }
                                else{
                                        bus->write(ly_addr, 0);
                                        compare_ly_lyc();
                                        update_stat_mode(2);
                                }
                        }
                        break;
        }
}

std::uint8_t PPU::get_lcdc() const{
        return bus->read(lcdc_addr);
}

std::uint8_t PPU::get_stat() const{
        return bus->read(stat_addr);
}

std::uint8_t PPU::get_scx() const{
        return bus->read(scx_addr);
}

std::uint8_t PPU::get_scy() const{
        return bus->read(scy_addr);
}

std::uint8_t PPU::get_ly() const{
        return bus->read(ly_addr);
}

std::uint8_t PPU::get_lyc() const{
        return bus->read(lyc_addr);
}

std::uint8_t PPU::get_bgp() const{
        return bus->read(bgp_addr);
}

std::uint8_t PPU::get_wx() const{
        return bus->read(wx_addr);
}

std::uint8_t PPU::get_wy() const{
        return bus->read(wy_addr);
}
