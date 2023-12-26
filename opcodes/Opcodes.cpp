#include <cstddef>
#include <unordered_map>

/**
 * @brief The Opcode struct represents an opcode instruction.
 *
 * An opcode is a binary instruction that represents a specific operation
 * to be performed by a computer processor. This struct encapsulates an
 * opcode instruction.
 */
typedef struct Opcode {
    std::byte instruction;
} Opcode;

/**
 * @enum OpcodeEnum
 * @brief Defines the opcode enumeration for the instruction set of the CPU.
 */
enum OpcodeEnum {
    Exit,
    Int_Store,              // allow storing integer in register
    Int_Print,              // print integer contents of a register
    Int_ToString,           // convert integer-register to string
    Int_Random,             // generate random number
    Jump_To,                // unconditional jump
    Jump_Z,                 // jump if Z-flag is set
    Jump_Nz,                // jump if Z-flag is not set
    Xor_Op,                 // perform XOR operation against two registers
    Add_Op,                 // perform ADD operation against two registers
    Sub_Op,                 // perform SUB operation against two registers
    Mul_Op,                 // perform MUL operation against two registers
    Div_Op,                 // perform DIV operation against two registers
    Inc_Op,                 // increment given register by one
    Dec_Op,                 // decrement given register by one
    And_Op,                 // perform logical AND operation against two registers
    Or_Op,                  // perform logical OR operation against two registers
    String_Store,           // store string in register
    String_Print,           // print string contents of register
    String_Concat,          // join two strings
    String_System,          // execute system binary store in given string register
    String_ToInt,           // convert given string-register to int
    Cmp_Reg,                // compare two registers
    Cmp_Immediate,          // compare register content with number
    Cmp_String,             // compare register contents with string
    Is_String,              // tests if register contains string
    Is_Integer,             // tests if register contains integer
    Nop_Op,                 // does nothing
    Reg_Store,              // store register content in another register
    Peek,                   // read from memory
    Poke,                   // set address-content
    Memcpy,                 // copy region of RAM
    Stack_Push,             // push given register-contents on stack
    Stack_Pop,              // retrieve value from stack
    Stack_Ret,              // return from a CALL
    Stack_Call,             // call a subroutine
    Trap_Op,                // invoke CPU trap
};

std::unordered_map<OpcodeEnum, std::byte> opcodeToByte =
        {
                {Exit, static_cast<std::byte>(0x00)},
                {Int_Store, static_cast<std::byte>(0x01)},
                {Int_Print, static_cast<std::byte>(0x02)},
                {Int_ToString, static_cast<std::byte>(0x03)},
                {Int_Random, static_cast<std::byte>(0x04)},
                {Jump_To, static_cast<std::byte>(0x10)},
                {Jump_Z, static_cast<std::byte>(0x11)},
                {Jump_Nz, static_cast<std::byte>(0x12)},
                {Xor_Op, static_cast<std::byte>(0x20)},
                {Add_Op, static_cast<std::byte>(0x21)},
                {Sub_Op, static_cast<std::byte>(0x22)},
                {Mul_Op, static_cast<std::byte>(0x23)},
                {Div_Op, static_cast<std::byte>(0x24)},
                {Inc_Op, static_cast<std::byte>(0x25)},
                {Dec_Op, static_cast<std::byte>(0x26)},
                {And_Op, static_cast<std::byte>(0x27)},
                {Or_Op, static_cast<std::byte>(0x28)},
                {String_Store, static_cast<std::byte>(0x30)},
                {String_Print, static_cast<std::byte>(0x31)},
                {String_Concat, static_cast<std::byte>(0x32)},
                {String_System, static_cast<std::byte>(0x33)},
                {String_ToInt, static_cast<std::byte>(0x34)},
                {Cmp_Reg, static_cast<std::byte>(0x40)},
                {Cmp_Immediate, static_cast<std::byte>(0x41)},
                {Cmp_String, static_cast<std::byte>(0x22)},
                {Is_String, static_cast<std::byte>(0x43)},
                {Is_Integer, static_cast<std::byte>(0x44)},
                {Nop_Op, static_cast<std::byte>(0x50)},
                {Reg_Store, static_cast<std::byte>(0x51)},
                {Peek, static_cast<std::byte>(0x60)},
                {Poke, static_cast<std::byte>(0x61)},
                {Memcpy, static_cast<std::byte>(0x62)},
                {Stack_Push, static_cast<std::byte>(0x70)},
                {Stack_Pop, static_cast<std::byte>(0x71)},
                {Stack_Ret, static_cast<std::byte>(0x72)},
                {Stack_Call, static_cast<std::byte>(0x23)},
                {Trap_Op, static_cast<std::byte>(0x80)},
        };


/**
 * \brief Creates a new `Opcode` object from the given `instruction`.
 *
 * \param instruction The instruction value for the opcode.
 * \return The newly created `Opcode` object.
 *
 * This function initializes a new `Opcode` object with the provided instruction value and returns it.
 */
Opcode NewOpcode(std::byte instruction) {
    Opcode opcode = {instruction};
    return opcode;
}
