# NFA-Simulation
NFA refers to Nondeterministic Finite Automaton. 

A Finite Automata(FA) is said to be non-deterministic if there 
is more than one possible transition from one state on the same input symbol.

## Properties of NFA 
- can use Empty String transition.
- can be understood as multiple little machines computing at the same time.
- each pair of state and input symbol can have many possible next states.
- rejects the string in the event of all branches dying or refusing the string.
- requires less space than DFA(Deterministic Finite Automata).

## What is the program? 

This program simulate NFA where:-
- All input strings must be over the Alphabet E = {0, 1}
- Accept an input string that ends with '01'
