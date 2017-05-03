# Readme
`TuringMachine` is a fairly crappy implementation of a Turing Machine, that I made to get back into using STL after writing my own library for a course in college.

## Compiling
```
make
```
That's it.

## Usage
```
./tm
```

You'll be presented with a blank terminal. Enter the number of "Cards" that you want to enter, and then enter the cards. The format for entering cards is as follows:

```
<Instruction if 0> <Instruction if 1>
```

To enter an instruction, use the following format

```
<direction to move after instruction> <what to overwrite with> <next card>
```

The direction can be `l` for going left, and `r` for going right. Anything else means to stay at the same spot. The overwrite thing is just a single bit, so it can be 0 or 1. The next card is any integer, but it should be a card that you'll make. Basically, shouldn't be larger than number of cards - 1.

After this, enter the memory. To do this, just type in a string of 0s and 1s, this is interpreted as the memory. For now, it always starts at the first bit of this string.

After doing all this, just type in the number of "ticks" you want to simulate, and it'll simulate that many ticks and show the memory output after each one. Keep entering numbers for ticks. If you enter a negative number or anything non numerical you'll exit the program.

_Yes I know this is super bad_