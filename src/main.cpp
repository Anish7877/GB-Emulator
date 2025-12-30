#include "../include/cpu.hpp"
#include "../include/bus.hpp"
#include "../include/cartridge.hpp"
#include <iostream>
#include <memory>

int main(void){
        std::shared_ptr<Cartridge> cartridge{std::make_shared<Cartridge>()};
        std::shared_ptr<Bus> bus{std::make_shared<Bus>()};
        std::shared_ptr<CPU> cpu{std::make_shared<CPU>()};
        std::shared_ptr<Joypad> joypad{std::make_shared<Joypad>()};
        cartridge->load("/home/anish/Downloads/gameboy/Super Mario Land (World) (Rev 1).gb");
        std::cout << "Cartridge Title : " << cartridge->get_cartridge_title() << '\n';
        std::cout << "CBG Flag : " << (int)cartridge->get_cgb_flag() << '\n';
        std::cout << "Cartridge Type : " << (int)cartridge->get_cartridge_type() << '\n';
        std::cout << "Rom Size : " << cartridge->get_rom_size() << '\n';
        std::cout << "Checksum : " << (int)cartridge->get_checksum() << '\n';
        bus->insert_cartridge(cartridge);
        bus->connect_joypad(joypad);
        cpu->connect_to_bus(bus);
        while(true){
                cpu->step();
        }
        return 0;
}
