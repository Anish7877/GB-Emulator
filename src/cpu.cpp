#include "../include/cpu.hpp"
#include "../include/bus.hpp"
#include <iostream>
#include <utility>

CPU::CPU(){
        lookup_table.resize(256);
        cb_lookup_table.resize(256);
        lookup_table = {
                {std::string("nop"),[this](){this->nop();}},
                {std::string("load_bc"),[this](){this->load_bc();}},
                {std::string("load_addr_bc_a"),[this](){this->load_addr_bc_a();}},
                {std::string("inc_bc"),[this](){this->inc_bc();}},
                {std::string("inc_b"),[this](){this->inc_b();}},
                {std::string("dec_b"),[this](){this->dec_b();}},
                {std::string("load_b"),[this](){this->load_b();}},
                {std::string("rlca"),[this](){this->rlca();}},
                {std::string("load_addr_sp"),[this](){this->load_addr_sp();}},
                {std::string("add_hl_bc"),[this](){this->add_hl_bc();}},
                {std::string("load_a_addr_bc"),[this](){this->load_a_addr_bc();}},
                {std::string("dec_bc"),[this](){this->dec_bc();}},
                {std::string("inc_c"),[this](){this->inc_c();}},
                {std::string("dec_c"),[this](){this->dec_c();}},
                {std::string("load_c"),[this](){this->load_c();}},
                {std::string("rrca"),[this](){this->rrca();}},
                {std::string("stop"),[this](){this->stop();}},
                {std::string("load_de"),[this](){this->load_de();}},
                {std::string("load_addr_de_a"),[this](){this->load_addr_de_a();}},
                {std::string("inc_de"),[this](){this->inc_de();}},
                {std::string("inc_d"),[this](){this->inc_d();}},
                {std::string("dec_d"),[this](){this->dec_d();}},
                {std::string("load_d"),[this](){this->load_d();}},
                {std::string("rla"),[this](){this->rla();}},
                {std::string("jr"),[this](){this->jr();}},
                {std::string("add_hl_de"),[this](){this->add_hl_de();}},
                {std::string("load_a_addr_de"),[this](){this->load_a_addr_de();}},
                {std::string("dec_de"),[this](){this->dec_de();}},
                {std::string("inc_e"),[this](){this->inc_e();}},
                {std::string("dec_e"),[this](){this->dec_e();}},
                {std::string("load_e"),[this](){this->load_e();}},
                {std::string("rra"),[this](){this->rra();}},
                {std::string("jr_nz"),[this](){this->jr_nz();}},
                {std::string("load_hl"),[this](){this->load_hl();}},
                {std::string("load_addr_hl_plus_a"),[this](){this->load_addr_hl_plus_a();}},
                {std::string("inc_hl"),[this](){this->inc_hl();}},
                {std::string("inc_h"),[this](){this->inc_h();}},
                {std::string("dec_h"),[this](){this->dec_h();}},
                {std::string("load_h"),[this](){this->load_h();}},
                {std::string("daa"),[this](){this->daa();}},
                {std::string("jr_z"),[this](){this->jr_z();}},
                {std::string("add_hl_hl"),[this](){this->add_hl_hl();}},
                {std::string("load_a_addr_hl_plus"),[this](){this->load_a_addr_hl_plus();}},
                {std::string("dec_hl"),[this](){this->dec_hl();}},
                {std::string("inc_l"),[this](){this->inc_l();}},
                {std::string("dec_l"),[this](){this->dec_l();}},
                {std::string("load_l"),[this](){this->load_l();}},
                {std::string("cpl"),[this](){this->cpl();}},
                {std::string("jr_nc"),[this](){this->jr_nc();}},
                {std::string("load_sp"),[this](){this->load_sp();}},
                {std::string("load_addr_hl_minus_a"),[this](){this->load_addr_hl_minus_a();}},
                {std::string("inc_sp"),[this](){this->inc_sp();}},
                {std::string("inc_addr_hl"),[this](){this->inc_addr_hl();}},
                {std::string("dec_addr_hl"),[this](){this->dec_addr_hl();}},
                {std::string("load_addr_hl"),[this](){this->load_addr_hl();}},
                {std::string("scf"),[this](){this->scf();}},
                {std::string("jr_c"),[this](){this->jr_c();}},
                {std::string("add_hl_sp"),[this](){this->add_hl_sp();}},
                {std::string("load_a_addr_hl_minus"),[this](){this->load_a_addr_hl_minus();}},
                {std::string("dec_sp"),[this](){this->dec_sp();}},
                {std::string("inc_a"),[this](){this->inc_a();}},
                {std::string("dec_a"),[this](){this->dec_a();}},
                {std::string("load_a"),[this](){this->load_a();}},
                {std::string("ccf"),[this](){this->ccf();}},
                {std::string("load_b_b"),[this](){this->load_b_b();}},
                {std::string("load_b_c"),[this](){this->load_b_c();}},
                {std::string("load_b_d"),[this](){this->load_b_d();}},
                {std::string("load_b_e"),[this](){this->load_b_e();}},
                {std::string("load_b_h"),[this](){this->load_b_h();}},
                {std::string("load_b_l"),[this](){this->load_b_l();}},
                {std::string("load_b_addr_hl"),[this](){this->load_b_addr_hl();}},
                {std::string("load_b_a"),[this](){this->load_b_a();}},
                {std::string("load_c_b"),[this](){this->load_c_b();}},
                {std::string("load_c_c"),[this](){this->load_c_c();}},
                {std::string("load_c_d"),[this](){this->load_c_d();}},
                {std::string("load_c_e"),[this](){this->load_c_e();}},
                {std::string("load_c_h"),[this](){this->load_c_h();}},
                {std::string("load_c_l"),[this](){this->load_c_l();}},
                {std::string("load_c_addr_hl"),[this](){this->load_c_addr_hl();}},
                {std::string("load_c_a"),[this](){this->load_c_a();}},
                {std::string("load_d_b"),[this](){this->load_d_b();}},
                {std::string("load_d_c"),[this](){this->load_d_c();}},
                {std::string("load_d_d"),[this](){this->load_d_d();}},
                {std::string("load_d_e"),[this](){this->load_d_e();}},
                {std::string("load_d_h"),[this](){this->load_d_h();}},
                {std::string("load_d_l"),[this](){this->load_d_l();}},
                {std::string("load_d_addr_hl"),[this](){this->load_d_addr_hl();}},
                {std::string("load_d_a"),[this](){this->load_d_a();}},
                {std::string("load_e_b"),[this](){this->load_e_b();}},
                {std::string("load_e_c"),[this](){this->load_e_c();}},
                {std::string("load_e_d"),[this](){this->load_e_d();}},
                {std::string("load_e_e"),[this](){this->load_e_e();}},
                {std::string("load_e_h"),[this](){this->load_e_h();}},
                {std::string("load_e_l"),[this](){this->load_e_l();}},
                {std::string("load_e_addr_hl"),[this](){this->load_e_addr_hl();}},
                {std::string("load_e_a"),[this](){this->load_e_a();}},
                {std::string("load_h_b"),[this](){this->load_h_b();}},
                {std::string("load_h_c"),[this](){this->load_h_c();}},
                {std::string("load_h_d"),[this](){this->load_h_d();}},
                {std::string("load_h_e"),[this](){this->load_h_e();}},
                {std::string("load_h_h"),[this](){this->load_h_h();}},
                {std::string("load_h_l"),[this](){this->load_h_l();}},
                {std::string("load_h_addr_hl"),[this](){this->load_h_addr_hl();}},
                {std::string("load_h_a"),[this](){this->load_h_a();}},
                {std::string("load_l_b"),[this](){this->load_l_b();}},
                {std::string("load_l_c"),[this](){this->load_l_c();}},
                {std::string("load_l_d"),[this](){this->load_l_d();}},
                {std::string("load_l_e"),[this](){this->load_l_e();}},
                {std::string("load_l_h"),[this](){this->load_l_h();}},
                {std::string("load_l_l"),[this](){this->load_l_l();}},
                {std::string("load_l_addr_hl"),[this](){this->load_l_addr_hl();}},
                {std::string("load_l_a"),[this](){this->load_l_a();}},
                {std::string("load_addr_hl_b"),[this](){this->load_addr_hl_b();}},
                {std::string("load_addr_hl_c"),[this](){this->load_addr_hl_c();}},
                {std::string("load_addr_hl_d"),[this](){this->load_addr_hl_d();}},
                {std::string("load_addr_hl_e"),[this](){this->load_addr_hl_e();}},
                {std::string("load_addr_hl_h"),[this](){this->load_addr_hl_h();}},
                {std::string("load_addr_hl_l"),[this](){this->load_addr_hl_l();}},
                {std::string("halt"),[this](){this->halt();}},
                {std::string("load_addr_hl_a"),[this](){this->load_addr_hl_a();}},
                {std::string("load_a_b"),[this](){this->load_a_b();}},
                {std::string("load_a_c"),[this](){this->load_a_c();}},
                {std::string("load_a_d"),[this](){this->load_a_d();}},
                {std::string("load_a_e"),[this](){this->load_a_e();}},
                {std::string("load_a_h"),[this](){this->load_a_h();}},
                {std::string("load_a_l"),[this](){this->load_a_l();}},
                {std::string("load_a_addr_hl"),[this](){this->load_a_addr_hl();}},
                {std::string("load_a_a"),[this](){this->load_a_a();}},
                {std::string("add_a_b"),[this](){this->add_a_b();}},
                {std::string("add_a_c"),[this](){this->add_a_c();}},
                {std::string("add_a_d"),[this](){this->add_a_d();}},
                {std::string("add_a_e"),[this](){this->add_a_e();}},
                {std::string("add_a_h"),[this](){this->add_a_h();}},
                {std::string("add_a_l"),[this](){this->add_a_l();}},
                {std::string("add_a_addr_hl"),[this](){this->add_a_addr_hl();}},
                {std::string("add_a_a"),[this](){this->add_a_a();}},
                {std::string("adc_a_b"),[this](){this->adc_a_b();}},
                {std::string("adc_a_c"),[this](){this->adc_a_c();}},
                {std::string("adc_a_d"),[this](){this->adc_a_d();}},
                {std::string("adc_a_e"),[this](){this->adc_a_e();}},
                {std::string("adc_a_h"),[this](){this->adc_a_h();}},
                {std::string("adc_a_l"),[this](){this->adc_a_l();}},
                {std::string("adc_a_addr_hl"),[this](){this->adc_a_addr_hl();}},
                {std::string("adc_a_a"),[this](){this->adc_a_a();}},
                {std::string("sub_a_b"),[this](){this->sub_a_b();}},
                {std::string("sub_a_c"),[this](){this->sub_a_c();}},
                {std::string("sub_a_d"),[this](){this->sub_a_d();}},
                {std::string("sub_a_e"),[this](){this->sub_a_e();}},
                {std::string("sub_a_h"),[this](){this->sub_a_h();}},
                {std::string("sub_a_l"),[this](){this->sub_a_l();}},
                {std::string("sub_a_addr_hl"),[this](){this->sub_a_addr_hl();}},
                {std::string("sub_a_a"),[this](){this->sub_a_a();}},
                {std::string("sbc_a_b"),[this](){this->sbc_a_b();}},
                {std::string("sbc_a_c"),[this](){this->sbc_a_c();}},
                {std::string("sbc_a_d"),[this](){this->sbc_a_d();}},
                {std::string("sbc_a_e"),[this](){this->sbc_a_e();}},
                {std::string("sbc_a_h"),[this](){this->sbc_a_h();}},
                {std::string("sbc_a_l"),[this](){this->sbc_a_l();}},
                {std::string("sbc_a_addr_hl"),[this](){this->sbc_a_addr_hl();}},
                {std::string("sbc_a_a"),[this](){this->sbc_a_a();}},
                {std::string("and_a_b"),[this](){this->and_a_b();}},
                {std::string("and_a_c"),[this](){this->and_a_c();}},
                {std::string("and_a_d"),[this](){this->and_a_d();}},
                {std::string("and_a_e"),[this](){this->and_a_e();}},
                {std::string("and_a_h"),[this](){this->and_a_h();}},
                {std::string("and_a_l"),[this](){this->and_a_l();}},
                {std::string("and_a_addr_hl"),[this](){this->and_a_addr_hl();}},
                {std::string("and_a_a"),[this](){this->and_a_a();}},
                {std::string("xor_a_b"),[this](){this->xor_a_b();}},
                {std::string("xor_a_c"),[this](){this->xor_a_c();}},
                {std::string("xor_a_d"),[this](){this->xor_a_d();}},
                {std::string("xor_a_e"),[this](){this->xor_a_e();}},
                {std::string("xor_a_h"),[this](){this->xor_a_h();}},
                {std::string("xor_a_l"),[this](){this->xor_a_l();}},
                {std::string("xor_a_addr_hl"),[this](){this->xor_a_addr_hl();}},
                {std::string("xor_a_a"),[this](){this->xor_a_a();}},
                {std::string("or_a_b"),[this](){this->or_a_b();}},
                {std::string("or_a_c"),[this](){this->or_a_c();}},
                {std::string("or_a_d"),[this](){this->or_a_d();}},
                {std::string("or_a_e"),[this](){this->or_a_e();}},
                {std::string("or_a_h"),[this](){this->or_a_h();}},
                {std::string("or_a_l"),[this](){this->or_a_l();}},
                {std::string("or_a_addr_hl"),[this](){this->or_a_addr_hl();}},
                {std::string("or_a_a"),[this](){this->or_a_a();}},
                {std::string("cp_a_b"),[this](){this->cp_a_b();}},
                {std::string("cp_a_c"),[this](){this->cp_a_c();}},
                {std::string("cp_a_d"),[this](){this->cp_a_d();}},
                {std::string("cp_a_e"),[this](){this->cp_a_e();}},
                {std::string("cp_a_h"),[this](){this->cp_a_h();}},
                {std::string("cp_a_l"),[this](){this->cp_a_l();}},
                {std::string("cp_a_addr_hl"),[this](){this->cp_a_addr_hl();}},
                {std::string("cp_a_a"),[this](){this->cp_a_a();}},
                {std::string("ret_nz"),[this](){this->ret_nz();}},
                {std::string("pop_bc"),[this](){this->pop_bc();}},
                {std::string("jp_nz"),[this](){this->jp_nz();}},
                {std::string("jp"),[this](){this->jp();}},
                {std::string("call_nz"),[this](){this->call_nz();}},
                {std::string("push_bc"),[this](){this->push_bc();}},
                {std::string("add_a"),[this](){this->add_a();}},
                {std::string("rst_00h"),[this](){this->rst_00h();}},
                {std::string("ret_z"),[this](){this->ret_z();}},
                {std::string("ret"),[this](){this->ret();}},
                {std::string("jp_z"),[this](){this->jp_z();}},
                {std::string("prefix"),[this](){this->prefix();}},
                {std::string("call_z"),[this](){this->call_z();}},
                {std::string("call"),[this](){this->call();}},
                {std::string("adc_a"),[this](){this->adc_a();}},
                {std::string("rst_08h"),[this](){this->rst_08h();}},
                {std::string("ret_nc"),[this](){this->ret_nc();}},
                {std::string("pop_de"),[this](){this->pop_de();}},
                {std::string("jp_nc"),[this](){this->jp_nc();}},
                {std::string(""),[this](){return;}},
                {std::string("call_nc"),[this](){this->call_nc();}},
                {std::string("push_de"),[this](){this->push_de();}},
                {std::string("sub_a"),[this](){this->sub_a();}},
                {std::string("rst_10h"),[this](){this->rst_10h();}},
                {std::string("ret_c"),[this](){this->ret_c();}},
                {std::string("reti"),[this](){this->reti();}},
                {std::string("jp_c"),[this](){this->jp_c();}},
                {std::string(""),[this](){return;}},
                {std::string("call_c"),[this](){this->call_c();}},
                {std::string(""),[this](){return;}},
                {std::string("sbc_a"),[this](){this->sbc_a();}},
                {std::string("rst_18h"),[this](){this->rst_18h();}},
                {std::string("ldh_addr_a"),[this](){this->ldh_addr_a();}},
                {std::string("pop_hl"),[this](){this->pop_hl();}},
                {std::string("ldh_addr_c_a"),[this](){this->ldh_addr_c_a();}},
                {std::string(""),[this](){return;}},
                {std::string(""),[this](){return;}},
                {std::string("push_hl"),[this](){this->push_hl();}},
                {std::string("and_a"),[this](){this->and_a();}},
                {std::string("rst_20h"),[this](){this->rst_20h();}},
                {std::string("add_sp"),[this](){this->add_sp();}},
                {std::string("jp_hl"),[this](){this->jp_hl();}},
                {std::string("load_addr_a"),[this](){this->load_addr_a();}},
                {std::string(""),[this](){return;}},
                {std::string(""),[this](){return;}},
                {std::string(""),[this](){return;}},
                {std::string("xor_a"),[this](){this->xor_a();}},
                {std::string("rst_28h"),[this](){this->rst_28h();}},
                {std::string("ldh_a_addr"),[this](){this->ldh_a_addr();}},
                {std::string(""),[this](){return;}},
                {std::string("pop_af"),[this](){this->pop_af();}},
                {std::string("ldh_a_addr_c"),[this](){this->ldh_a_addr_c();}},
                {std::string("di"),[this](){this->di();}},
                {std::string("push_af"),[this](){this->push_af();}},
                {std::string("or_a"),[this](){this->or_a();}},
                {std::string("rst_30h"),[this](){this->rst_30h();}},
                {std::string("load_hl_sp_add"),[this](){this->load_hl_sp_add();}},
                {std::string("load_sp_hl"),[this](){this->load_sp_hl();}},
                {std::string("load_a_addr"),[this](){this->load_a_addr();}},
                {std::string("ei"),[this](){this->ei();}},
                {std::string(""),[this](){return;}},
                {std::string(""),[this](){return;}},
                {std::string("cp_a"),[this](){this->cp_a();}},
                {std::string("rst_38h"),[this](){this->rst_38h();}}
        };
        cb_lookup_table = {
                {std::string("cb_rlc_b"),[this](){this->cb_rlc_b();}},
                {std::string("cb_rlc_c"),[this](){this->cb_rlc_c();}},
                {std::string("cb_rlc_d"),[this](){this->cb_rlc_d();}},
                {std::string("cb_rlc_e"),[this](){this->cb_rlc_e();}},
                {std::string("cb_rlc_h"),[this](){this->cb_rlc_h();}},
                {std::string("cb_rlc_l"),[this](){this->cb_rlc_l();}},
                {std::string("cb_rlc_addr_hl"),[this](){this->cb_rlc_addr_hl();}},
                {std::string("cb_rlc_a"),[this](){this->cb_rlc_a();}},
                {std::string("cb_rrc_b"),[this](){this->cb_rrc_b();}},
                {std::string("cb_rrc_c"),[this](){this->cb_rrc_c();}},
                {std::string("cb_rrc_d"),[this](){this->cb_rrc_d();}},
                {std::string("cb_rrc_e"),[this](){this->cb_rrc_e();}},
                {std::string("cb_rrc_h"),[this](){this->cb_rrc_h();}},
                {std::string("cb_rrc_l"),[this](){this->cb_rrc_l();}},
                {std::string("cb_rrc_addr_hl"),[this](){this->cb_rrc_addr_hl();}},
                {std::string("cb_rrc_a"),[this](){this->cb_rrc_a();}},
                {std::string("cb_rl_b"),[this](){this->cb_rl_b();}},
                {std::string("cb_rl_c"),[this](){this->cb_rl_c();}},
                {std::string("cb_rl_d"),[this](){this->cb_rl_d();}},
                {std::string("cb_rl_e"),[this](){this->cb_rl_e();}},
                {std::string("cb_rl_h"),[this](){this->cb_rl_h();}},
                {std::string("cb_rl_l"),[this](){this->cb_rl_l();}},
                {std::string("cb_rl_addr_hl"),[this](){this->cb_rl_addr_hl();}},
                {std::string("cb_rl_a"),[this](){this->cb_rl_a();}},
                {std::string("cb_rr_b"),[this](){this->cb_rr_b();}},
                {std::string("cb_rr_c"),[this](){this->cb_rr_c();}},
                {std::string("cb_rr_d"),[this](){this->cb_rr_d();}},
                {std::string("cb_rr_e"),[this](){this->cb_rr_e();}},
                {std::string("cb_rr_h"),[this](){this->cb_rr_h();}},
                {std::string("cb_rr_l"),[this](){this->cb_rr_l();}},
                {std::string("cb_rr_addr_hl"),[this](){this->cb_rr_addr_hl();}},
                {std::string("cb_rr_a"),[this](){this->cb_rr_a();}},
                {std::string("cb_sla_b"),[this](){this->cb_sla_b();}},
                {std::string("cb_sla_c"),[this](){this->cb_sla_c();}},
                {std::string("cb_sla_d"),[this](){this->cb_sla_d();}},
                {std::string("cb_sla_e"),[this](){this->cb_sla_e();}},
                {std::string("cb_sla_h"),[this](){this->cb_sla_h();}},
                {std::string("cb_sla_l"),[this](){this->cb_sla_l();}},
                {std::string("cb_sla_addr_hl"),[this](){this->cb_sla_addr_hl();}},
                {std::string("cb_sla_a"),[this](){this->cb_sla_a();}},
                {std::string("cb_sra_b"),[this](){this->cb_sra_b();}},
                {std::string("cb_sra_c"),[this](){this->cb_sra_c();}},
                {std::string("cb_sra_d"),[this](){this->cb_sra_d();}},
                {std::string("cb_sra_e"),[this](){this->cb_sra_e();}},
                {std::string("cb_sra_h"),[this](){this->cb_sra_h();}},
                {std::string("cb_sra_l"),[this](){this->cb_sra_l();}},
                {std::string("cb_sra_addr_hl"),[this](){this->cb_sra_addr_hl();}},
                {std::string("cb_sra_a"),[this](){this->cb_sra_a();}},
                {std::string("cb_swap_b"),[this](){this->cb_swap_b();}},
                {std::string("cb_swap_c"),[this](){this->cb_swap_c();}},
                {std::string("cb_swap_d"),[this](){this->cb_swap_d();}},
                {std::string("cb_swap_e"),[this](){this->cb_swap_e();}},
                {std::string("cb_swap_h"),[this](){this->cb_swap_h();}},
                {std::string("cb_swap_l"),[this](){this->cb_swap_l();}},
                {std::string("cb_swap_addr_hl"),[this](){this->cb_swap_addr_hl();}},
                {std::string("cb_swap_a"),[this](){this->cb_swap_a();}},
                {std::string("cb_srl_b"),[this](){this->cb_srl_b();}},
                {std::string("cb_srl_c"),[this](){this->cb_srl_c();}},
                {std::string("cb_srl_d"),[this](){this->cb_srl_d();}},
                {std::string("cb_srl_e"),[this](){this->cb_srl_e();}},
                {std::string("cb_srl_h"),[this](){this->cb_srl_h();}},
                {std::string("cb_srl_l"),[this](){this->cb_srl_l();}},
                {std::string("cb_srl_addr_hl"),[this](){this->cb_srl_addr_hl();}},
                {std::string("cb_srl_a"),[this](){this->cb_srl_a();}},
                {std::string("cb_bit_0_b"),[this](){this->cb_bit_0_b();}},
                {std::string("cb_bit_0_c"),[this](){this->cb_bit_0_c();}},
                {std::string("cb_bit_0_d"),[this](){this->cb_bit_0_d();}},
                {std::string("cb_bit_0_e"),[this](){this->cb_bit_0_e();}},
                {std::string("cb_bit_0_h"),[this](){this->cb_bit_0_h();}},
                {std::string("cb_bit_0_l"),[this](){this->cb_bit_0_l();}},
                {std::string("cb_bit_0_addr_hl"),[this](){this->cb_bit_0_addr_hl();}},
                {std::string("cb_bit_0_a"),[this](){this->cb_bit_0_a();}},
                {std::string("cb_bit_1_b"),[this](){this->cb_bit_1_b();}},
                {std::string("cb_bit_1_c"),[this](){this->cb_bit_1_c();}},
                {std::string("cb_bit_1_d"),[this](){this->cb_bit_1_d();}},
                {std::string("cb_bit_1_e"),[this](){this->cb_bit_1_e();}},
                {std::string("cb_bit_1_h"),[this](){this->cb_bit_1_h();}},
                {std::string("cb_bit_1_l"),[this](){this->cb_bit_1_l();}},
                {std::string("cb_bit_1_addr_hl"),[this](){this->cb_bit_1_addr_hl();}},
                {std::string("cb_bit_1_a"),[this](){this->cb_bit_1_a();}},
                {std::string("cb_bit_2_b"),[this](){this->cb_bit_2_b();}},
                {std::string("cb_bit_2_c"),[this](){this->cb_bit_2_c();}},
                {std::string("cb_bit_2_d"),[this](){this->cb_bit_2_d();}},
                {std::string("cb_bit_2_e"),[this](){this->cb_bit_2_e();}},
                {std::string("cb_bit_2_h"),[this](){this->cb_bit_2_h();}},
                {std::string("cb_bit_2_l"),[this](){this->cb_bit_2_l();}},
                {std::string("cb_bit_2_addr_hl"),[this](){this->cb_bit_2_addr_hl();}},
                {std::string("cb_bit_2_a"),[this](){this->cb_bit_2_a();}},
                {std::string("cb_bit_3_b"),[this](){this->cb_bit_3_b();}},
                {std::string("cb_bit_3_c"),[this](){this->cb_bit_3_c();}},
                {std::string("cb_bit_3_d"),[this](){this->cb_bit_3_d();}},
                {std::string("cb_bit_3_e"),[this](){this->cb_bit_3_e();}},
                {std::string("cb_bit_3_h"),[this](){this->cb_bit_3_h();}},
                {std::string("cb_bit_3_l"),[this](){this->cb_bit_3_l();}},
                {std::string("cb_bit_3_addr_hl"),[this](){this->cb_bit_3_addr_hl();}},
                {std::string("cb_bit_3_a"),[this](){this->cb_bit_3_a();}},
                {std::string("cb_bit_4_b"),[this](){this->cb_bit_4_b();}},
                {std::string("cb_bit_4_c"),[this](){this->cb_bit_4_c();}},
                {std::string("cb_bit_4_d"),[this](){this->cb_bit_4_d();}},
                {std::string("cb_bit_4_e"),[this](){this->cb_bit_4_e();}},
                {std::string("cb_bit_4_h"),[this](){this->cb_bit_4_h();}},
                {std::string("cb_bit_4_l"),[this](){this->cb_bit_4_l();}},
                {std::string("cb_bit_4_addr_hl"),[this](){this->cb_bit_4_addr_hl();}},
                {std::string("cb_bit_4_a"),[this](){this->cb_bit_4_a();}},
                {std::string("cb_bit_5_b"),[this](){this->cb_bit_5_b();}},
                {std::string("cb_bit_5_c"),[this](){this->cb_bit_5_c();}},
                {std::string("cb_bit_5_d"),[this](){this->cb_bit_5_d();}},
                {std::string("cb_bit_5_e"),[this](){this->cb_bit_5_e();}},
                {std::string("cb_bit_5_h"),[this](){this->cb_bit_5_h();}},
                {std::string("cb_bit_5_l"),[this](){this->cb_bit_5_l();}},
                {std::string("cb_bit_5_addr_hl"),[this](){this->cb_bit_5_addr_hl();}},
                {std::string("cb_bit_5_a"),[this](){this->cb_bit_5_a();}},
                {std::string("cb_bit_6_b"),[this](){this->cb_bit_6_b();}},
                {std::string("cb_bit_6_c"),[this](){this->cb_bit_6_c();}},
                {std::string("cb_bit_6_d"),[this](){this->cb_bit_6_d();}},
                {std::string("cb_bit_6_e"),[this](){this->cb_bit_6_e();}},
                {std::string("cb_bit_6_h"),[this](){this->cb_bit_6_h();}},
                {std::string("cb_bit_6_l"),[this](){this->cb_bit_6_l();}},
                {std::string("cb_bit_6_addr_hl"),[this](){this->cb_bit_6_addr_hl();}},
                {std::string("cb_bit_6_a"),[this](){this->cb_bit_6_a();}},
                {std::string("cb_bit_7_b"),[this](){this->cb_bit_7_b();}},
                {std::string("cb_bit_7_c"),[this](){this->cb_bit_7_c();}},
                {std::string("cb_bit_7_d"),[this](){this->cb_bit_7_d();}},
                {std::string("cb_bit_7_e"),[this](){this->cb_bit_7_e();}},
                {std::string("cb_bit_7_h"),[this](){this->cb_bit_7_h();}},
                {std::string("cb_bit_7_l"),[this](){this->cb_bit_7_l();}},
                {std::string("cb_bit_7_addr_hl"),[this](){this->cb_bit_7_addr_hl();}},
                {std::string("cb_bit_7_a"),[this](){this->cb_bit_7_a();}},
                {std::string("cb_res_0_b"),[this](){this->cb_res_0_b();}},
                {std::string("cb_res_0_c"),[this](){this->cb_res_0_c();}},
                {std::string("cb_res_0_d"),[this](){this->cb_res_0_d();}},
                {std::string("cb_res_0_e"),[this](){this->cb_res_0_e();}},
                {std::string("cb_res_0_h"),[this](){this->cb_res_0_h();}},
                {std::string("cb_res_0_l"),[this](){this->cb_res_0_l();}},
                {std::string("cb_res_0_addr_hl"),[this](){this->cb_res_0_addr_hl();}},
                {std::string("cb_res_0_a"),[this](){this->cb_res_0_a();}},
                {std::string("cb_res_1_b"),[this](){this->cb_res_1_b();}},
                {std::string("cb_res_1_c"),[this](){this->cb_res_1_c();}},
                {std::string("cb_res_1_d"),[this](){this->cb_res_1_d();}},
                {std::string("cb_res_1_e"),[this](){this->cb_res_1_e();}},
                {std::string("cb_res_1_h"),[this](){this->cb_res_1_h();}},
                {std::string("cb_res_1_l"),[this](){this->cb_res_1_l();}},
                {std::string("cb_res_1_addr_hl"),[this](){this->cb_res_1_addr_hl();}},
                {std::string("cb_res_1_a"),[this](){this->cb_res_1_a();}},
                {std::string("cb_res_2_b"),[this](){this->cb_res_2_b();}},
                {std::string("cb_res_2_c"),[this](){this->cb_res_2_c();}},
                {std::string("cb_res_2_d"),[this](){this->cb_res_2_d();}},
                {std::string("cb_res_2_e"),[this](){this->cb_res_2_e();}},
                {std::string("cb_res_2_h"),[this](){this->cb_res_2_h();}},
                {std::string("cb_res_2_l"),[this](){this->cb_res_2_l();}},
                {std::string("cb_res_2_addr_hl"),[this](){this->cb_res_2_addr_hl();}},
                {std::string("cb_res_2_a"),[this](){this->cb_res_2_a();}},
                {std::string("cb_res_3_b"),[this](){this->cb_res_3_b();}},
                {std::string("cb_res_3_c"),[this](){this->cb_res_3_c();}},
                {std::string("cb_res_3_d"),[this](){this->cb_res_3_d();}},
                {std::string("cb_res_3_e"),[this](){this->cb_res_3_e();}},
                {std::string("cb_res_3_h"),[this](){this->cb_res_3_h();}},
                {std::string("cb_res_3_l"),[this](){this->cb_res_3_l();}},
                {std::string("cb_res_3_addr_hl"),[this](){this->cb_res_3_addr_hl();}},
                {std::string("cb_res_3_a"),[this](){this->cb_res_3_a();}},
                {std::string("cb_res_4_b"),[this](){this->cb_res_4_b();}},
                {std::string("cb_res_4_c"),[this](){this->cb_res_4_c();}},
                {std::string("cb_res_4_d"),[this](){this->cb_res_4_d();}},
                {std::string("cb_res_4_e"),[this](){this->cb_res_4_e();}},
                {std::string("cb_res_4_h"),[this](){this->cb_res_4_h();}},
                {std::string("cb_res_4_l"),[this](){this->cb_res_4_l();}},
                {std::string("cb_res_4_addr_hl"),[this](){this->cb_res_4_addr_hl();}},
                {std::string("cb_res_4_a"),[this](){this->cb_res_4_a();}},
                {std::string("cb_res_5_b"),[this](){this->cb_res_5_b();}},
                {std::string("cb_res_5_c"),[this](){this->cb_res_5_c();}},
                {std::string("cb_res_5_d"),[this](){this->cb_res_5_d();}},
                {std::string("cb_res_5_e"),[this](){this->cb_res_5_e();}},
                {std::string("cb_res_5_h"),[this](){this->cb_res_5_h();}},
                {std::string("cb_res_5_l"),[this](){this->cb_res_5_l();}},
                {std::string("cb_res_5_addr_hl"),[this](){this->cb_res_5_addr_hl();}},
                {std::string("cb_res_5_a"),[this](){this->cb_res_5_a();}},
                {std::string("cb_res_6_b"),[this](){this->cb_res_6_b();}},
                {std::string("cb_res_6_c"),[this](){this->cb_res_6_c();}},
                {std::string("cb_res_6_d"),[this](){this->cb_res_6_d();}},
                {std::string("cb_res_6_e"),[this](){this->cb_res_6_e();}},
                {std::string("cb_res_6_h"),[this](){this->cb_res_6_h();}},
                {std::string("cb_res_6_l"),[this](){this->cb_res_6_l();}},
                {std::string("cb_res_6_addr_hl"),[this](){this->cb_res_6_addr_hl();}},
                {std::string("cb_res_6_a"),[this](){this->cb_res_6_a();}},
                {std::string("cb_res_7_b"),[this](){this->cb_res_7_b();}},
                {std::string("cb_res_7_c"),[this](){this->cb_res_7_c();}},
                {std::string("cb_res_7_d"),[this](){this->cb_res_7_d();}},
                {std::string("cb_res_7_e"),[this](){this->cb_res_7_e();}},
                {std::string("cb_res_7_h"),[this](){this->cb_res_7_h();}},
                {std::string("cb_res_7_l"),[this](){this->cb_res_7_l();}},
                {std::string("cb_res_7_addr_hl"),[this](){this->cb_res_7_addr_hl();}},
                {std::string("cb_res_7_a"),[this](){this->cb_res_7_a();}},
                {std::string("cb_set_0_b"),[this](){this->cb_set_0_b();}},
                {std::string("cb_set_0_c"),[this](){this->cb_set_0_c();}},
                {std::string("cb_set_0_d"),[this](){this->cb_set_0_d();}},
                {std::string("cb_set_0_e"),[this](){this->cb_set_0_e();}},
                {std::string("cb_set_0_h"),[this](){this->cb_set_0_h();}},
                {std::string("cb_set_0_l"),[this](){this->cb_set_0_l();}},
                {std::string("cb_set_0_addr_hl"),[this](){this->cb_set_0_addr_hl();}},
                {std::string("cb_set_0_a"),[this](){this->cb_set_0_a();}},
                {std::string("cb_set_1_b"),[this](){this->cb_set_1_b();}},
                {std::string("cb_set_1_c"),[this](){this->cb_set_1_c();}},
                {std::string("cb_set_1_d"),[this](){this->cb_set_1_d();}},
                {std::string("cb_set_1_e"),[this](){this->cb_set_1_e();}},
                {std::string("cb_set_1_h"),[this](){this->cb_set_1_h();}},
                {std::string("cb_set_1_l"),[this](){this->cb_set_1_l();}},
                {std::string("cb_set_1_addr_hl"),[this](){this->cb_set_1_addr_hl();}},
                {std::string("cb_set_1_a"),[this](){this->cb_set_1_a();}},
                {std::string("cb_set_2_b"),[this](){this->cb_set_2_b();}},
                {std::string("cb_set_2_c"),[this](){this->cb_set_2_c();}},
                {std::string("cb_set_2_d"),[this](){this->cb_set_2_d();}},
                {std::string("cb_set_2_e"),[this](){this->cb_set_2_e();}},
                {std::string("cb_set_2_h"),[this](){this->cb_set_2_h();}},
                {std::string("cb_set_2_l"),[this](){this->cb_set_2_l();}},
                {std::string("cb_set_2_addr_hl"),[this](){this->cb_set_2_addr_hl();}},
                {std::string("cb_set_2_a"),[this](){this->cb_set_2_a();}},
                {std::string("cb_set_3_b"),[this](){this->cb_set_3_b();}},
                {std::string("cb_set_3_c"),[this](){this->cb_set_3_c();}},
                {std::string("cb_set_3_d"),[this](){this->cb_set_3_d();}},
                {std::string("cb_set_3_e"),[this](){this->cb_set_3_e();}},
                {std::string("cb_set_3_h"),[this](){this->cb_set_3_h();}},
                {std::string("cb_set_3_l"),[this](){this->cb_set_3_l();}},
                {std::string("cb_set_3_addr_hl"),[this](){this->cb_set_3_addr_hl();}},
                {std::string("cb_set_3_a"),[this](){this->cb_set_3_a();}},
                {std::string("cb_set_4_b"),[this](){this->cb_set_4_b();}},
                {std::string("cb_set_4_c"),[this](){this->cb_set_4_c();}},
                {std::string("cb_set_4_d"),[this](){this->cb_set_4_d();}},
                {std::string("cb_set_4_e"),[this](){this->cb_set_4_e();}},
                {std::string("cb_set_4_h"),[this](){this->cb_set_4_h();}},
                {std::string("cb_set_4_l"),[this](){this->cb_set_4_l();}},
                {std::string("cb_set_4_addr_hl"),[this](){this->cb_set_4_addr_hl();}},
                {std::string("cb_set_4_a"),[this](){this->cb_set_4_a();}},
                {std::string("cb_set_5_b"),[this](){this->cb_set_5_b();}},
                {std::string("cb_set_5_c"),[this](){this->cb_set_5_c();}},
                {std::string("cb_set_5_d"),[this](){this->cb_set_5_d();}},
                {std::string("cb_set_5_e"),[this](){this->cb_set_5_e();}},
                {std::string("cb_set_5_h"),[this](){this->cb_set_5_h();}},
                {std::string("cb_set_5_l"),[this](){this->cb_set_5_l();}},
                {std::string("cb_set_5_addr_hl"),[this](){this->cb_set_5_addr_hl();}},
                {std::string("cb_set_5_a"),[this](){this->cb_set_5_a();}},
                {std::string("cb_set_6_b"),[this](){this->cb_set_6_b();}},
                {std::string("cb_set_6_c"),[this](){this->cb_set_6_c();}},
                {std::string("cb_set_6_d"),[this](){this->cb_set_6_d();}},
                {std::string("cb_set_6_e"),[this](){this->cb_set_6_e();}},
                {std::string("cb_set_6_h"),[this](){this->cb_set_6_h();}},
                {std::string("cb_set_6_l"),[this](){this->cb_set_6_l();}},
                {std::string("cb_set_6_addr_hl"),[this](){this->cb_set_6_addr_hl();}},
                {std::string("cb_set_6_a"),[this](){this->cb_set_6_a();}},
                {std::string("cb_set_7_b"),[this](){this->cb_set_7_b();}},
                {std::string("cb_set_7_c"),[this](){this->cb_set_7_c();}},
                {std::string("cb_set_7_d"),[this](){this->cb_set_7_d();}},
                {std::string("cb_set_7_e"),[this](){this->cb_set_7_e();}},
                {std::string("cb_set_7_h"),[this](){this->cb_set_7_h();}},
                {std::string("cb_set_7_l"),[this](){this->cb_set_7_l();}},
                {std::string("cb_set_7_addr_hl"),[this](){this->cb_set_7_addr_hl();}},
                {std::string("cb_set_7_a"),[this](){this->cb_set_7_a();}},
        };
}
void CPU::connect_to_bus(const std::shared_ptr<Bus>& bus){
        this->bus = bus;
}

void CPU::step(){
        std::uint8_t op_code{bus->read(pc)};
        pc++;
        std::cout << "op = " << lookup_table[op_code].mneomic << '\n';
        std::cout << std::hex;
        std::cout << "pc = " << (int)pc << '\n';
        lookup_table[op_code].execute();
        std::cout << "a = " << (int)a << '\n';
        std::cout << "b = " << (int)b << '\n';
        std::cout << "c = " << (int)c << '\n';
        std::cout << "d = " << (int)d << '\n';
        std::cout << "e = " << (int)e << '\n';
        std::cout << "h = " << (int)h << '\n';
        std::cout << "af = " << (int)af << '\n';
        std::cout << "bc = " << (int)bc << '\n';
        std::cout << "de = " << (int)de << '\n';
        std::cout << "hl = " << (int)hl << '\n';
}

std::uint8_t CPU::fetch_byte(){
        std::uint8_t byte{bus->read(pc)};
        pc++;
        return byte;
}

std::uint16_t CPU::fetch_word(){
        std::uint8_t low{fetch_byte()};
        std::uint8_t high{fetch_byte()};
        return static_cast<std::uint16_t>((static_cast<std::uint16_t>(high)<<8) | static_cast<std::uint16_t>(low));
}

void CPU::push_word(std::uint16_t word){
        sp--;
        bus->write(sp, static_cast<std::uint8_t>(word>>8));
        sp--;
        bus->write(sp, static_cast<std::uint8_t>(word&0xFF));
}

std::uint16_t CPU::pop_word(){
        std::uint8_t low{bus->read(sp)};
        sp++;
        std::uint8_t high{bus->read(sp)};
        sp++;
        return static_cast<std::uint16_t>((static_cast<std::uint16_t>(high)<<8) | static_cast<std::uint16_t>(low));
}

void CPU::_load_8_bit_reg(std::uint8_t& reg, std::uint8_t operand){
        reg = operand;
}

void CPU::_load_16_bit_reg(std::uint16_t& reg, std::uint16_t operand){
        reg = operand;
}

void CPU::_inc_8_bit_reg(std::uint8_t& reg){
        half_carry = ((reg&0x0F) == 0x0F);
        reg++;
        zero = (reg == 0);
        n_flag = 0;
}

void CPU::_inc_16_bit_reg(std::uint16_t& reg){
        reg++;
}

void CPU::_dec_8_bit_reg(std::uint8_t& reg){
        half_carry = ((reg&0x0F) == 0x00);
        reg--;
        zero = (reg==0);
        n_flag = 1;
}

void CPU::_dec_16_bit_reg(std::uint16_t& reg){
        reg--;
}

void CPU::_add_8_bit_reg(std::uint8_t& operand_1, std::uint8_t& operand_2){
        std::uint16_t res{static_cast<std::uint16_t>(static_cast<std::uint16_t>(operand_1)+static_cast<std::uint16_t>(operand_2))};
        half_carry = (((operand_1&0x0F)+(operand_2&0xF)) > 0x0F);
        carry = (res > 0xFF);
        operand_1 = static_cast<std::uint8_t>(res);
        zero = (operand_1 == 0);
        n_flag = 0;
}

void CPU::_add_16_bit_reg(std::uint16_t& operand_1, std::uint16_t& operand_2){
        std::uint32_t res{static_cast<std::uint32_t>(operand_1)+static_cast<std::uint32_t>(operand_2)};
        half_carry = ((operand_1&0x0FFF)+(operand_2&0x0FFF) > 0x0FFF);
        carry = (res > 0xFFFF);
        operand_1 = static_cast<std::uint16_t>(res);
        n_flag = 0;
}

void CPU::_adc(std::uint8_t& operand_1, std::uint8_t& operand_2){
        std::uint16_t res{static_cast<std::uint16_t>(static_cast<std::uint16_t>(operand_1)+
                                                     static_cast<std::uint16_t>(operand_2)+
                                                     static_cast<std::uint16_t>(carry))};
        half_carry = (((operand_1&0x0F)+(operand_2&0xF)+carry) > 0x0F);
        carry = (res > 0xFF);
        operand_1 = static_cast<std::uint8_t>(res);
        zero = (operand_1 == 0);
        n_flag = 0;
}

void CPU::_sub(std::uint8_t& operand_1, std::uint8_t& operand_2){
        half_carry = ((operand_1&0x0F) < (operand_2&0x0F));
        carry = (operand_1 < operand_2);
        operand_1 -= operand_2;
        zero = (operand_1 == 0);
        n_flag = 1;
}

void CPU::_sbc(std::uint8_t& operand_1, std::uint8_t& operand_2){
        std::int16_t res{static_cast<std::int16_t>(
                         static_cast<std::int16_t>(operand_1)-
                         static_cast<std::int16_t>(operand_2)-
                         static_cast<std::int16_t>(carry)
                        )};
        half_carry = (((operand_1&0x0F) - (operand_2&0x0F) - carry) < 0);
        carry = (res < 0);
        operand_1 = static_cast<std::uint8_t>(res);
        zero = (operand_1 == 0);
        n_flag = 1;
}

void CPU::_and(std::uint8_t& operand_1, std::uint8_t& operand_2){
        operand_1 &= operand_2;
        zero = (operand_1 == 0);
        n_flag = 0;
        half_carry = 1;
        carry = 0;
}

void CPU::_xor(std::uint8_t& operand_1, std::uint8_t& operand_2){
        operand_1 ^= operand_2;
        zero = (operand_1 == 0);
        n_flag = 0;
        half_carry = 0;
        carry = 0;
}

void CPU::_or(std::uint8_t& operand_1, std::uint8_t& operand_2){
        operand_1 |= operand_2;
        zero = (operand_1 == 0);
        n_flag = 0;
        half_carry = 0;
        carry = 0;
}

void CPU::_cp(std::uint8_t& operand_1, std::uint8_t& operand_2){
        zero = (operand_1 == operand_2);
        n_flag = 1;
        half_carry = ((operand_1&0x0F) < (operand_2&0x0F));
        carry = (operand_1 < operand_2);
}

void CPU::_jr(std::uint8_t operand, bool condition){
        std::int8_t offset{static_cast<std::int8_t>(operand)};
        if(condition){
                pc += offset;
        }
}

void CPU::_jp(std::uint16_t operand, bool condition){
        if(condition){
                pc = operand;
        }
}

void CPU::_call(std::uint16_t operand, bool condition){
        if(condition){
                push_word(pc);
                pc = operand;
        }
}

void CPU::_ret(bool condition){
        if(condition){
                std::uint16_t ret_addr{pop_word()};
                pc = ret_addr;
        }
}

void CPU::_rst(std::uint8_t operand){
        push_word(pc);
        pc = operand;
}

void CPU::cb_rlc(std::uint8_t& reg){
        std::uint8_t bit7{static_cast<std::uint8_t>(reg>>7)};
        reg <<= 1;
        reg |= bit7;
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit7;
}

void CPU::cb_rrc(std::uint8_t& reg){
        std::uint8_t bit0{static_cast<std::uint8_t>(reg&1)};
        reg >>= 1;
        reg |= (bit0<<7);
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::cb_rl(std::uint8_t& reg){
        std::uint8_t bit7{static_cast<std::uint8_t>(reg>>7)};
        reg <<= 1;
        reg |= carry;
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit7;
}

void CPU::cb_rr(std::uint8_t& reg){
        std::uint8_t bit0{static_cast<std::uint8_t>(reg&1)};
        reg >>= 1;
        reg |= (carry<<7);
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::cb_sla(std::uint8_t& reg){
        std::uint8_t bit7{static_cast<std::uint8_t>(reg>>7)};
        reg <<= 1;
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit7;
}

void CPU::cb_sra(std::uint8_t& reg){
        std::uint8_t bit7{static_cast<std::uint8_t>(reg>>7)};
        std::uint8_t bit0{static_cast<std::uint8_t>(reg&1)};
        reg >>= 1;
        reg |= (bit7<<7);
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::cb_swap(std::uint8_t& reg){
        std::uint8_t upper{static_cast<std::uint8_t>(reg&0xF0)};
        std::uint8_t lower{static_cast<std::uint8_t>(reg&0x0F)};
        reg = (lower<<4) | (upper>>4);
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = 0;
}

void CPU::cb_srl(std::uint8_t& reg){
        std::uint8_t bit0{static_cast<std::uint8_t>(reg&1)};
        reg >>= 1;
        zero = (reg == 0);
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::cb_bit(std::uint8_t& reg, std::uint8_t n_bit){
        std::uint8_t bit{static_cast<std::uint8_t>((reg>>n_bit)&1)};
        zero = (bit == 0);
        n_flag = 0;
        half_carry = 1;
}

void CPU::cb_res(std::uint8_t& reg, std::uint8_t n_bit){
        reg &= ~(1<<n_bit);
}

void CPU::cb_set(std::uint8_t& reg, std::uint8_t n_bit){
        reg |= (1<<n_bit);
}

void CPU::nop(){
}

void CPU::load_bc(){
        _load_16_bit_reg(bc, fetch_word());
}

void CPU::load_addr_bc_a(){
        bus->write(bc, a);
}

void CPU::inc_bc(){
        _inc_16_bit_reg(bc);
}

void CPU::inc_b(){
        _inc_8_bit_reg(b);
}

void CPU::dec_b(){
        _dec_8_bit_reg(b);
}

void CPU::load_b(){
        _load_8_bit_reg(b, fetch_byte());
}

void CPU::rlca(){
        std::uint8_t bit7{static_cast<std::uint8_t>((a>>7)&1)};
        a <<= 1;
        a = bit7 ? a | 1 : a;
        zero = 0;
        n_flag = 0;
        half_carry = 0;
        carry = bit7;
}

void CPU::load_addr_sp(){
        std::uint16_t addr{fetch_word()};
        std::uint8_t sp_low{static_cast<std::uint8_t>(sp&0x00FF)};
        std::uint8_t sp_high{static_cast<std::uint8_t>(sp>>8)};
        bus->write(addr, sp_low);
        bus->write(addr+1, sp_high);
}

void CPU::add_hl_bc(){
        _add_16_bit_reg(hl, bc);
}

void CPU::load_a_addr_bc(){
        _load_8_bit_reg(a, bus->read(bc));
}

void CPU::dec_bc(){
        _dec_16_bit_reg(bc);
}

void CPU::inc_c(){
        _inc_8_bit_reg(c);
}

void CPU::dec_c(){
        _dec_8_bit_reg(c);
}

void CPU::load_c(){
        _load_8_bit_reg(c, fetch_byte());
}

void CPU::rrca(){
        std::uint8_t bit0{static_cast<std::uint8_t>((a)&1)};
        a >>= 1;
        a = bit0 ? a | 0x80 : a;
        zero = 0;
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::stop(){
        fetch_byte();
        // 2. TODO: Pause the CPU (Implement later!)
        // For now, do nothing. Just let the CPU keep running.
        // If we pause here without working interrupts, the emulator dies.

        // 3. TODO: Handle GBC Speed Switch (Implement much later)
}

void CPU::load_de(){
        _load_16_bit_reg(de, fetch_word());
}

void CPU::load_addr_de_a(){
        bus->write(de, a);
}

void CPU::inc_de(){
        _inc_16_bit_reg(de);
}

void CPU::inc_d(){
        _inc_8_bit_reg(d);
}

void CPU::dec_d(){
        _dec_8_bit_reg(d);
}

void CPU::load_d(){
        _load_8_bit_reg(d, fetch_byte());
}

void CPU::rla(){
        std::uint8_t bit7{static_cast<std::uint8_t>((a>>7)&1)};
        a <<= 1;
        a |= carry;
        zero = 0;
        n_flag = 0;
        half_carry = 0;
        carry = bit7;
}

void CPU::jr(){
        _jr(fetch_byte(), true);
}

void CPU::add_hl_de(){
        _add_16_bit_reg(hl, de);
}

void CPU::load_a_addr_de(){
        _load_8_bit_reg(a, bus->read(de));
}

void CPU::dec_de(){
        _dec_16_bit_reg(de);
}

void CPU::inc_e(){
        _inc_8_bit_reg(e);
}

void CPU::dec_e(){
        _dec_8_bit_reg(e);
}

void CPU::load_e(){
        _load_8_bit_reg(e, fetch_byte());
}

void CPU::rra(){
        std::uint8_t bit0{static_cast<std::uint8_t>((a)&1)};
        a >>= 1;
        a |= (carry<<7);
        zero = 0;
        n_flag = 0;
        half_carry = 0;
        carry = bit0;
}

void CPU::jr_nz(){
        _jr(fetch_byte(), !zero);
}

void CPU::load_hl(){
        _load_16_bit_reg(hl, fetch_word());
}

void CPU::load_addr_hl_plus_a(){
        bus->write(hl,a);
        hl++;
}

void CPU::inc_hl(){
        _inc_16_bit_reg(hl);
}

void CPU::inc_h(){
        _inc_8_bit_reg(h);
}

void CPU::dec_h(){
        _dec_8_bit_reg(h);
}

void CPU::load_h(){
        _load_8_bit_reg(h, fetch_byte());
}

void CPU::daa(){
        std::uint8_t correction{};
        std::uint8_t set_carry{0};
        if(!n_flag){
                if(half_carry || (a&0x0F) > 0x09){
                        correction |= 0x06;
                }
                if(carry || a > 0x99){
                        correction |= 0x60;
                        set_carry = 1;
                }
                a += correction;
        }
        else{
                if(half_carry){
                        correction |= 0x06;
                }
                if(carry){
                        correction |= 0x60;
                        set_carry = 1;
                }
                a -= correction;
        }
        zero = (a==0);
        half_carry = 0;
        carry = set_carry;
}

void CPU::jr_z(){
        _jr(fetch_byte(), zero);
}

void CPU::add_hl_hl(){
        _add_16_bit_reg(hl, hl);
}

void CPU::load_a_addr_hl_plus(){
        _load_8_bit_reg(a, bus->read(hl));
        hl++;
}

void CPU::dec_hl(){
        _dec_16_bit_reg(hl);
}

void CPU::inc_l(){
        _inc_8_bit_reg(l);
}

void CPU::dec_l(){
        _dec_8_bit_reg(l);
}

void CPU::load_l(){
        _load_8_bit_reg(l, fetch_byte());
}

void CPU::cpl(){
        a = ~a;
        n_flag = 1;
        half_carry = 1;
}

void CPU::jr_nc(){
        _jr(fetch_byte(), !carry);
}

void CPU::load_sp(){
        _load_16_bit_reg(sp, fetch_word());
}

void CPU::load_addr_hl_minus_a(){
        bus->write(hl, a);
        hl--;
}

void CPU::inc_sp(){
        _inc_16_bit_reg(sp);
}

void CPU::inc_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _inc_8_bit_reg(val);
        bus->write(hl, val);
}

void CPU::dec_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _dec_8_bit_reg(val);
        bus->write(hl, val);
}

void CPU::load_addr_hl(){
        bus->write(hl, fetch_byte());
}

void CPU::scf(){
        n_flag = 0;
        half_carry = 0;
        carry = 1;
}

void CPU::jr_c(){
        _jr(fetch_byte(), carry);
}

void CPU::add_hl_sp(){
        _add_16_bit_reg(hl, sp);
}

void CPU::load_a_addr_hl_minus(){
        _load_8_bit_reg(a, bus->read(hl));
        hl--;
}

void CPU::dec_sp(){
        _dec_16_bit_reg(sp);
}

void CPU::inc_a(){
        _inc_8_bit_reg(a);
}

void CPU::dec_a(){
        _dec_8_bit_reg(a);
}

void CPU::load_a(){
        _load_8_bit_reg(a, fetch_byte());
}

void CPU::ccf(){
        n_flag = 0;
        half_carry = 0;
        carry = ~carry;
}

void CPU::load_b_b(){}

void CPU::load_b_c(){
        _load_8_bit_reg(b, c);
}

void CPU::load_b_d(){
        _load_8_bit_reg(b, d);
}

void CPU::load_b_e(){
        _load_8_bit_reg(b, e);
}

void CPU::load_b_h(){
        _load_8_bit_reg(b, h);
}

void CPU::load_b_l(){
        _load_8_bit_reg(b, l);
}

void CPU::load_b_addr_hl(){
        _load_8_bit_reg(b, bus->read(hl));
}

void CPU::load_b_a(){
        _load_8_bit_reg(b, a);
}

void CPU::load_c_b(){
        _load_8_bit_reg(c, b);
}

void CPU::load_c_c(){}

void CPU::load_c_d(){
        _load_8_bit_reg(c, d);
}

void CPU::load_c_e(){
        _load_8_bit_reg(c, e);
}

void CPU::load_c_h(){
        _load_8_bit_reg(c, h);
}

void CPU::load_c_l(){
        _load_8_bit_reg(c, l);
}

void CPU::load_c_addr_hl(){
        _load_8_bit_reg(c, bus->read(hl));
}

void CPU::load_c_a(){
        _load_8_bit_reg(c, a);
}

void CPU::load_d_b(){
        _load_8_bit_reg(d, b);
}

void CPU::load_d_c(){
        _load_8_bit_reg(d, c);
}

void CPU::load_d_d(){}

void CPU::load_d_e(){
        _load_8_bit_reg(d, e);
}

void CPU::load_d_h(){
        _load_8_bit_reg(d, h);
}

void CPU::load_d_l(){
        _load_8_bit_reg(d, l);
}

void CPU::load_d_addr_hl(){
        _load_8_bit_reg(d, bus->read(hl));
}

void CPU::load_d_a(){
        _load_8_bit_reg(d, a);
}

void CPU::load_e_b(){
        _load_8_bit_reg(e, b);
}

void CPU::load_e_c(){
        _load_8_bit_reg(e, c);
}

void CPU::load_e_d(){
        _load_8_bit_reg(e, d);
}

void CPU::load_e_e(){}

void CPU::load_e_h(){
        _load_8_bit_reg(e, h);
}

void CPU::load_e_l(){
        _load_8_bit_reg(e, l);
}

void CPU::load_e_addr_hl(){
        _load_8_bit_reg(e, bus->read(hl));
}

void CPU::load_e_a(){
        _load_8_bit_reg(e, a);
}

void CPU::load_h_b(){
        _load_8_bit_reg(h, b);
}

void CPU::load_h_c(){
        _load_8_bit_reg(h, c);
}

void CPU::load_h_d(){
        _load_8_bit_reg(h, d);
}

void CPU::load_h_e(){
        _load_8_bit_reg(h, e);
}

void CPU::load_h_h(){}

void CPU::load_h_l(){
        _load_8_bit_reg(h, l);
}

void CPU::load_h_addr_hl(){
        _load_8_bit_reg(h, bus->read(hl));
}

void CPU::load_h_a(){
        _load_8_bit_reg(h, a);
}

void CPU::load_l_b(){
        _load_8_bit_reg(l, b);
}

void CPU::load_l_c(){
        _load_8_bit_reg(l, c);
}

void CPU::load_l_d(){
        _load_8_bit_reg(l, d);
}

void CPU::load_l_e(){
        _load_8_bit_reg(l, e);
}

void CPU::load_l_h(){
        _load_8_bit_reg(l, h);
}

void CPU::load_l_l(){}

void CPU::load_l_addr_hl(){
        _load_8_bit_reg(l, bus->read(hl));
}

void CPU::load_l_a(){
        _load_8_bit_reg(l, a);
}

void CPU::load_addr_hl_b(){
        bus->write(hl, b);
}

void CPU::load_addr_hl_c(){
        bus->write(hl, c);
}

void CPU::load_addr_hl_d(){
        bus->write(hl, d);
}

void CPU::load_addr_hl_e(){
        bus->write(hl, e);
}

void CPU::load_addr_hl_h(){
        bus->write(hl, h);
}

void CPU::load_addr_hl_l(){
        bus->write(hl, l);
}

void CPU::halt(){
        // TO DO implement interrupt enable register
}

void CPU::load_addr_hl_a(){
        bus->write(hl, a);
}

void CPU::load_a_b(){
        _load_8_bit_reg(a, b);
}

void CPU::load_a_c(){
        _load_8_bit_reg(a, c);
}

void CPU::load_a_d(){
        _load_8_bit_reg(a, d);
}

void CPU::load_a_e(){
        _load_8_bit_reg(a, e);
}

void CPU::load_a_h(){
        _load_8_bit_reg(a, h);
}

void CPU::load_a_l(){
        _load_8_bit_reg(a, l);
}

void CPU::load_a_addr_hl(){
        _load_8_bit_reg(a, bus->read(hl));
}

void CPU::load_a_a(){}

void CPU::add_a_b(){
        _add_8_bit_reg(a, b);
}

void CPU::add_a_c(){
        _add_8_bit_reg(a, c);
}

void CPU::add_a_d(){
        _add_8_bit_reg(a, d);
}

void CPU::add_a_e(){
        _add_8_bit_reg(a, e);
}

void CPU::add_a_h(){
        _add_8_bit_reg(a, h);
}

void CPU::add_a_l(){
        _add_8_bit_reg(a, l);
}

void CPU::add_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _add_8_bit_reg(a, val);
}

void CPU::add_a_a(){
        _add_8_bit_reg(a, a);
}

void CPU::adc_a_b(){
        _adc(a, b);
}

void CPU::adc_a_c(){
        _adc(a, c);
}

void CPU::adc_a_d(){
        _adc(a, d);
}

void CPU::adc_a_e(){
        _adc(a, e);
}

void CPU::adc_a_h(){
        _adc(a, h);
}

void CPU::adc_a_l(){
        _adc(a, l);
}

void CPU::adc_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _adc(a, val);
}

void CPU::adc_a_a(){
        _adc(a, a);
}

void CPU::sub_a_b(){
        _sub(a, b);
}

void CPU::sub_a_c(){
        _sub(a, c);
}

void CPU::sub_a_d(){
        _sub(a, d);
}

void CPU::sub_a_e(){
        _sub(a, e);
}

void CPU::sub_a_h(){
        _sub(a, h);
}

void CPU::sub_a_l(){
        _sub(a, l);
}

void CPU::sub_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _sub(a, val);
}

void CPU::sub_a_a(){
        _sub(a, a);
}

void CPU::sbc_a_b(){
        _sbc(a, b);
}

void CPU::sbc_a_c(){
        _sbc(a, c);
}

void CPU::sbc_a_d(){
        _sbc(a, d);
}

void CPU::sbc_a_e(){
        _sbc(a, e);
}

void CPU::sbc_a_h(){
        _sbc(a, h);
}

void CPU::sbc_a_l(){
        _sbc(a, l);
}

void CPU::sbc_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _sbc(a, val);
}

void CPU::sbc_a_a(){
        _sbc(a, a);
}

void CPU::and_a_b(){
        _and(a, b);
}

void CPU::and_a_c(){
        _and(a, c);
}

void CPU::and_a_d(){
        _and(a, d);
}

void CPU::and_a_e(){
        _and(a, e);
}

void CPU::and_a_h(){
        _and(a, h);
}

void CPU::and_a_l(){
        _and(a, l);
}

void CPU::and_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _and(a, val);
}

void CPU::and_a_a(){
        _and(a, a);
}

void CPU::xor_a_b(){
        _xor(a, b);
}

void CPU::xor_a_c(){
        _xor(a, c);
}

void CPU::xor_a_d(){
        _xor(a, d);
}

void CPU::xor_a_e(){
        _xor(a, e);
}

void CPU::xor_a_h(){
        _xor(a, h);
}

void CPU::xor_a_l(){
        _xor(a, l);
}

void CPU::xor_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _xor(a, val);
}

void CPU::xor_a_a(){
        _xor(a, a);
}

void CPU::or_a_b(){
        _or(a, b);
}

void CPU::or_a_c(){
        _or(a, c);
}

void CPU::or_a_d(){
        _or(a, d);
}

void CPU::or_a_e(){
        _or(a, e);
}

void CPU::or_a_h(){
        _or(a, h);
}

void CPU::or_a_l(){
        _or(a, l);
}

void CPU::or_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _or(a, val);
}

void CPU::or_a_a(){
        _or(a, a);
}

void CPU::cp_a_b(){
        _cp(a, b);
}

void CPU::cp_a_c(){
        _cp(a, c);
}

void CPU::cp_a_d(){
        _cp(a, d);
}

void CPU::cp_a_e(){
        _cp(a, e);
}

void CPU::cp_a_h(){
        _cp(a, h);
}

void CPU::cp_a_l(){
        _cp(a, l);
}

void CPU::cp_a_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        _cp(a, val);
}

void CPU::cp_a_a(){
        _cp(a, a);
}

void CPU::ret_nz(){
        _ret(!zero);
}

void CPU::pop_bc(){
        bc = pop_word();
}

void CPU::jp_nz(){
        _jp(fetch_word(), !zero);
}

void CPU::jp(){
        _jp(fetch_word(), true);
}

void CPU::call_nz(){
        _call(fetch_word(), !zero);
}

void CPU::push_bc(){
        push_word(bc);
}

void CPU::add_a(){
        std::uint8_t val{fetch_byte()};
        _add_8_bit_reg(a, val);
}

void CPU::rst_00h(){
        _rst(0x00);
}

void CPU::ret_z(){
        _ret(zero);
}

void CPU::ret(){
        _ret(true);
}

void CPU::jp_z(){
        _jp(fetch_word(), zero);
}

void CPU::prefix(){
        std::uint8_t op_code{fetch_byte()};
        std::cout << cb_lookup_table[op_code].mneomic << '\n';
        std::cout << std::hex;
        std::cout << "pc = " << (int)pc << '\n';
        lookup_table[op_code].execute();
        std::cout << "a = " << (int)a << '\n';
        std::cout << "b = " << (int)b << '\n';
        std::cout << "c = " << (int)c << '\n';
        std::cout << "d = " << (int)d << '\n';
        std::cout << "e = " << (int)e << '\n';
        std::cout << "h = " << (int)h << '\n';
        std::cout << "af = " << (int)af << '\n';
        std::cout << "bc = " << (int)bc << '\n';
        std::cout << "de = " << (int)de << '\n';
        std::cout << "hl = " << (int)hl << '\n';
}

void CPU::call_z(){
        _call(fetch_word(), zero);
}

void CPU::call(){
        _call(fetch_word(), true);
}

void CPU::adc_a(){
        std::uint8_t val{fetch_byte()};
        _adc(a, val);
}

void CPU::rst_08h(){
        _rst(0x08);
}

void CPU::ret_nc(){
        _ret(!carry);
}

void CPU::pop_de(){
        de = pop_word();
}

void CPU::jp_nc(){
        _jp(fetch_word(), !carry);
}

void CPU::call_nc(){
        _call(fetch_word(), !carry);
}

void CPU::push_de(){
        push_word(de);
}

void CPU::sub_a(){
        std::uint8_t val{fetch_byte()};
        _sub(a, val);
}

void CPU::rst_10h(){
        _rst(0x10);
}

void CPU::ret_c(){
        _ret(carry);
}

void CPU::reti(){
        _ret(true);
        // interrupt_master_enable = true;
}

void CPU::jp_c(){
        _jp(fetch_word(), carry);
}

void CPU::call_c(){
        _call(fetch_word(), carry);
}

void CPU::sbc_a(){
        std::uint8_t val{fetch_byte()};
        _sbc(a, val);
}

void CPU::rst_18h(){
        _rst(0x18);
}

void CPU::ldh_addr_a(){
        std::uint8_t offset{fetch_byte()};
        std::uint16_t addr{static_cast<std::uint16_t>(static_cast<std::uint16_t>(0xFF00) | static_cast<std::uint16_t>(offset))};
        bus->write(addr, a);
}

void CPU::pop_hl(){
        hl = pop_word();
}

void CPU::ldh_addr_c_a(){
        std::uint16_t addr{static_cast<std::uint16_t>(static_cast<std::uint16_t>(0xFF00) | static_cast<std::uint16_t>(c))};
        bus->write(addr, a);
}

void CPU::push_hl(){
        push_word(hl);
}

void CPU::and_a(){
        std::uint8_t val{fetch_byte()};
        _and(a, val);
}

void CPU::rst_20h(){
        _rst(0x20);
}

void CPU::add_sp(){
        std::int8_t offset{static_cast<std::int8_t>(fetch_byte())};
        half_carry = (((sp & 0x0F) + (offset & 0x0F)) > 0x0F);
        carry = (((sp & 0xFF) + (offset & 0xFF)) > 0xFF);
        sp += offset;
        zero = 0;
        n_flag = 0;
}

void CPU::jp_hl(){
        _jp(hl, true);
}

void CPU::load_addr_a(){
        std::uint16_t addr{fetch_word()};
        bus->write(addr, a);
}

void CPU::xor_a(){
        std::uint8_t val{fetch_byte()};
        _xor(a, val);
}

void CPU::rst_28h(){
        _rst(0x28);
}

void CPU::ldh_a_addr(){
        std::uint8_t addr{fetch_byte()};
        std::uint16_t effective_addr{static_cast<std::uint16_t>(
                                     static_cast<std::uint16_t>(0xFF00) | static_cast<std::uint16_t>(addr))};
        a = bus->read(effective_addr);
}

void CPU::pop_af(){
        af = pop_word()&0xFFF0;
}

void CPU::ldh_a_addr_c(){
        std::uint16_t effective_addr{static_cast<std::uint16_t>(
                                     static_cast<std::uint16_t>(0xFF00) | static_cast<std::uint16_t>(c))};
        a = bus->read(effective_addr);
}

void CPU::di(){
        // disable interrupt
}

void CPU::push_af(){
        push_word(af);
}

void CPU::or_a(){
        std::uint8_t val{fetch_byte()};
        _or(a, val);
}

void CPU::rst_30h(){
        _rst(0x30);
}

void CPU::load_hl_sp_add(){
        std::int8_t offset{static_cast<std::int8_t>(fetch_byte())};
        half_carry = (((sp & 0x0F) + (offset & 0x0F)) > 0x0F);
        carry = (((sp & 0xFF) + (offset & 0xFF)) > 0xFF);
        hl = sp+offset;
        zero = 0;
        n_flag = 0;
}

void CPU::load_sp_hl(){
        _load_16_bit_reg(sp, hl);
}

void CPU::load_a_addr(){
        std::uint16_t addr{fetch_word()};
        _load_8_bit_reg(a, bus->read(addr));
}

void CPU::ei(){
        // enable interrupt
}

void CPU::cp_a(){
        std::uint8_t val{fetch_byte()};
        _cp(a, val);
}

void CPU::rst_38h(){
        _rst(0x38);
}

void CPU::cb_rlc_b(){
        cb_rlc(b);
}

void CPU::cb_rlc_c(){
        cb_rlc(c);
}

void CPU::cb_rlc_d(){
        cb_rlc(d);
}

void CPU::cb_rlc_e(){
        cb_rlc(e);
}

void CPU::cb_rlc_h(){
        cb_rlc(h);
}

void CPU::cb_rlc_l(){
        cb_rlc(l);
}

void CPU::cb_rlc_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_rlc(val);
        bus->write(hl, val);
}

void CPU::cb_rlc_a(){
        cb_rlc(a);
}

void CPU::cb_rrc_b(){
        cb_rrc(b);
}

void CPU::cb_rrc_c(){
        cb_rrc(c);
}

void CPU::cb_rrc_d(){
        cb_rrc(d);
}

void CPU::cb_rrc_e(){
        cb_rrc(e);
}

void CPU::cb_rrc_h(){
        cb_rrc(h);
}

void CPU::cb_rrc_l(){
        cb_rrc(l);
}

void CPU::cb_rrc_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_rrc(val);
        bus->write(hl, val);
}

void CPU::cb_rrc_a(){
        cb_rrc(a);
}

void CPU::cb_rl_b(){
        cb_rl(b);
}

void CPU::cb_rl_c(){
        cb_rl(c);
}

void CPU::cb_rl_d(){
        cb_rl(d);
}

void CPU::cb_rl_e(){
        cb_rl(e);
}

void CPU::cb_rl_h(){
        cb_rl(h);
}

void CPU::cb_rl_l(){
        cb_rl(l);
}

void CPU::cb_rl_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_rl(val);
        bus->write(hl, val);
}

void CPU::cb_rl_a(){
        cb_rl(a);
}

void CPU::cb_rr_b(){
        cb_rr(b);
}

void CPU::cb_rr_c(){
        cb_rr(c);
}

void CPU::cb_rr_d(){
        cb_rr(d);
}

void CPU::cb_rr_e(){
        cb_rr(e);
}

void CPU::cb_rr_h(){
        cb_rr(h);
}

void CPU::cb_rr_l(){
        cb_rr(l);
}

void CPU::cb_rr_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_rr(val);
        bus->write(hl, val);
}

void CPU::cb_rr_a(){
        cb_rr(a);
}

void CPU::cb_sla_b(){
        cb_sla(b);
}

void CPU::cb_sla_c(){
        cb_sla(c);
}

void CPU::cb_sla_d(){
        cb_sla(d);
}

void CPU::cb_sla_e(){
        cb_sla(e);
}

void CPU::cb_sla_h(){
        cb_sla(h);
}

void CPU::cb_sla_l(){
        cb_sla(l);
}

void CPU::cb_sla_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_sla(val);
        bus->write(hl, val);
}

void CPU::cb_sla_a(){
        cb_sla(a);
}

void CPU::cb_sra_b(){
        cb_sra(b);
}

void CPU::cb_sra_c(){
        cb_sra(c);
}

void CPU::cb_sra_d(){
        cb_sra(d);
}

void CPU::cb_sra_e(){
        cb_sra(e);
}

void CPU::cb_sra_h(){
        cb_sra(h);
}

void CPU::cb_sra_l(){
        cb_sra(l);
}

void CPU::cb_sra_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_sra(val);
        bus->write(hl, val);
}

void CPU::cb_sra_a(){
        cb_sra(a);
}

void CPU::cb_swap_b(){
        cb_swap(b);
}

void CPU::cb_swap_c(){
        cb_swap(c);
}

void CPU::cb_swap_d(){
        cb_swap(d);
}

void CPU::cb_swap_e(){
        cb_swap(e);
}

void CPU::cb_swap_h(){
        cb_swap(h);
}

void CPU::cb_swap_l(){
        cb_swap(l);
}

void CPU::cb_swap_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_swap(val);
        bus->write(hl, val);
}

void CPU::cb_swap_a(){
        cb_swap(a);
}

void CPU::cb_srl_b(){
        cb_srl(b);
}

void CPU::cb_srl_c(){
        cb_srl(c);
}

void CPU::cb_srl_d(){
        cb_srl(d);
}

void CPU::cb_srl_e(){
        cb_srl(e);
}

void CPU::cb_srl_h(){
        cb_srl(h);
}

void CPU::cb_srl_l(){
        cb_srl(l);
}

void CPU::cb_srl_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_srl(val);
        bus->write(hl, val);
}

void CPU::cb_srl_a(){
        cb_srl(a);
}

void CPU::cb_bit_0_b(){
        cb_bit(b, 0);
}

void CPU::cb_bit_0_c(){
        cb_bit(c, 0);
}

void CPU::cb_bit_0_d(){
        cb_bit(d, 0);
}

void CPU::cb_bit_0_e(){
        cb_bit(e, 0);
}

void CPU::cb_bit_0_h(){
        cb_bit(h, 0);
}

void CPU::cb_bit_0_l(){
        cb_bit(l, 0);
}

void CPU::cb_bit_0_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 0);
}

void CPU::cb_bit_0_a(){
        cb_bit(a, 0);
}

void CPU::cb_bit_1_b(){
        cb_bit(b, 1);
}

void CPU::cb_bit_1_c(){
        cb_bit(c, 1);
}

void CPU::cb_bit_1_d(){
        cb_bit(d, 1);
}

void CPU::cb_bit_1_e(){
        cb_bit(e, 1);
}

void CPU::cb_bit_1_h(){
        cb_bit(h, 1);
}

void CPU::cb_bit_1_l(){
        cb_bit(l, 1);
}

void CPU::cb_bit_1_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 1);
}

void CPU::cb_bit_1_a(){
        cb_bit(a, 1);
}

void CPU::cb_bit_2_b(){
        cb_bit(b, 2);
}

void CPU::cb_bit_2_c(){
        cb_bit(c, 2);
}

void CPU::cb_bit_2_d(){
        cb_bit(d, 2);
}

void CPU::cb_bit_2_e(){
        cb_bit(e, 2);
}

void CPU::cb_bit_2_h(){
        cb_bit(h, 2);
}

void CPU::cb_bit_2_l(){
        cb_bit(l, 2);
}

void CPU::cb_bit_2_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 2);
}

void CPU::cb_bit_2_a(){
        cb_bit(a, 2);
}

void CPU::cb_bit_3_b(){
        cb_bit(b, 3);
}

void CPU::cb_bit_3_c(){
        cb_bit(c, 3);
}

void CPU::cb_bit_3_d(){
        cb_bit(d, 3);
}

void CPU::cb_bit_3_e(){
        cb_bit(e, 3);
}

void CPU::cb_bit_3_h(){
        cb_bit(h, 3);
}

void CPU::cb_bit_3_l(){
        cb_bit(l, 3);
}

void CPU::cb_bit_3_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 3);
}

void CPU::cb_bit_3_a(){
        cb_bit(a, 3);
}

void CPU::cb_bit_4_b(){
        cb_bit(b, 4);
}

void CPU::cb_bit_4_c(){
        cb_bit(c, 4);
}

void CPU::cb_bit_4_d(){
        cb_bit(d, 4);
}

void CPU::cb_bit_4_e(){
        cb_bit(e, 4);
}

void CPU::cb_bit_4_h(){
        cb_bit(h, 4);
}

void CPU::cb_bit_4_l(){
        cb_bit(l, 4);
}

void CPU::cb_bit_4_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 4);
}

void CPU::cb_bit_4_a(){
        cb_bit(a, 4);
}

void CPU::cb_bit_5_b(){
        cb_bit(b, 5);
}

void CPU::cb_bit_5_c(){
        cb_bit(c, 5);
}

void CPU::cb_bit_5_d(){
        cb_bit(d, 5);
}

void CPU::cb_bit_5_e(){
        cb_bit(e, 5);
}

void CPU::cb_bit_5_h(){
        cb_bit(h, 5);
}

void CPU::cb_bit_5_l(){
        cb_bit(l, 5);
}

void CPU::cb_bit_5_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 5);
}

void CPU::cb_bit_5_a(){
        cb_bit(a, 5);
}

void CPU::cb_bit_6_b(){
        cb_bit(b, 6);
}

void CPU::cb_bit_6_c(){
        cb_bit(c, 6);
}

void CPU::cb_bit_6_d(){
        cb_bit(d, 6);
}

void CPU::cb_bit_6_e(){
        cb_bit(e, 6);
}

void CPU::cb_bit_6_h(){
        cb_bit(h, 6);
}

void CPU::cb_bit_6_l(){
        cb_bit(l, 6);
}

void CPU::cb_bit_6_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 6);
}

void CPU::cb_bit_6_a(){
        cb_bit(a, 6);
}

void CPU::cb_bit_7_b(){
        cb_bit(b, 7);
}

void CPU::cb_bit_7_c(){
        cb_bit(c, 7);
}

void CPU::cb_bit_7_d(){
        cb_bit(d, 7);
}

void CPU::cb_bit_7_e(){
        cb_bit(e, 7);
}

void CPU::cb_bit_7_h(){
        cb_bit(h, 7);
}

void CPU::cb_bit_7_l(){
        cb_bit(l, 7);
}

void CPU::cb_bit_7_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_bit(val, 7);
}

void CPU::cb_bit_7_a(){
        cb_bit(a, 7);
}

void CPU::cb_res_0_b(){
        cb_res(b, 0);
}

void CPU::cb_res_0_c(){
        cb_res(c, 0);
}

void CPU::cb_res_0_d(){
        cb_res(d, 0);
}

void CPU::cb_res_0_e(){
        cb_res(e, 0);
}

void CPU::cb_res_0_h(){
        cb_res(h, 0);
}

void CPU::cb_res_0_l(){
        cb_res(l, 0);
}

void CPU::cb_res_0_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 0);
        bus->write(hl, val);
}

void CPU::cb_res_0_a(){
        cb_res(a, 0);
}

void CPU::cb_res_1_b(){
        cb_res(b, 1);
}

void CPU::cb_res_1_c(){
        cb_res(c, 1);
}

void CPU::cb_res_1_d(){
        cb_res(d, 1);
}

void CPU::cb_res_1_e(){
        cb_res(e, 1);
}

void CPU::cb_res_1_h(){
        cb_res(h, 1);
}

void CPU::cb_res_1_l(){
        cb_res(l, 1);
}

void CPU::cb_res_1_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 1);
        bus->write(hl, val);
}

void CPU::cb_res_1_a(){
        cb_res(a, 1);
}

void CPU::cb_res_2_b(){
        cb_res(b, 2);
}

void CPU::cb_res_2_c(){
        cb_res(c, 2);
}

void CPU::cb_res_2_d(){
        cb_res(d, 2);
}

void CPU::cb_res_2_e(){
        cb_res(e, 2);
}

void CPU::cb_res_2_h(){
        cb_res(h, 2);
}

void CPU::cb_res_2_l(){
        cb_res(l, 2);
}

void CPU::cb_res_2_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 2);
        bus->write(hl, val);
}

void CPU::cb_res_2_a(){
        cb_res(a, 2);
}

void CPU::cb_res_3_b(){
        cb_res(b, 3);
}

void CPU::cb_res_3_c(){
        cb_res(c, 3);
}

void CPU::cb_res_3_d(){
        cb_res(d, 3);
}

void CPU::cb_res_3_e(){
        cb_res(e, 3);
}

void CPU::cb_res_3_h(){
        cb_res(h, 3);
}

void CPU::cb_res_3_l(){
        cb_res(l, 3);
}

void CPU::cb_res_3_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 3);
        bus->write(hl, val);
}

void CPU::cb_res_3_a(){
        cb_res(a, 3);
}

void CPU::cb_res_4_b(){
        cb_res(b, 4);
}

void CPU::cb_res_4_c(){
        cb_res(c, 4);
}

void CPU::cb_res_4_d(){
        cb_res(d, 4);
}

void CPU::cb_res_4_e(){
        cb_res(e, 4);
}

void CPU::cb_res_4_h(){
        cb_res(h, 4);
}

void CPU::cb_res_4_l(){
        cb_res(l, 4);
}

void CPU::cb_res_4_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 4);
        bus->write(hl, val);
}

void CPU::cb_res_4_a(){
        cb_res(a, 4);
}

void CPU::cb_res_5_b(){
        cb_res(b, 5);
}

void CPU::cb_res_5_c(){
        cb_res(c, 5);
}

void CPU::cb_res_5_d(){
        cb_res(d, 5);
}

void CPU::cb_res_5_e(){
        cb_res(e, 5);
}

void CPU::cb_res_5_h(){
        cb_res(h, 5);
}

void CPU::cb_res_5_l(){
        cb_res(l, 5);
}

void CPU::cb_res_5_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 5);
        bus->write(hl, val);
}

void CPU::cb_res_5_a(){
        cb_res(a, 5);
}

void CPU::cb_res_6_b(){
        cb_res(b, 6);
}

void CPU::cb_res_6_c(){
        cb_res(c, 6);
}

void CPU::cb_res_6_d(){
        cb_res(d, 6);
}

void CPU::cb_res_6_e(){
        cb_res(e, 6);
}

void CPU::cb_res_6_h(){
        cb_res(h, 6);
}

void CPU::cb_res_6_l(){
        cb_res(l, 6);
}

void CPU::cb_res_6_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 6);
        bus->write(hl, val);
}

void CPU::cb_res_6_a(){
        cb_res(a, 6);
}

void CPU::cb_res_7_b(){
        cb_res(b, 7);
}

void CPU::cb_res_7_c(){
        cb_res(c, 7);
}

void CPU::cb_res_7_d(){
        cb_res(d, 7);
}

void CPU::cb_res_7_e(){
        cb_res(e, 7);
}

void CPU::cb_res_7_h(){
        cb_res(h, 7);
}

void CPU::cb_res_7_l(){
        cb_res(l, 7);
}

void CPU::cb_res_7_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_res(val, 7);
        bus->write(hl, val);
}

void CPU::cb_res_7_a(){
        cb_res(a, 7);
}

void CPU::cb_set_0_b(){
        cb_set(b, 0);
}

void CPU::cb_set_0_c(){
        cb_set(c, 0);
}

void CPU::cb_set_0_d(){
        cb_set(d, 0);
}

void CPU::cb_set_0_e(){
        cb_set(e, 0);
}

void CPU::cb_set_0_h(){
        cb_set(h, 0);
}

void CPU::cb_set_0_l(){
        cb_set(l, 0);
}

void CPU::cb_set_0_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 0);
        bus->write(hl, val);
}

void CPU::cb_set_0_a(){
        cb_set(a, 0);
}

void CPU::cb_set_1_b(){
        cb_set(b, 1);
}

void CPU::cb_set_1_c(){
        cb_set(c, 1);
}

void CPU::cb_set_1_d(){
        cb_set(d, 1);
}

void CPU::cb_set_1_e(){
        cb_set(e, 1);
}

void CPU::cb_set_1_h(){
        cb_set(h, 1);
}

void CPU::cb_set_1_l(){
        cb_set(l, 1);
}

void CPU::cb_set_1_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 1);
        bus->write(hl, val);
}

void CPU::cb_set_1_a(){
        cb_set(a, 1);
}

void CPU::cb_set_2_b(){
        cb_set(b, 2);
}

void CPU::cb_set_2_c(){
        cb_set(c, 2);
}

void CPU::cb_set_2_d(){
        cb_set(d, 2);
}

void CPU::cb_set_2_e(){
        cb_set(e, 2);
}

void CPU::cb_set_2_h(){
        cb_set(h, 2);
}

void CPU::cb_set_2_l(){
        cb_set(l, 2);
}

void CPU::cb_set_2_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 2);
        bus->write(hl, val);
}

void CPU::cb_set_2_a(){
        cb_set(a, 2);
}

void CPU::cb_set_3_b(){
        cb_set(b, 3);
}

void CPU::cb_set_3_c(){
        cb_set(c, 3);
}

void CPU::cb_set_3_d(){
        cb_set(d, 3);
}

void CPU::cb_set_3_e(){
        cb_set(e, 3);
}

void CPU::cb_set_3_h(){
        cb_set(h, 3);
}

void CPU::cb_set_3_l(){
        cb_set(l, 3);
}

void CPU::cb_set_3_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 3);
        bus->write(hl, val);
}

void CPU::cb_set_3_a(){
        cb_set(a, 3);
}

void CPU::cb_set_4_b(){
        cb_set(b, 4);
}

void CPU::cb_set_4_c(){
        cb_set(c, 4);
}

void CPU::cb_set_4_d(){
        cb_set(d, 4);
}

void CPU::cb_set_4_e(){
        cb_set(e, 4);
}

void CPU::cb_set_4_h(){
        cb_set(h, 4);
}

void CPU::cb_set_4_l(){
        cb_set(l, 4);
}

void CPU::cb_set_4_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 4);
        bus->write(hl, val);
}

void CPU::cb_set_4_a(){
        cb_set(a, 4);
}

void CPU::cb_set_5_b(){
        cb_set(b, 5);
}

void CPU::cb_set_5_c(){
        cb_set(c, 5);
}

void CPU::cb_set_5_d(){
        cb_set(d, 5);
}

void CPU::cb_set_5_e(){
        cb_set(e, 5);
}

void CPU::cb_set_5_h(){
        cb_set(h, 5);
}

void CPU::cb_set_5_l(){
        cb_set(l, 5);
}

void CPU::cb_set_5_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 5);
        bus->write(hl, val);
}

void CPU::cb_set_5_a(){
        cb_set(a, 5);
}

void CPU::cb_set_6_b(){
        cb_set(b, 6);
}

void CPU::cb_set_6_c(){
        cb_set(c, 6);
}

void CPU::cb_set_6_d(){
        cb_set(d, 6);
}

void CPU::cb_set_6_e(){
        cb_set(e, 6);
}

void CPU::cb_set_6_h(){
        cb_set(h, 6);
}

void CPU::cb_set_6_l(){
        cb_set(l, 6);
}

void CPU::cb_set_6_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 6);
        bus->write(hl, val);
}

void CPU::cb_set_6_a(){
        cb_set(a, 6);
}

void CPU::cb_set_7_b(){
        cb_set(b, 7);
}

void CPU::cb_set_7_c(){
        cb_set(c, 7);
}

void CPU::cb_set_7_d(){
        cb_set(d, 7);
}

void CPU::cb_set_7_e(){
        cb_set(e, 7);
}

void CPU::cb_set_7_h(){
        cb_set(h, 7);
}

void CPU::cb_set_7_l(){
        cb_set(l, 7);
}

void CPU::cb_set_7_addr_hl(){
        std::uint8_t val{bus->read(hl)};
        cb_set(val, 7);
        bus->write(hl, val);
}

void CPU::cb_set_7_a(){
        cb_set(a, 7);
}
