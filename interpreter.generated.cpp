#include <string>
#include <cstdint>
#include <cmath>
#include "common.h"
#include "interpreter.h"
using std::string;

bool Interpreter::interpret(uint inst, ulong pc) {
	/* ADCS */
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) ((bool) (state->NZCV_C)));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) ((bool) (state->NZCV_C)));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* ADD-extended-register */
	if((inst & 0x7FE00000U) == 0x0B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_122) -> string { switch(temp_122) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_123) -> string { switch(temp_123) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (((uint) (([=](auto temp_124) -> uint { switch(temp_124) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (((uint) (([=](auto temp_125) -> uint { switch(temp_125) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_126) -> ulong { switch(temp_126) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((uint) (m)), 32)))); default: return m; } })(option))) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_127) -> ulong { switch(temp_127) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((uint) (m)), 32)))); default: return m; } })(option))) << (uint) (imm)))));
			}
		}
		return true;
	}
	/* ADD-immediate */
	if((inst & 0x7F800000U) == 0x11000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint) (((uint) ((uint) (imm))) << (uint) (shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) (simm))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) (simm))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (simm)));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (simm)));
		}
		return true;
	}
	/* ADD-shifted-register */
	if((inst & 0x7F200000U) == 0x0B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_128) -> string { switch(temp_128) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (([=](auto temp_129) -> uint { switch(temp_129) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (int) (imm))); } })(shift))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (([=](auto temp_130) -> uint { switch(temp_130) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (int) (imm))); } })(shift))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (([=](auto temp_131) -> ulong { switch(temp_131) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (([=](auto temp_132) -> ulong { switch(temp_132) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
		}
		return true;
	}
	/* ADD-vector */
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_133) -> string { switch(temp_133) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = (Vector128<float>) (([=](auto temp_134) -> Vector128<float> { switch(temp_134) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))))); case 0x3: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rm]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	/* ADDS-immediate */
	if((inst & 0x7F800000U) == 0x31000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint) (((uint) ((uint) (imm))) << (uint) (shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL))));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* ADDS-shifted-register */
	if((inst & 0x7F200000U) == 0x2B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_135) -> string { switch(temp_135) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (([=](auto temp_136) -> uint { switch(temp_136) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (([=](auto temp_137) -> ulong { switch(temp_137) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* ADR */
	if((inst & 0x9F000000U) == 0x10000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((uint) ((uint) (((uint) (((uint) (immlo)) << 0)) | ((uint) (((uint) (immhi)) << 2)))), 21));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (imm)));
		state->X[(int) rd] = addr;
		return true;
	}
	/* ADRP */
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) (immlo)) << 12)))) | ((ulong) (((ulong) (immhi)) << 14)))), 33));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) ((ulong) ((ulong) ((ulong) (((ulong) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((ulong) (long) (imm)));
		state->X[(int) rd] = addr;
		return true;
	}
	/* AND-immediate */
	if((inst & 0x7F800000U) == 0x12000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
		}
		return true;
	}
	/* AND-shifted-register */
	if((inst & 0x7F200000U) == 0x0A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_138) -> string { switch(temp_138) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (([=](auto temp_139) -> uint { switch(temp_139) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (([=](auto temp_140) -> ulong { switch(temp_140) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	/* AND-vector */
	if((inst & 0xBFE0FC00U) == 0x0E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		auto v = (Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) & reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	/* ANDS-shifted-register */
	if((inst & 0x7F200000U) == 0x6A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_141) -> string { switch(temp_141) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto result = (uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (([=](auto temp_142) -> uint { switch(temp_142) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
			state->X[(int) rd] = (ulong) (uint) (result);
			state->NZCV_N = (uint) ((result) >> (uint) (0x1F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		} else {
			auto result = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (([=](auto temp_143) -> ulong { switch(temp_143) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
			state->X[(int) rd] = result;
			state->NZCV_N = (ulong) ((result) >> (uint) (0x3F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		}
		return true;
	}
	/* ANDS-immediate */
	if((inst & 0x7F800000U) == 0x72000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto result = (uint) ((((ulong) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((ulong) (imm))));
			state->X[(int) rd] = (ulong) (uint) (result);
			state->NZCV_N = (uint) ((result) >> (uint) (0x1F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		} else {
			auto result = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
			state->X[(int) rd] = result;
			state->NZCV_N = (ulong) ((result) >> (uint) (0x3F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		}
		return true;
	}
	/* ASRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])))) >> (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])))) >> (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))))));
		}
		return true;
	}
	/* B */
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28)))));
		Branch(addr);
		return true;
	}
	/* B.cond */
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_144) -> string { switch(temp_144) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_145) -> bool { switch(temp_145) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			Branch(addr);
		} else {
			Branch(pc + 4);
		}
		return true;
	}
	/* BFM */
	if((inst & 0x7F800000U) == 0x33000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto dst = (uint) ((rd) == 31 ? 0U : (uint) state->X[(int) rd]);
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) ((((uint) (dst)) & ((uint) ((uint) (~(wmask)))))))) | ((uint) ((uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))))))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) (dst)) & ((uint) ((uint) (~(tmask)))))))) | ((uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))))))));
		} else {
			auto dst = (ulong) ((rd) == 31 ? 0UL : state->X[(int) rd]);
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) ((((ulong) (dst)) & ((ulong) ((ulong) (~(wmask)))))))) | ((ulong) ((ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))))))));
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) (dst)) & ((ulong) ((ulong) (~(tmask)))))))) | ((ulong) ((ulong) ((((ulong) (bot)) & ((ulong) (tmask))))))));
		}
		return true;
	}
	/* BIC */
	if((inst & 0x7F200000U) == 0x0A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_146) -> string { switch(temp_146) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (~((uint) (([=](auto temp_147) -> uint { switch(temp_147) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (~((ulong) (([=](auto temp_148) -> ulong { switch(temp_148) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	/* BIC-vector-register */
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto v = (Vector128<float>) (reinterpret_cast<Vector128<float>>(~(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) & reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm])))));
		if(((bool) (((Q) == (0x1)) ? 1U : 0U)) != 0) {
			state->V[rd] = v;
		} else {
			state->V[rd] = (Vector128<float>) (v);
		}
		return true;
	}
	/* BL */
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		BranchLinked(addr);
		return true;
	}
	/* BLR */
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchLinkedRegister(rn);
		return true;
	}
	/* BR */
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
	/* BRK */
	if((inst & 0xFFE0001FU) == 0xD4200000U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		Branch(-0xE0E0E0E0D0D0D0E);
		return true;
	}
	/* CASP */
	if((inst & 0xBFE0FC00U) == 0x08207C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	/* CASPA */
	if((inst & 0xBFE0FC00U) == 0x08607C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	/* CASPAL */
	if((inst & 0xBFE0FC00U) == 0x0860FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto cl = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
			auto ch = (uint) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? 0U : (uint) state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]);
			auto nl = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
			auto nh = (uint) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? 0U : (uint) state->X[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]);
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			auto data = (ulong) (*(ulong*) (address));
			if(((bool) (((data) == ((ulong) ((((ulong) ((ulong) (((ulong) ((ulong) (ch))) << (uint) (0x20)))) | ((ulong) ((ulong) ((ulong) (cl)))))))) ? 1U : 0U)) != 0) {
				*(ulong*) (address) = (ulong) ((((ulong) ((ulong) (((ulong) ((ulong) (nh))) << (uint) (0x20)))) | ((ulong) ((ulong) ((ulong) (nl))))));
			} else {
			}
			state->X[(int) rs] = (ulong) (uint) ((uint) ((uint) (data)));
			state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = (ulong) (uint) ((uint) ((uint) ((ulong) ((data) >> (uint) (0x20)))));
		} else {
			auto cl = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
			auto ch = (ulong) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? 0UL : state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]);
			auto nl = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
			auto nh = (ulong) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? 0UL : state->X[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]);
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			auto dl = (ulong) (*(ulong*) (address));
			auto dh = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
			if(((bool) ((((bool) ((bool) (((dl) == (cl)) ? 1U : 0U))) & ((bool) ((bool) (((dh) == (ch)) ? 1U : 0U)))))) != 0) {
				*(ulong*) (address) = nl;
				*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = nh;
			} else {
			}
			state->X[(int) rs] = dl;
			state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = dh;
		}
		return true;
	}
	/* CASPL */
	if((inst & 0xBFE0FC00U) == 0x0820FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	/* CBNZ */
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(((bool) ((((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])) != ((uint) ((uint) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		} else {
			if(((bool) ((((ulong) ((rs) == 31 ? 0UL : state->X[(int) rs])) != ((ulong) ((ulong) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		}
		return true;
	}
	/* CBZ */
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(((bool) ((((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])) == ((uint) ((uint) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		} else {
			if(((bool) ((((ulong) ((rs) == 31 ? 0UL : state->X[(int) rs])) == ((ulong) ((ulong) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		}
		return true;
	}
	/* CCMN-immediate */
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_149) -> string { switch(temp_149) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_150) -> bool { switch(temp_150) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) ((uint) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) ((ulong) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	/* CCMP-immediate */
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_151) -> string { switch(temp_151) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_152) -> bool { switch(temp_152) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	/* CCMP-register */
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_153) -> string { switch(temp_153) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_154) -> bool { switch(temp_154) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	/* CLREX */
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return true;
	}
	/* CLZ */
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (CountLeadingZeros((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (CountLeadingZeros((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		}
		return true;
	}
	/* CNT */
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_155) -> string { switch(temp_155) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		state->V[rd] = (Vector128<float>) (VectorCountBits((Vector128<float>) (state->V[rn]), (long) (([=](auto temp_156) -> long { switch(temp_156) { case 0x0: return 0x8; default: return 0x10; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))))));
		return true;
	}
	/* CSEL */
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_157) -> string { switch(temp_157) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_158) -> bool { switch(temp_158) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]));
			} else {
				state->X[(int) rd] = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			}
		}
		return true;
	}
	/* CSINC */
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_159) -> string { switch(temp_159) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_160) -> bool { switch(temp_160) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) + ((uint) (uint) ((uint) ((uint) (0x1))))));
			} else {
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) + ((ulong) (long) (0x1)));
			}
		}
		return true;
	}
	/* CSINV */
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_161) -> string { switch(temp_161) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_162) -> bool { switch(temp_162) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))));
			} else {
				state->X[(int) rd] = (ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])));
			}
		}
		return true;
	}
	/* CSNEG */
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_163) -> string { switch(temp_163) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_164) -> bool { switch(temp_164) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (-((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))))))));
			} else {
				state->X[(int) rd] = (ulong) ((ulong) ((long) (-((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))));
			}
		}
		return true;
	}
	/* DMB */
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_165) -> string { switch(temp_165) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return true;
	}
	/* DSB */
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_166) -> string { switch(temp_166) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return true;
	}
	/* DUP-general */
	if((inst & 0xBFE0FC00U) == 0x0E000C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto size = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((long) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x8)) ? 1U : 0U) != 0) ? (0x40) : (0x20)));
		auto r = (string) (((bool) (((size) == (0x40)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto T = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("16B")) : (string("8B")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("8H")) : (string("4H")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("4S")) : (string("2S")))) : ((string) ((Q != 0) ? (string("2D")) : throw "Not implemented"))))))));
		auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
		state->V[rd] = (Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (src))) - (Vector128<byte>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (src))) - (Vector128<byte>) {})))))) : ((Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) ((ushort) (src))) - (Vector128<ushort>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) ((ushort) (src))) - (Vector128<ushort>) {})))))) : ((Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((uint) ((uint) (src))) - (Vector128<uint>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((uint) ((uint) (src))) - (Vector128<uint>) {})))))) : ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>((src) - (Vector128<ulong>) {}))) : throw "Not implemented")))))));
		return true;
	}
	/* DUP-element-scalar */
	if((inst & 0xFFE0FC00U) == 0x5E000400U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = string("");
		auto size = 0x0;
		auto index = (uint) ((uint) (0x0));
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				r = string("B");
				size = 0x8;
				index = (byte) ((imm) >> (uint) (0x1));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					r = string("H");
					size = 0x10;
					index = (byte) ((imm) >> (uint) (0x2));
				} else {
					if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						r = string("S");
						size = 0x20;
						index = (byte) ((imm) >> (uint) (0x3));
					} else {
						r = string("D");
						size = 0x40;
						index = (byte) ((imm) >> (uint) (0x4));
					}
				}
			}
		}
		switch(size) {
			case 0x8: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn]))[index]), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x10: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[index]), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x20: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[index]), 0, 0, 0 };
				break;
			}
			case 0x40: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[index]), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* EON-shifted-register */
	if((inst & 0x7F200000U) == 0x4A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_167) -> string { switch(temp_167) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) (~((uint) (([=](auto temp_168) -> uint { switch(temp_168) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) ((ulong) (~((ulong) (([=](auto temp_169) -> ulong { switch(temp_169) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	/* EOR-immediate */
	if((inst & 0x7F800000U) == 0x52000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) (imm))));
		}
		return true;
	}
	/* EOR-shifted-register */
	if((inst & 0x7F200000U) == 0x4A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_170) -> string { switch(temp_170) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) (([=](auto temp_171) -> uint { switch(temp_171) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) ((ulong) (([=](auto temp_172) -> ulong { switch(temp_172) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	/* EXT */
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		state->V[rd] = (Vector128<float>) (VectorExtract((Vector128<float>) (state->V[rn]), (Vector128<float>) (state->V[rm]), Q, index));
		return true;
	}
	/* EXTR */
	if((inst & 0x7FA00000U) == 0x13800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto o = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto lsb = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (uint) ((ulong) (((ulong) (long) (0x20)) - ((ulong) (byte) (lsb))))))) | ((uint) ((uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (lsb)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (uint) ((ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (lsb))))))) | ((ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (lsb))))));
		}
		return true;
	}
	/* FABS-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_173) -> string { switch(temp_173) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (fabs((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (fabs((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FABS-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_174) -> string { switch(temp_174) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (fabs(a));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (fabs(b));
				break;
			}
			case 0x1: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (fabs(a));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (fabs(b));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (fabs(c));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (fabs(d));
				break;
			}
			case 0x3: {
				auto a = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x0))) - (Vector128<double>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (fabs(a));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (fabs(b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADD-scalar */
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_175) -> string { switch(temp_175) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))) + ((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rm])[0])))))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) + ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADD-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_176) -> string { switch(temp_176) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) + ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) + ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADDP-scalar */
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]))) + ((float) (float) ((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1])))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1])))), 0 });
		}
		return true;
	}
	/* FADDP-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_177) -> string { switch(temp_177) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((float) (float) (a)) + ((float) (float) (b)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((float) (float) (c)) + ((float) (float) (d)));
				break;
			}
			case 0x1: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				auto e = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto f = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				auto g = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x2]);
				auto h = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((float) (float) (a)) + ((float) (float) (b)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((float) (float) (c)) + ((float) (float) (d)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (((float) (float) (e)) + ((float) (float) (f)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (((float) (float) (g)) + ((float) (float) (h)));
				break;
			}
			case 0x3: {
				auto a = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto d = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (((double) (double) (a)) + ((double) (double) (b)));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (((double) (double) (c)) + ((double) (double) (d)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCCMP */
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_178) -> string { switch(temp_178) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_179) -> string { switch(temp_179) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_180) -> bool { switch(temp_180) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			switch(type) {
				case 0x0: {
					auto __macro_fcmp_a = (float) (state->V[rn][0]);
					auto __macro_fcmp_b = (float) (state->V[rm][0]);
					NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
					break;
				}
				case 0x1: {
					auto __macro_fcmp_a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
					auto __macro_fcmp_b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
					NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	/* FCMxx-register-vector */
	if((inst & 0x9F20F400U) == 0x0E20E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto E = (inst >> 23) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ac = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_181) -> string { switch(temp_181) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
		auto t = (string) (([=](auto temp_182) -> string { switch(temp_182) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto b1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_183) -> float { switch(temp_183) { case 0x0: return (float) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a1))) >= ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a1))) > ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_184) -> float { switch(temp_184) { case 0x0: return (float) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a2))) >= ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a2))) > ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			case 0x1: {
				auto a1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto a3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto a4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				auto b1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				auto b3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x2]);
				auto b4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_185) -> float { switch(temp_185) { case 0x0: return (float) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a1))) >= ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a1))) > ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_186) -> float { switch(temp_186) { case 0x0: return (float) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a2))) >= ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a2))) > ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (([=](auto temp_187) -> float { switch(temp_187) { case 0x0: return (float) (((bool) (((a3) == (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a3) >= (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a3))) >= ((float) (fabs(b3)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a3) > (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a3))) > ((float) (fabs(b3)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (([=](auto temp_188) -> float { switch(temp_188) { case 0x0: return (float) (((bool) (((a4) == (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a4) >= (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a4))) >= ((float) (fabs(b4)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a4) > (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a4))) > ((float) (fabs(b4)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			case 0x3: {
				auto a1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto b1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (([=](auto temp_189) -> double { switch(temp_189) { case 0x0: return (double) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x3: return (double) (((bool) ((((double) (fabs(a1))) >= ((double) (fabs(b1)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x6: return (double) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x7: return (double) (((bool) ((((double) (fabs(a1))) > ((double) (fabs(b1)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (([=](auto temp_190) -> double { switch(temp_190) { case 0x0: return (double) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x3: return (double) (((bool) ((((double) (fabs(a2))) >= ((double) (fabs(b2)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x6: return (double) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x7: return (double) (((bool) ((((double) (fabs(a2))) > ((double) (fabs(b2)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMxx-zero-vector */
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_191) -> string { switch(temp_191) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
		auto t = (string) (([=](auto temp_192) -> string { switch(temp_192) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_193) -> float { switch(temp_193) { case 0x0: return (float) (((bool) (((v1) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v1) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v1) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v1) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_194) -> float { switch(temp_194) { case 0x0: return (float) (((bool) (((v2) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v2) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v2) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v2) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			case 0x1: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto v3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto v4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_195) -> float { switch(temp_195) { case 0x0: return (float) (((bool) (((v1) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v1) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v1) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v1) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_196) -> float { switch(temp_196) { case 0x0: return (float) (((bool) (((v2) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v2) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v2) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v2) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (([=](auto temp_197) -> float { switch(temp_197) { case 0x0: return (float) (((bool) (((v3) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v3) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v3) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v3) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (([=](auto temp_198) -> float { switch(temp_198) { case 0x0: return (float) (((bool) (((v4) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v4) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v4) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v4) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			case 0x3: {
				auto v1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (([=](auto temp_199) -> double { switch(temp_199) { case 0x0: return (double) (((bool) (((v1) > ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x1: return (double) (((bool) (((v1) >= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((v1) == ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: return (double) (((bool) (((v1) <= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (([=](auto temp_200) -> double { switch(temp_200) { case 0x0: return (double) (((bool) (((v2) > ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x1: return (double) (((bool) (((v2) >= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((v2) == ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: return (double) (((bool) (((v2) <= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMLT-zero-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_201) -> string { switch(temp_201) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((bool) (((v1) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((bool) (((v2) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				break;
			}
			case 0x1: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto v3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto v4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((bool) (((v1) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((bool) (((v2) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (((bool) (((v3) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (((bool) (((v4) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				break;
			}
			case 0x3: {
				auto v1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (((bool) (((v1) < ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (((bool) (((v2) < ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMP */
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_202) -> string { switch(temp_202) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		switch(type) {
			case 0x0: {
				auto __macro_fcmp_a = (float) (state->V[rn][0]);
				auto __macro_fcmp_b = (float) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? ((float) ((float) (0x0))) : ((float) (state->V[rm][0])));
				NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
				break;
			}
			case 0x1: {
				auto __macro_fcmp_a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto __macro_fcmp_b = (double) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? ((double) ((double) (0x0))) : ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])));
				NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCSEL */
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_203) -> string { switch(temp_203) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_204) -> string { switch(temp_204) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_205) -> bool { switch(temp_205) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			switch(type) {
				case 0x0: {
					state->V[(int) (rd)] = (Vector128<float>) { (float) (state->V[rn][0]), 0, 0, 0 };
					break;
				}
				case 0x1: {
					state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), 0 });
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		} else {
			switch(type) {
				case 0x0: {
					state->V[(int) (rd)] = (Vector128<float>) { (float) (state->V[rm][0]), 0, 0, 0 };
					break;
				}
				case 0x1: {
					state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]), 0 });
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		}
		return true;
	}
	/* FCVT */
	if((inst & 0xFF3E7C00U) == 0x1E224000U) {
		auto type = (inst >> 22) & 0x3U;
		auto opc = (inst >> 15) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = string("");
		auto r2 = string("");
		auto tf = (byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (type)) << 2))));
		switch(tf) {
			case 0xC: {
				r1 = string("S");
				r2 = string("H");
				break;
			}
			case 0xD: {
				r1 = string("D");
				r2 = string("H");
				break;
			}
			case 0x3: {
				r1 = string("H");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("S");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("D");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(tf) {
			case 0xC: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))), 0, 0, 0 };
				break;
			}
			case 0xD: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))), 0 });
				break;
			}
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((float) (state->V[rn][0]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((float) (state->V[rn][0]))), 0 });
				break;
			}
			case 0x7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0, 0, 0 };
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTL[2] */
	if((inst & 0xBFBFFC00U) == 0x0E217800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = (string) ((size != 0) ? (string("2D")) : (string("4S")));
		auto tb = (string) (([=](auto temp_206) -> string { switch(temp_206) { case 0x0: return string("4H"); case 0x1: return string("8H"); case 0x2: return string("2S"); default: return string("4S"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x2: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x2])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x3])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZS-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E180000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_207) -> string { switch(temp_207) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((float) (state->V[rn][0]), (int) (fbits))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((float) (state->V[rn][0]), (int) (fbits)));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E380000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((float) (state->V[rn][0]))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((float) (state->V[rn][0])))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZU-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E190000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_208) -> string { switch(temp_208) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((float) (state->V[rn][0]), (int) (fbits))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((float) (state->V[rn][0]), (int) (fbits)));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E390000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((float) (state->V[rn][0]))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((float) (state->V[rn][0])));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FDIV-scalar */
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_209) -> string { switch(temp_209) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				throw "Not implemented";
				break;
			}
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) / ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) / ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FDIV-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_210) -> string { switch(temp_210) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) / ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) / ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) / reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMADD */
	if((inst & 0xFF208000U) == 0x1F000000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_211) -> string { switch(temp_211) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))) + ((float) (float) ((float) (state->V[ra][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[ra])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMAX-scalar */
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_212) -> string { switch(temp_212) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMAXNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_213) -> string { switch(temp_213) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMIN-scalar */
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_214) -> string { switch(temp_214) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMINNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_215) -> string { switch(temp_215) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMLA-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F801000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_216) -> string { switch(temp_216) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_217) -> uint { switch(temp_217) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rd])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<double>) {}))))))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rd])) + ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<float>) {}))))));
		}
		return true;
	}
	/* FMLA-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_218) -> string { switch(temp_218) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rd])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm])))))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rd])) + ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))));
		}
		return true;
	}
	/* FMOV-general */
	if((inst & 0x7F36FC00U) == 0x1E260000U) {
		auto sf = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto mode = (inst >> 19) & 0x1U;
		auto ropc = (inst >> 16) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto opc = (byte) ((byte) (((byte) (((byte) (ropc)) << 0)) | ((byte) (((byte) ((byte) ((byte) (0x3)))) << 1))));
		auto tf = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) ((byte) ((byte) (mode)))) << 3)))) | ((byte) (((byte) (type)) << 5)))) | ((byte) (((byte) (sf)) << 7))));
		auto r1 = string("");
		auto r2 = string("");
		switch(tf) {
			case 0x66: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0xE6: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x67: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x6: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0xE7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0xA7: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			case 0xCF: {
				r1 = string("V");
				r2 = string("X");
				break;
			}
			case 0xCE: {
				r1 = string("X");
				r2 = string("V");
				break;
			}
			case 0xA6: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		auto index1 = (string) (((bool) (((r1) == (string("V"))) ? 1U : 0U) != 0) ? (string(".D[1]")) : (string("")));
		auto index2 = (string) (((bool) (((r2) == (string("V"))) ? 1U : 0U) != 0) ? (string(".D[1]")) : (string("")));
		switch(tf) {
			case 0x66: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))));
				break;
			}
			case 0xE6: {
				state->X[(int) rd] = (ulong) ((ulong) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0])));
				break;
			}
			case 0x67: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x7: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (Bitcast<uint, float>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<float, uint>((float) (state->V[rn][0]))));
				break;
			}
			case 0xE7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0xA7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			case 0xA6: {
				state->X[(int) rd] = (ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])));
				break;
			}
			case 0xCE: {
				state->X[(int) rd] = (ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[(byte) ((((ulong) ((byte) ((rn) << (uint) (0x1)))) | ((ulong) (0x1))))])[0])));
				break;
			}
			case 0xCF: {
				state->V[(int) ((byte) ((((ulong) ((byte) ((rd) << (uint) (0x1)))) | ((ulong) (0x1)))))] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMOV-scalar-immediate */
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_219) -> string { switch(temp_219) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint, float>((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((bool) ((bool) (0x0)))) << 0)) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 1)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 2)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 3)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 4)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 5)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 6)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 7)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 8)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 9)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 10)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 11)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 12)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 13)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 14)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 15)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 16)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 17)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 19)))) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 23)))) | ((uint) (((uint) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))))) << 25)))) | ((uint) (((uint) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint) (((uint) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 31))))));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { sv, 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 0)) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 1)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 2)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 3)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 4)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 5)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 6)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 7)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 8)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 9)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 10)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 11)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 12)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 13)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 14)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 15)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 16)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 17)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 18)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 19)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 20)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 21)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 22)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 23)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 24)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 25)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 26)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 27)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 28)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 29)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 30)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 31)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 32)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 33)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 34)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 35)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 36)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 37)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 38)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 39)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 40)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 41)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 42)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 43)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 44)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 45)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 46)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 47)))))) << 0)) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 48)))) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 52)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 5)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 6)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 7)))))) << 54)))) | ((ulong) (((ulong) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 62)))) | ((ulong) (((ulong) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 63)))))), 0 });
				break;
			}
		}
		return true;
	}
	/* FMOV-vector-immediate-single */
	if((inst & 0xBFF8FC00U) == 0x0F00F400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto sv = (float) (Bitcast<uint, float>((uint) ((((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (0x0)))) << 0)) | ((uint) (((uint) (h)) << 19)))) | ((uint) (((uint) (g)) << 20)))) | ((uint) (((uint) (f)) << 21)))) | ((uint) (((uint) (e)) << 22)))) | ((uint) (((uint) (d)) << 23)))) | ((uint) (((uint) (c)) << 24)))) | ((uint) (((uint) (b)) << 25)))) | ((uint) (((uint) (b)) << 26)))) | ((uint) (((uint) (b)) << 27)))) | ((uint) (((uint) (b)) << 28)))) | ((uint) (((uint) (b)) << 29)))) | ((uint) (((uint) (b)) << 30)))) | ((uint) (((uint) (a)) << 31)))))) ^ ((uint) ((uint) (((uint) ((uint) (0x1))) << (uint) (0x1E))))))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>((sv) - (Vector128<float>) {}));
		if((Q) != 0) {
			state->V[rd] = avec;
		} else {
			state->V[rd] = (Vector128<float>) (avec);
		}
		return true;
	}
	/* FMOV-vector-immediate-double */
	if((inst & 0xFFF8FC00U) == 0x6F00F400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto sv = (double) (Bitcast<ulong, double>((ulong) ((((ulong) ((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ulong) ((ulong) (0x0)))) << 0)) | ((ulong) (((ulong) (h)) << 48)))) | ((ulong) (((ulong) (g)) << 49)))) | ((ulong) (((ulong) (f)) << 50)))) | ((ulong) (((ulong) (e)) << 51)))) | ((ulong) (((ulong) (d)) << 52)))) | ((ulong) (((ulong) (c)) << 53)))) | ((ulong) (((ulong) (b)) << 54)))) | ((ulong) (((ulong) (b)) << 55)))) | ((ulong) (((ulong) (b)) << 56)))) | ((ulong) (((ulong) (b)) << 57)))) | ((ulong) (((ulong) (b)) << 58)))) | ((ulong) (((ulong) (b)) << 59)))) | ((ulong) (((ulong) (b)) << 60)))) | ((ulong) (((ulong) (b)) << 61)))) | ((ulong) (((ulong) (b)) << 62)))) | ((ulong) (((ulong) (a)) << 63)))))) ^ ((ulong) ((ulong) (((ulong) ((ulong) (0x1))) << (uint) (0x3E))))))));
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>((sv) - (Vector128<double>) {}));
		return true;
	}
	/* FMUL-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F809000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_220) -> string { switch(temp_220) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_221) -> uint { switch(temp_221) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<double>) {})))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<float>) {}))));
		}
		return true;
	}
	/* FMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_222) -> string { switch(temp_222) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMUL-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_223) -> string { switch(temp_223) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FNEG */
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_224) -> string { switch(temp_224) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (-((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (-((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FNMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_225) -> string { switch(temp_225) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (-((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (-((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FRINTA-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E264000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_226) -> string { switch(temp_226) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (roundf((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (round((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FRINTM-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E254000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_227) -> string { switch(temp_227) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (ceilf(((float) (state->V[rn][0])) - 0.5f)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (ceil(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) - 0.5)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FRINTP-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E24C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_228) -> string { switch(temp_228) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (floorf(((float) (state->V[rn][0])) + 0.5f)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (floor(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) + 0.5)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FRSQRTE-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_229) -> string { switch(temp_229) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		state->V[rd] = (Vector128<float>) (([=](auto temp_230) -> Vector128<float> { switch(temp_230) { case 0x0: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x20, 0x2)); case 0x1: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x20, 0x4)); case 0x3: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x40, 0x2)); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return true;
	}
	/* FRSQRTS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_231) -> string { switch(temp_231) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x3))) - (Vector128<float>) {}))) - ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))))) / ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x2))) - (Vector128<float>) {})))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x3))) - (Vector128<float>) {}))) - ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))))) / ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x2))) - (Vector128<float>) {}))));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x3))) - (Vector128<double>) {}))) - reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm])))))))) / reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x2))) - (Vector128<double>) {})))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FSQRT-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_232) -> string { switch(temp_232) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) sqrt((double) ((float) (state->V[rn][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) sqrt((double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FSUB-scalar */
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_233) -> string { switch(temp_233) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) - ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) - ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* INS-general */
	if((inst & 0xFFE0FC00U) == 0x4E001C00U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index = (uint) ((uint) (0x0));
		auto r = string("W");
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index = (byte) ((imm) >> (uint) (0x1));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index = (byte) ((imm) >> (uint) (0x2));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index = (byte) ((imm) >> (uint) (0x3));
				} else {
					ts = string("D");
					index = (byte) ((imm) >> (uint) (0x4));
					r = string("X");
				}
			}
		}
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][index] = (byte) ((byte) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][index] = (ushort) ((ushort) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][index] = (float) (Bitcast<uint, float>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
				} else {
					reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][index] = (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
				}
			}
		}
		return true;
	}
	/* INS-vector */
	if((inst & 0xFFE08400U) == 0x6E000400U) {
		auto imm5 = (inst >> 16) & 0x1FU;
		auto imm4 = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index1 = (uint) ((uint) (0x0));
		auto index2 = (uint) ((uint) (0x0));
		if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index1 = (byte) ((imm5) >> (uint) (0x1));
			index2 = imm4;
		} else {
			if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index1 = (byte) ((imm5) >> (uint) (0x2));
				index2 = (byte) ((imm4) >> (uint) (0x1));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index1 = (byte) ((imm5) >> (uint) (0x3));
					index2 = (byte) ((imm4) >> (uint) (0x2));
				} else {
					ts = string("D");
					index1 = (byte) ((imm5) >> (uint) (0x4));
					index2 = (byte) ((imm4) >> (uint) (0x3));
				}
			}
		}
		if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][index1] = (byte) (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn]))[index2]);
		} else {
			if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][index1] = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[index2]);
			} else {
				if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][index1] = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[index2]);
				} else {
					reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][index1] = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[index2]);
				}
			}
		}
		return true;
	}
	/* LDAR */
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) (address)));
		} else {
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			state->X[(int) rt] = (ulong) (*(ulong*) (address));
		}
		return true;
	}
	/* LDARB */
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (*(byte*) (address))));
		return true;
	}
	/* LDARH */
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		return true;
	}
	/* LDAXB */
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (state->Exclusive32 = *(uint*) (address)));
		} else {
			state->X[(int) rt] = (ulong) (state->Exclusive64 = *(ulong*) (address));
		}
		return true;
	}
	/* LDAXRB */
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (state->Exclusive8 = *(byte*) (address))));
		return true;
	}
	/* LDAXRH */
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (state->Exclusive16 = *(ushort*) (address))));
		return true;
	}
	/* LDP-immediate-postindex */
	if((inst & 0x7FC00000U) == 0x28C00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt1] = (ulong) (uint) ((uint) (*(uint*) (address)));
			state->X[(int) rt2] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))));
		} else {
			state->X[(int) rt1] = (ulong) (*(ulong*) (address));
			state->X[(int) rt2] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* LDP-immediate-signed-offset */
	if((inst & 0x7FC00000U) == 0x29400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt1] = (ulong) (uint) ((uint) (*(uint*) (address)));
			state->X[(int) rt2] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))));
		} else {
			state->X[(int) rt1] = (ulong) (*(ulong*) (address));
			state->X[(int) rt2] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
		}
		return true;
	}
	/* LDP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_234) -> string { switch(temp_234) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_235) -> long { switch(temp_235) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch(opc) {
			case 0x0: {
				state->V[(int) (rt1)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				state->V[(int) (rt2)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt1)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				state->V[(int) (rt2)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8))))), 0 });
				break;
			}
			default: {
				state->V[rt1] = (Vector128<float>) (LoadVector(address));
				state->V[rt2] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* LDP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_236) -> string { switch(temp_236) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_237) -> long { switch(temp_237) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				state->V[(int) (rt1)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				state->V[(int) (rt2)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt1)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				state->V[(int) (rt2)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8))))), 0 });
				break;
			}
			default: {
				state->V[rt1] = (Vector128<float>) (LoadVector(address));
				state->V[rt2] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))));
				break;
			}
		}
		return true;
	}
	/* LDPSW-immediate-signed-offset */
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) (0x2));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		state->X[(int) rt1] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		state->X[(int) rt2] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 32))));
		return true;
	}
	/* LDR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) (address)));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) (address));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))));
		}
		return true;
	}
	/* LDR-literal */
	if((inst & 0xBF000000U) == 0x18000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>((uint) ((uint) ((uint) ((rawimm) << (uint) (0x2)))), 21));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) (addr)));
		} else {
			state->X[(int) rt] = (ulong) (*(ulong*) (addr));
		}
		return true;
	}
	/* LDR-simd-immediate-postindex */
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_238) -> string { switch(temp_238) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x2: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) (address)), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* LDR-simd-immediate-preindex */
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_239) -> string { switch(temp_239) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x2: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) (address)), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDR-simd-immediate-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto ropc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto opc = (byte) ((byte) (((byte) (((byte) ((bool) ((bool) (0x1)))) << 0)) | ((byte) (((byte) (ropc)) << 1))));
		auto m = (byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_240) -> string { switch(temp_240) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint) (((uint) ((uint) (rawimm))) << (uint) ((long) (([=](auto temp_241) -> long { switch(temp_241) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		switch(m) {
			case 0x1: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x5: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x9: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0 };
				break;
			}
			case 0xD: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0 });
				break;
			}
			default: {
				state->V[rt] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm)))));
				break;
			}
		}
		return true;
	}
	/* LDR-simd-literal */
	if((inst & 0x3F000000U) == 0x1C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_242) -> string { switch(temp_242) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(size));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) (((uint) (((uint) ((byte) ((byte) (0x0)))) << 0)) | ((uint) (((uint) (imm)) << 2)))), 21)))));
		switch(size) {
			case 0x0: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (addr)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (addr)), 0 });
				break;
			}
			case 0x2: {
				state->V[rt] = (Vector128<float>) (LoadVector(addr));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* LDR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C600800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_243) -> string { switch(temp_243) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_244) -> string { switch(temp_244) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (ulong) (((ulong) (bool) (scale)) * ((ulong) (long) ((long) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((long) (([=](auto temp_245) -> long { switch(temp_245) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		auto offset = (ulong) (((ulong) (([=](auto temp_246) -> ulong { switch(temp_246) { case 0x2: return (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))); case 0x3: return (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32)))); case 0x7: return (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]); default: throw "Not implemented"; } })(option))) << (uint) (amount));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* LDR-register */
	if((inst & 0xBFE00C00U) == 0xB8600800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_247) -> string { switch(temp_247) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		} else {
			state->X[(int) rt] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))));
		}
		return true;
	}
	/* LDRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((byte) (*(byte*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((byte) (*(byte*) (address)))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))))));
		return true;
	}
	/* LDRB-register */
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_248) -> string { switch(temp_248) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) (uint) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		return true;
	}
	/* LDRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))))));
		return true;
	}
	/* LDRH-register */
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_249) -> string { switch(temp_249) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) (uint) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		return true;
	}
	/* LDRSB-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) (address)), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) (address)), 8))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDRSB-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) (address)), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) (address)), 8))));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDRSB-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 8))));
		}
		return true;
	}
	/* LDRSB-register */
	if((inst & 0xFFA00C00U) == 0x38A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_250) -> string { switch(temp_250) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 8))));
		}
		return true;
	}
	/* LDRSH-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) (address)), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) (address)), 16))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDRSH-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) (address)), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) (address)), 16))));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDRSH-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 16))));
		}
		return true;
	}
	/* LDRSH-register */
	if((inst & 0xFFA00C00U) == 0x78A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_251) -> string { switch(temp_251) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 16))));
		}
		return true;
	}
	/* LDRSW-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	/* LDRSW-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* LDRSW-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x2));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 32))));
		return true;
	}
	/* LDRSW-literal */
	if((inst & 0xFF000000U) == 0x98000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) (((uint) (((uint) ((byte) ((byte) (0x0)))) << 0)) | ((uint) (((uint) (imm)) << 2)))), 21)))));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (addr)), 32))));
		return true;
	}
	/* LDRSW-register */
	if((inst & 0xFFE00C00U) == 0xB8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0x2));
		auto extend = (string) (([=](auto temp_252) -> string { switch(temp_252) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 32))));
		return true;
	}
	/* LDUR */
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))));
		}
		return true;
	}
	/* LDURB */
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rd] = (ulong) ((ulong) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))))));
		return true;
	}
	/* LDURH */
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rd] = (ulong) ((ulong) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))))));
		return true;
	}
	/* LDURSB */
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 8)))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 8))));
		}
		return true;
	}
	/* LDURSH */
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 16)))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 16))));
		}
		return true;
	}
	/* LDURSW */
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 32))));
		return true;
	}
	/* LDUR-simd */
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_253) -> string { switch(temp_253) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
		}
		return true;
	}
	/* LDXR */
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (state->Exclusive32 = *(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))));
		} else {
			state->X[(int) rt] = (ulong) (state->Exclusive64 = *(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
		}
		return true;
	}
	/* LDXRB */
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (state->Exclusive8 = *(byte*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])))));
		return true;
	}
	/* LDXRH */
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (state->Exclusive16 = *(ushort*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])))));
		return true;
	}
	/* LSL-register */
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))));
		}
		return true;
	}
	/* LSRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) >> (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) >> (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))));
		}
		return true;
	}
	/* MADD */
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) * ((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))) + ((uint) (uint) ((uint) ((ra) == 31 ? 0U : (uint) state->X[(int) ra])))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) * ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))) + ((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))));
		}
		return true;
	}
	/* MOVI-scalar-64bit */
	if((inst & 0xFFF8FC00U) == 0x2F00E400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm8a = (byte) ((byte) ((long) ((a != 0) ? (0xFF) : (0x0))));
		auto imm8b = (byte) ((byte) ((long) ((b != 0) ? (0xFF) : (0x0))));
		auto imm8c = (byte) ((byte) ((long) ((c != 0) ? (0xFF) : (0x0))));
		auto imm8d = (byte) ((byte) ((long) ((d != 0) ? (0xFF) : (0x0))));
		auto imm8e = (byte) ((byte) ((long) ((e != 0) ? (0xFF) : (0x0))));
		auto imm8f = (byte) ((byte) ((long) ((f != 0) ? (0xFF) : (0x0))));
		auto imm8g = (byte) ((byte) ((long) ((g != 0) ? (0xFF) : (0x0))));
		auto imm8h = (byte) ((byte) ((long) ((h != 0) ? (0xFF) : (0x0))));
		auto imm = (ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) (imm8h)) << 0)) | ((ulong) (((ulong) (imm8g)) << 8)))) | ((ulong) (((ulong) (imm8f)) << 16)))) | ((ulong) (((ulong) (imm8e)) << 24)))) | ((ulong) (((ulong) (imm8d)) << 32)))) | ((ulong) (((ulong) (imm8c)) << 40)))) | ((ulong) (((ulong) (imm8b)) << 48)))) | ((ulong) (((ulong) (imm8a)) << 56))));
		state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>(imm)), 0 });
		return true;
	}
	/* MOVI-vector-8bit */
	if((inst & 0xBFF8FC00U) == 0x0F00E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (Bitcast<uint, float>((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) (imm)) << 0)) | ((uint) (((uint) (imm)) << 8)))) | ((uint) (((uint) (imm)) << 16)))) | ((uint) (((uint) (imm)) << 24))))))) - (Vector128<float>) {}));
		if((Q) != 0) {
			state->V[rd] = avec;
		} else {
			state->V[rd] = (Vector128<float>) (avec);
		}
		return true;
	}
	/* MOVI-vector-32bit */
	if((inst & 0xBFF89C00U) == 0x0F000400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto cmode = (inst >> 13) & 0x3U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto amount = (long) (([=](auto temp_254) -> long { switch(temp_254) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (Bitcast<uint, float>((uint) (((uint) ((uint) (imm))) << (uint) (amount))))) - (Vector128<float>) {}));
		if((Q) != 0) {
			state->V[rd] = avec;
		} else {
			state->V[rd] = (Vector128<float>) (avec);
		}
		return true;
	}
	/* MOVI-Vx.2D */
	if((inst & 0xFFF8FC00U) == 0x6F00E400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (h)) << 1)))) | ((byte) (((byte) (h)) << 2)))) | ((byte) (((byte) (h)) << 3)))) | ((byte) (((byte) (h)) << 4)))) | ((byte) (((byte) (h)) << 5)))) | ((byte) (((byte) (h)) << 6)))) | ((byte) (((byte) (h)) << 7)))))) << 0)) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (g)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (g)) << 2)))) | ((byte) (((byte) (g)) << 3)))) | ((byte) (((byte) (g)) << 4)))) | ((byte) (((byte) (g)) << 5)))) | ((byte) (((byte) (g)) << 6)))) | ((byte) (((byte) (g)) << 7)))))) << 8)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (f)) << 0)) | ((byte) (((byte) (f)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (f)) << 3)))) | ((byte) (((byte) (f)) << 4)))) | ((byte) (((byte) (f)) << 5)))) | ((byte) (((byte) (f)) << 6)))) | ((byte) (((byte) (f)) << 7)))))) << 16)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (e)) << 0)) | ((byte) (((byte) (e)) << 1)))) | ((byte) (((byte) (e)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (e)) << 4)))) | ((byte) (((byte) (e)) << 5)))) | ((byte) (((byte) (e)) << 6)))) | ((byte) (((byte) (e)) << 7)))))) << 24)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (d)) << 0)) | ((byte) (((byte) (d)) << 1)))) | ((byte) (((byte) (d)) << 2)))) | ((byte) (((byte) (d)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (d)) << 5)))) | ((byte) (((byte) (d)) << 6)))) | ((byte) (((byte) (d)) << 7)))))) << 32)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (c)) << 0)) | ((byte) (((byte) (c)) << 1)))) | ((byte) (((byte) (c)) << 2)))) | ((byte) (((byte) (c)) << 3)))) | ((byte) (((byte) (c)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (c)) << 6)))) | ((byte) (((byte) (c)) << 7)))))) << 40)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (b)) << 0)) | ((byte) (((byte) (b)) << 1)))) | ((byte) (((byte) (b)) << 2)))) | ((byte) (((byte) (b)) << 3)))) | ((byte) (((byte) (b)) << 4)))) | ((byte) (((byte) (b)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (b)) << 7)))))) << 48)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (a)) << 0)) | ((byte) (((byte) (a)) << 1)))) | ((byte) (((byte) (a)) << 2)))) | ((byte) (((byte) (a)) << 3)))) | ((byte) (((byte) (a)) << 4)))) | ((byte) (((byte) (a)) << 5)))) | ((byte) (((byte) (a)) << 6)))) | ((byte) (((byte) (a)) << 7)))))) << 56))));
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>((imm) - (Vector128<ulong>) {}));
		return true;
	}
	/* MOVK */
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) ((uint) ((rd) == 31 ? 0U : (uint) state->X[(int) rd]))) & ((uint) ((uint) ((((uint) ((uint) ((uint) (-0x1)))) ^ ((uint) ((uint) (((uint) ((uint) (0xFFFF))) << (uint) (shift)))))))))))) | ((uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) ((ulong) ((rd) == 31 ? 0UL : state->X[(int) rd]))) & ((ulong) ((ulong) ((((ulong) ((ulong) ((ulong) (-0x1)))) ^ ((ulong) ((ulong) (((ulong) ((ulong) (0xFFFF))) << (uint) (shift)))))))))))) | ((ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))))));
		}
		return true;
	}
	/* MOVN */
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (~((uint) (((uint) ((uint) (imm))) << (uint) (shift)))));
		} else {
			state->X[(int) rd] = (ulong) (~((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))));
		}
		return true;
	}
	/* MOVZ */
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((ulong) (imm))) << (uint) (shift));
		}
		return true;
	}
	/* MRS */
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) (SR(op0, op1, cn, cm, op2));
		return true;
	}
	/* MSR-register */
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		SR(op0, op1, cn, cm, op2, (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]));
		return true;
	}
	/* MSUB */
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((ra) == 31 ? 0U : (uint) state->X[(int) ra]))) - ((uint) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) * ((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))) - ((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) * ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))));
		}
		return true;
	}
	/* MUL-by-element */
	if((inst & 0xBF00F400U) == 0x0F008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto L = (inst >> 21) & 0x1U;
		auto M = (inst >> 20) & 0x1U;
		auto rv = (inst >> 16) & 0xFU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto rm = (byte) (((bool) (((size) == (0x2)) ? 1U : 0U) != 0) ? ((byte) ((byte) (((byte) (((byte) (rv)) << 0)) | ((byte) (((byte) (M)) << 4))))) : (rv));
		auto t = (string) (([=](auto temp_255) -> string { switch(temp_255) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_256) -> string { switch(temp_256) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (byte) (([=](auto temp_257) -> byte { switch(temp_257) { case 0x1: return (byte) ((byte) (((byte) (byte) (((byte) (((byte) (M)) << 0)) | ((byte) (((byte) (L)) << 1)))) | ((byte) (((byte) (H)) << 2)))); case 0x2: return (byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		auto v = (Vector128<float>) (([=](auto temp_258) -> Vector128<float> { switch(temp_258) { case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) * (((ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))[index]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) * (((uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))[index]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	/* MUL-vector */
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_259) -> string { switch(temp_259) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = (Vector128<float>) (([=](auto temp_260) -> Vector128<float> { switch(temp_260) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	/* NEG-vector */
	if((inst & 0xBF3FFC00U) == 0x2E20B800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_261) -> string { switch(temp_261) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x0] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x0])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x1] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x1])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x2] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x2])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x3] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x3])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x4] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x4])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x5] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x5])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x6] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x6])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x7] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x7])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x0] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x0])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x1] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x1])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x2] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x2])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x3] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x3])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x4] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x4])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x5] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x5])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x6] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x6])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x7] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x7])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x8] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x8])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x9] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x9])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xA] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xA])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xB] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xB])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xC] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xC])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xD] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xD])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xE] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xE])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xF] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xF])));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x3])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x4] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x4])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x5] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x5])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x6] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x6])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x7] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x7])));
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				break;
			}
			case 0x5: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x3])));
				break;
			}
			case 0x7: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (-((double) (reinterpret_cast<Vector128<double>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (-((double) (reinterpret_cast<Vector128<double>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* NOP */
	if((inst & 0xFFFFFFFFU) == 0xD503201FU) {
		return true;
	}
	/* ORN-shifted-register */
	if((inst & 0x7F200000U) == 0x2A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_262) -> string { switch(temp_262) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) (~((uint) (([=](auto temp_263) -> uint { switch(temp_263) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) ((ulong) (~((ulong) (([=](auto temp_264) -> ulong { switch(temp_264) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	/* ORR-immediate */
	if((inst & 0x7F800000U) == 0x32000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) (imm))));
		}
		return true;
	}
	/* ORR-shifted-register */
	if((inst & 0x7F200000U) == 0x2A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_265) -> string { switch(temp_265) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) (([=](auto temp_266) -> uint { switch(temp_266) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) ((ulong) (([=](auto temp_267) -> ulong { switch(temp_267) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	/* ORR-simd-register */
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		if(((bool) (((rm) == (rn)) ? 1U : 0U)) != 0) {
			state->V[rd] = (Vector128<float>) (state->V[rn]);
		} else {
			throw "Not implemented";
		}
		return true;
	}
	/* PRFM-immediate */
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (ulong) (((ulong) (ushort) (imm)) * ((ulong) (long) (0x8)));
		return true;
	}
	/* RBIT */
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (ReverseBits((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (ReverseBits((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		}
		return true;
	}
	/* RET */
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
	/* REV */
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto x = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((((uint) ((uint) (((uint) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x18)))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x8))))) | ((uint) ((uint) ((((ulong) ((uint) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF)))))))));
				break;
			}
			case 0x3: {
				auto x = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
				state->X[(int) rd] = (ulong) ((((((((((ulong) ((ulong) (((ulong) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x38)))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))) << (uint) (0x30))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x28))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x20))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x20)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x28)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x30)))) & ((ulong) (0xFF))))) << (uint) (0x8))))) | ((ulong) ((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x38)))) & ((ulong) (0xFF))))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* REV16 */
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto x = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((((uint) ((uint) (((uint) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x8)))) | ((uint) ((uint) ((((ulong) ((uint) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x10)))))));
		} else {
			auto x = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			state->X[(int) rd] = (ulong) ((((((((((ulong) ((ulong) (((ulong) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x8)))) | ((ulong) ((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x20)))) & ((ulong) (0xFF))))) << (uint) (0x28))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x28)))) & ((ulong) (0xFF))))) << (uint) (0x20))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x30)))) & ((ulong) (0xFF))))) << (uint) (0x38))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x38)))) & ((ulong) (0xFF))))) << (uint) (0x30))))));
		}
		return true;
	}
	/* RORV */
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (32 - (int) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20)))))) | (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) >> (int) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (64 - (int) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))))) | (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) >> (int) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40))))));
		}
		return true;
	}
	/* SBCS */
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) ((bool) (state->NZCV_C)));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) ((bool) (state->NZCV_C)));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* SBFM */
	if((inst & 0x7F800000U) == 0x13000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))));
			auto top = (uint) (((uint) (uint) ((uint) ((uint) (0x0)))) - ((uint) (uint) ((uint) ((((ulong) ((uint) ((src) >> (uint) (imms)))) & ((ulong) (0x1)))))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) (top)) & ((uint) ((uint) (~(tmask)))))))) | ((uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))))))));
		} else {
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))));
			auto top = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (0x0)))) - ((ulong) (ulong) ((ulong) ((((ulong) ((ulong) ((src) >> (uint) (imms)))) & ((ulong) (0x1)))))));
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) (top)) & ((ulong) ((ulong) (~(tmask)))))))) | ((ulong) ((ulong) ((((ulong) (bot)) & ((ulong) (tmask))))))));
		}
		return true;
	}
	/* SCVTF-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E220000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x0: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("X");
				break;
			}
			case 0x5: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))), 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))), 0, 0, 0 };
				break;
			}
			case 0x5: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* SCVTF-scalar */
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((int) (Bitcast<float, int>((float) (state->V[rn][0]))))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((long) (Bitcast<double, long>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))), 0 });
		}
		return true;
	}
	/* SCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x0E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_268) -> string { switch(temp_268) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x1])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((long) (reinterpret_cast<Vector128<long>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((long) (reinterpret_cast<Vector128<long>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* SDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) (0x0))) : ((uint) ((uint) ((float) (((float) (float) ((float) ((float) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))))) / ((float) (float) ((float) ((float) ((int) ((int) (operand2))))))))))));
		} else {
			auto operand2 = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (0x0))) : ((ulong) ((ulong) ((double) (((double) (double) ((double) ((double) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))))) / ((double) (double) ((double) ((double) ((long) ((long) (operand2)))))))))));
		}
		return true;
	}
	/* SMADDL */
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((long) (((long) (long) ((long) ((long) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))))) + ((long) (long) ((long) (((long) (long) ((long) (SignExt<long>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]), 32)))) * ((long) (long) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))))))));
		return true;
	}
	/* SMULH */
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((Int128) (((Int128) (((Int128) (Int128) ((Int128) ((Int128) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))))) * ((Int128) (Int128) ((Int128) ((Int128) ((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))))))))) >> (uint) (0x40))))));
		return true;
	}
	/* SSHLL */
	if((inst & 0xBF80FC00U) == 0x0F00A400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto immh = (inst >> 19) & 0xFU;
		auto immb = (inst >> 16) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto variant = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = string("");
		auto tb = string("");
		auto shift = (ulong) ((ulong) (0x0));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			ta = string("8H");
			tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x8)));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				ta = string("4S");
				tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x10)));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					ta = string("2D");
					tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		auto iv = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x8)))) : (0x0))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x8)))) : (0x1))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x8)))) : (0x2))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x8)))) : (0x3))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x4] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x4)) + ((long) (long) (0x8)))) : (0x4))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x5] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x5)) + ((long) (long) (0x8)))) : (0x5))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x6] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x6)) + ((long) (long) (0x8)))) : (0x6))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x7] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x7)) + ((long) (long) (0x8)))) : (0x7))))])))) << (uint) (shift));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x0] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x4)))) : (0x0))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x1] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x4)))) : (0x1))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x2] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x4)))) : (0x2))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x3] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x4)))) : (0x3))))])))) << (uint) (shift));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<long>*>(&(state->V[(int) (rd)]))[0][0x0] = (long) (((long) ((long) ((int) (reinterpret_cast<Vector128<int>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x2)))) : (0x0))))])))) << (uint) (shift));
					reinterpret_cast<Vector128<long>*>(&(state->V[(int) (rd)]))[0][0x1] = (long) (((long) ((long) ((int) (reinterpret_cast<Vector128<int>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x2)))) : (0x1))))])))) << (uint) (shift));
				} else {
					throw "Not implemented";
				}
			}
		}
		return true;
	}
	/* STLR */
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	/* STLRB */
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	/* STLRH */
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	/* STLXR */
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) (address) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		state->X[(int) rs] = (ulong) (uint) (0x0);
		return true;
	}
	/* STLXRB */
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		state->X[(int) rs] = (ulong) (uint) (0x0);
		return true;
	}
	/* STP-postindex */
	if((inst & 0x7FC00000U) == 0x28800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STP-preindex */
	if((inst & 0x7FC00000U) == 0x29800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	/* STP-signed-offset */
	if((inst & 0x7FC00000U) == 0x29000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		return true;
	}
	/* STP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_269) -> string { switch(temp_269) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_270) -> long { switch(temp_270) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt1]);
				*(Vector128<float>*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))) = (Vector128<float>) (state->V[rt2]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_271) -> string { switch(temp_271) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_272) -> long { switch(temp_272) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt1]);
				*(Vector128<float>*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))) = (Vector128<float>) (state->V[rt2]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	/* STP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_273) -> string { switch(temp_273) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_274) -> long { switch(temp_274) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt1]);
				*(Vector128<float>*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))) = (Vector128<float>) (state->V[rt2]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) (address) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) (address) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	/* STR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (ulong) (((ulong) ((ulong) (imm))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (ulong) (pimm)))) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (ulong) (pimm)))) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		return true;
	}
	/* STR-register */
	if((inst & 0xBFE00C00U) == 0xB8200800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_275) -> string { switch(temp_275) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	/* STR-simd-postindex */
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_276) -> string { switch(temp_276) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STR-simd-preindex */
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_277) -> string { switch(temp_277) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	/* STR-simd-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_278) -> string { switch(temp_278) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) ((ushort) ((imm) << (uint) (scale)))));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C200800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r1 = (string) (([=](auto temp_279) -> string { switch(temp_279) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (([=](auto temp_280) -> long { switch(temp_280) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (long) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_281) -> string { switch(temp_281) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		*(byte*) (address) = (byte) ((byte) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	/* STRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))) = (byte) ((byte) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	/* STRB-register */
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_282) -> string { switch(temp_282) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	/* STRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	/* STRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	/* STRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))) = (ushort) ((ushort) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	/* STRH-register */
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_283) -> string { switch(temp_283) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (ushort) ((ushort) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	/* STUR */
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>(imm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	/* STUR-simd */
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_284) -> string { switch(temp_284) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				*(Vector128<float>*) (address) = (Vector128<float>) (state->V[rt]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STURB */
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (byte) ((byte) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	/* STURH */
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (ushort) ((ushort) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	/* STXR */
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		state->X[(int) rs] = (ulong) (uint) ((bool) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((bool) (CompareAndSwap((uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])), (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]), state->Exclusive32))) : ((bool) (CompareAndSwap((ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])), (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]), state->Exclusive64)))));
		return true;
	}
	/* SUB-immediate */
	if((inst & 0x7F800000U) == 0x51000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
		}
		return true;
	}
	/* SUB-extended-register */
	if((inst & 0x7FE00000U) == 0x4B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_285) -> string { switch(temp_285) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_286) -> string { switch(temp_286) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) (([=](auto temp_287) -> uint { switch(temp_287) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) (([=](auto temp_288) -> uint { switch(temp_288) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_289) -> ulong { switch(temp_289) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_290) -> ulong { switch(temp_290) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm)))));
			}
		}
		return true;
	}
	/* SUB-shifted-register */
	if((inst & 0x7F200000U) == 0x4B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_291) -> string { switch(temp_291) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) - ((uint) (uint) ((uint) (([=](auto temp_292) -> uint { switch(temp_292) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (([=](auto temp_293) -> ulong { switch(temp_293) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
		}
		return true;
	}
	/* SUBS-extended-register */
	if((inst & 0x7FE00000U) == 0x6B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_294) -> string { switch(temp_294) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_295) -> string { switch(temp_295) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL))));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) (((uint) (([=](auto temp_296) -> uint { switch(temp_296) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (((ulong) (([=](auto temp_297) -> ulong { switch(temp_297) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		}
		return true;
	}
	/* SUBS-shifted-register */
	if((inst & 0x7F200000U) == 0x6B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto mode32 = (bool) (((size) == (0x0)) ? 1U : 0U);
		auto r = (string) ((mode32 != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_298) -> string { switch(temp_298) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if((mode32) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) (([=](auto temp_299) -> uint { switch(temp_299) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (([=](auto temp_300) -> ulong { switch(temp_300) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* SUBS-immediate */
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_301) -> string { switch(temp_301) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		auto rimm = (uint) ((shift != 0) ? ((uint) (((uint) ((uint) (imm))) << (uint) (0xC))) : (imm));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	/* SVC */
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		Svc(imm);
		return true;
	}
	/* SYS */
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return true;
	}
	/* TBZ */
	if((inst & 0x7F000000U) == 0x36000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint) ((((uint) ((uint) (((uint) ((uint) (upper))) << (uint) (0x5)))) | ((uint) ((uint) ((uint) (bottom))))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		if(((ulong) ((((ulong) ((ulong) (((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])) >> (uint) (imm)))) & ((ulong) (0x1))))) != 0) {
			Branch(pc + 4);
		} else {
			Branch(addr);
		}
		return true;
	}
	/* TBNZ */
	if((inst & 0x7F000000U) == 0x37000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint) ((((uint) ((uint) (((uint) ((uint) (upper))) << (uint) (0x5)))) | ((uint) ((uint) ((uint) (bottom))))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		if(((ulong) ((((ulong) ((ulong) (((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])) >> (uint) (imm)))) & ((ulong) (0x1))))) != 0) {
			Branch(addr);
		} else {
			Branch(pc + 4);
		}
		return true;
	}
	/* UADDLV */
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_302) -> string { switch(temp_302) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_303) -> string { switch(temp_303) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto esize = (long) ((0x8) << (uint) (size));
		auto count = (long) (((long) (long) ((long) ((Q != 0) ? (0x80) : (0x40)))) / ((long) (long) (esize)));
		switch(size) {
			case 0x0: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (Bitcast<uint, float>((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))), 0, 0, 0 };
				break;
			}
			case 0x2: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((ulong) ((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* UBFM */
	if((inst & 0x7F800000U) == 0x53000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))));
		} else {
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))));
			state->X[(int) rd] = (ulong) ((((ulong) (bot)) & ((ulong) (tmask))));
		}
		return true;
	}
	/* UCVTF-scalar-gpr-integer */
	if((inst & 0x7F3FFC00U) == 0x1E230000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x0: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("X");
				break;
			}
			case 0x5: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x5: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* UCVTF-scalar-integer */
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((uint) (Bitcast<float, uint>((float) (state->V[rn][0]))))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))), 0 });
		}
		return true;
	}
	/* UCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x2E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_304) -> string { switch(temp_304) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* UDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) (0x0))) : ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) / ((uint) (uint) (operand2))))));
		} else {
			auto operand2 = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (0x0))) : ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) / ((ulong) (ulong) (operand2)))));
		}
		return true;
	}
	/* UMADDL */
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))) + ((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))) * ((ulong) (ulong) ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))));
		return true;
	}
	/* UMULH */
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))) * ((UInt128) (UInt128) ((UInt128) ((UInt128) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))))))) >> (uint) (0x40))));
		return true;
	}
	/* USHL-vector */
	if((inst & 0xBF20FC00U) == 0x2E204400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_305) -> string { switch(temp_305) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		auto m = (Vector128<float>) (state->V[rm]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x0])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x0])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x1])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x1])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x2])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x2])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x3])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x3])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x4])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x4])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x5])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x5])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x6])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x6])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x7])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x7])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x0])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x0])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x1])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x1])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x2])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x2])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x3])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x3])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x4])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x4])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x5])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x5])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x6])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x6])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x7])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x7])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x8])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x8])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x9])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x9])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xA])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xA])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xB])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xB])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xC])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xC])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xD])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xD])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xE])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xE])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xF])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xF])));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x0])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x0])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x1])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x1])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x2])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x2])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x3])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x0])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x0])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x1])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x1])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x2])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x2])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x3])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x3])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x4])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x4])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x5])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x5])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x6])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x6])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x7])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x7])));
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x0])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x1])));
				break;
			}
			case 0x5: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x0])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x1])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x2])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x2])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x3])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x3])));
				break;
			}
			case 0x7: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x0])) << (uint) ((ulong) (reinterpret_cast<Vector128<ulong>>(m)[0x0])));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x1])) << (uint) ((ulong) (reinterpret_cast<Vector128<ulong>>(m)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* XTN */
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_306) -> string { switch(temp_306) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_307) -> string { switch(temp_307) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) ((byte) (a));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) ((byte) (b));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) ((byte) (c));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) ((byte) (d));
				break;
			}
			case 0x1: {
				auto a = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) ((ushort) (a));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) ((ushort) (b));
				break;
			}
			case 0x2: {
				auto a = (ulong) (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn]))[0x0]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) ((uint) (a));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* XTN2 */
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_308) -> string { switch(temp_308) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_309) -> string { switch(temp_309) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x3]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) ((byte) (a));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) ((byte) (b));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) ((byte) (c));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) ((byte) (d));
				break;
			}
			case 0x1: {
				auto a = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x1]);
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) ((ushort) (a));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) ((ushort) (b));
				break;
			}
			case 0x2: {
				auto a = (ulong) (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn]))[0x0]);
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) ((uint) (a));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}

    return false;
}
