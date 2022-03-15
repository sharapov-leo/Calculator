source := calc.cpp basegramma.h basegramma.cpp kngramma.h kngramma.cpp slr.h slr.cpp fsm.h baselexer.h baselexer.cpp base-compiler.h base-compiler.cpp longArithmetic.h longArithmetic.cpp code-gen.h code-gen.cpp
all:
	g++ $(addprefix src/, $(source))
