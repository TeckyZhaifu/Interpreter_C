#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;

    initChunk(&chunk); /*Puntatori, diamo l`indirizzo*/

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123); /*123 numero a caso*/
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "Test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

  return 0;
}