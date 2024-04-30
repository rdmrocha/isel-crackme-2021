# ISEL crackme

Very simple barebones _crackme_ exercise for [Ghidra](https://github.com/NationalSecurityAgency/ghidra) (or similar tools)

This exercise's intent is to help understand reverse engineering tools and how to analyse a simple piece of code.

# What is the aim of this exercise?
The application prompts the user for a password and the exercise expects the coder to be able to produce a valid key generator allowing any user to login. By analysing and following the code in a tool like Ghidra, it will become obvious that there is more to it than meets the eye. It will be very hard to generate valid _admin keys_, so other methods of exploitation are needed.

# Compiling
This makefile is almost as simple as it can be and it's targetting MacOS machines. Other architectures can be added by adapting or replacing the compiler call and most likely, nothing else is needed.

# Keygen
Inside the _src_ dir, there's a very simple (and unoptimised) implementation of one of the possible solutions for the keygen. The first _print_ simple outputs valid keys for this exercise. Commenting that _print_ and uncommenting the _padding+print_ part of the code outputs a valid passwords that can be piped to the _crackme_ application in order to exploit it and escalate previleges.

Have fun!
