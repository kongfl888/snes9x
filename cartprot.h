#ifndef _CARTPROT_H_
#define _CARTPROT_H_

enum
{
	CARTPROT_NONE,
	CARTPROT_TEKKEN2,		// "Tekken 2" / Street Fighter EX command chip at $80-$BF:$8000
	CARTPROT_BUGSLIFE		// "A Bug's Life" XOR ports at $xx:6000-$6FFF
};

// Security chips found on unlicensed LoROM carts.
struct SCartProt
{
	uint8	Armed;
	uint8	Command;
	uint8	Argument;
	uint8	Answer;
	uint8	Xor[4];
};

extern struct SCartProt	CartProt;

bool8 S9xCartProtDetect (uint8 *rom, uint32 size);
int   S9xCartProtKind (void);
void  S9xCartProtReset (void);
void  S9xCartProtWrite (uint32 address, uint8 data);
uint8 S9xCartProtRead (uint32 address);
void  S9xCartProtSetRomBase (uint32 bank, uint8 *base);

#endif
