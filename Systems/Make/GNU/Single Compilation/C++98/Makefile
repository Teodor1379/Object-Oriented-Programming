COMPILER = g++

FLAGS	=		-Wall							\
				-Wpedantic						\
				-Wextra							\
				-Winline						\
				-Walloca						\
				-Walloc-zero					\
				-Wshadow						\
												\
				-Wmissing-declarations			\
				-Wmissing-include-dirs			\
												\
				-Wnull-dereference				\
				-Wfree-nonheap-object			\
				-Wcast-qual						\
				-Wcast-align					\
												\
				-Wfloat-equal					\
				-Wdouble-promotion				\
												\
				-Wsuggest-attribute=pure		\
				-Wsuggest-attribute=const		\
				-Wsuggest-attribute=noreturn	\
				-Wmissing-noreturn				\
				-Wsuggest-attribute=malloc		\
				-Wsuggest-attribute=format		\
				-Wmissing-format-attribute		\
				-Wsuggest-attribute=cold		\
												\
				-Wconversion					\
				-Warith-conversion				\
												\
				-Wlogical-op					\
				-Wduplicated-branches			\
				-Wduplicated-cond				\
				-Wtrampolines					\
				-Wredundant-decls				\
				-Waggregate-return				\
												\
				-Wswitch-default				\
				-Wswitch-enum					\
												\
				-Wpacked						\
				-Wpadded						\
												\
				-Wstack-protector				\
				-Wopenacc-parallelism			\
				-Wopenmp-simd					\
												\
				-Wvector-operation-performance	\
												\
												\
				-pedantic						\
				-pedantic-errors				\
												\
												\
				-fpermissive					\

LINKER_FLAGS	=		-lm



all:
	$(COMPILER) $(FLAGS) -std=c++98 "$(Argument)" $(LINKER_FLAGS)
