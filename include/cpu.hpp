#ifndef CPU_HPP
#define CPU_HPP
#include <cstdint>
class CPU {
        public:
                explicit CPU() = default;
                void load_a(std::uint8_t data) { a = data; }
                void load_b(std::uint8_t data) { b = data; }
                void load_c(std::uint8_t data) { c = data; }
                void load_d(std::uint8_t data) { d = data; }
                void load_e(std::uint8_t data) { e = data; }
                void load_h(std::uint8_t data) { h = data; }
                void load_l(std::uint8_t data) { l = data; }
                void load_af(std::uint16_t data) { af = data; af &= 0xFFF0;}
                void load_bc(std::uint16_t data) { bc = data; }
                void load_de(std::uint16_t data) { de = data; }
                void load_hl(std::uint16_t data) { hl = data; }
                void load_pc(std::uint16_t data) { pc = data; }
                void inc_a() { a++; }
                void inc_b() { b++; }
                void inc_c() { c++; }
                void inc_d() { d++; }
                void inc_e() { e++; }
                void inc_h() { h++; }
                void inc_l() { l++; }
                void inc_bc() { bc++; }
                void inc_de() { de++; }
                void inc_hl() { hl++; }
                void inc_pc() { pc++; }
                void inc_sp() { sp++; }
                void clr_a() { a = 0; }
                void clr_b() { b = 0; }
                void clr_c() { c = 0; }
                void clr_d() { d = 0; }
                void clr_e() { e = 0; }
                void clr_h() { h = 0; }
                void clr_l() { l = 0; }
                void clr_af() { af = 0; }
                void clr_bc() { bc = 0; }
                void clr_de() { de = 0; }
                void clr_hl() { hl = 0; }
                void clr_pc() { pc = 0; }
                void clr_sp() { sp = 0; }
                void set_carry() { carry = 1; }
                void set_half_carry() { half_carry = 1; }
                void set_n_flag() { n_flag = 1; }
                void set_zero() { zero = 1; }
                void unset_carry() { carry = 0; }
                void unset_half_carry() { half_carry = 0; }
                void unset_n_flag() { n_flag = 0; }
                void unset_zero() { zero = 0; }
                std::uint8_t get_a() const { return a; }
                std::uint8_t get_b() const { return b; }
                std::uint8_t get_c() const { return c; }
                std::uint8_t get_d() const { return d; }
                std::uint8_t get_e() const { return e; }
                std::uint8_t get_h() const { return h; }
                std::uint8_t get_l() const { return l; }
                std::uint16_t get_af() const { return af; }
                std::uint16_t get_bc() const { return bc; }
                std::uint16_t get_de() const { return de; }
                std::uint16_t get_hl() const { return hl; }
                std::uint16_t get_pc() const { return pc; }
                std::uint16_t get_sp() const { return sp; }
        private :
                union {
                        struct {
                                std::uint8_t unused       : 4; // BITS 4
                                std::uint8_t carry        : 1; // BITS 1
                                std::uint8_t half_carry   : 1; // BITS 1
                                std::uint8_t n_flag       : 1; // BITS 1
                                std::uint8_t zero         : 1; // BITS 1
                                std::uint8_t a;
                        };
                        struct {
                                std::uint8_t f;
                                std::uint8_t a_reg;
                        };
                        std::uint16_t af{};
                };
                union {
                        struct {
                                std::uint8_t c;
                                std::uint8_t b;
                        };
                        std::uint16_t bc{};
                };
                union {
                        struct {
                                std::uint8_t e;
                                std::uint8_t d;
                        };
                        std::uint16_t de{};
                };
                union {
                        struct {
                                std::uint8_t l;
                                std::uint8_t h;
                        };
                        std::uint16_t hl{};
                };
                std::uint16_t pc{};
                std::uint16_t sp{};
};
enum class RegisterCode8_t {
        A   = 0b111,
        B   = 0b000,
        C   = 0b001,
        D   = 0b010,
        E   = 0b011,
        H   = 0b100,
        HLI = 0b110,
        L   = 0b101
};
enum class RegisterCode16_t {
        AF = 0b11,
        BC = 0b00,
        DE = 0b01,
        HL = 0b10
};
#endif
