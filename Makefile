# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 21:43:21 by amassias          #+#    #+#              #
#    Updated: 2024/01/20 18:04:31 by amassias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				:=	cc

THIRD_PARTY_DIR	:=	third-party

SRC_DIR			:=	sources
INC_DIR			:=	includes
OBJ_DIR			:=	_objects
BIN_DIR			:=	binaries

PUSH_SWAP		:=	push_swap
PS_SRC_DIR		:=	$(SRC_DIR)/push_swap
PS_OBJ_DIR		:=	$(OBJ_DIR)/push_swap

CHECKER			:=	checker
CK_SRC_DIR		:=	$(SRC_DIR)/checker
CK_OBJ_DIR		:=	$(OBJ_DIR)/checker

CM_SRC_DIR		:=	$(SRC_DIR)/common
CM_OBJ_DIR		:=	$(OBJ_DIR)/common

# **************************************************************************** #
#                                                                              #
# Third party libraries                                                        #
#                                                                              #
# **************************************************************************** #

LIB_FT_PATH		:=	$(THIRD_PARTY_DIR)/libft-full
LIB_FT			:=	$(LIB_FT_PATH)/libftfull.a

# **************************************************************************** #
#                                                                              #
# Compiler flags                                                               #
#                                                                              #
# **************************************************************************** #

CFLAGS			:=					\
	-I$(INC_DIR)					\
	-I$(LIB_FT_PATH)				\
	-Wall -Werror -Wextra -g		\

LFLAGS			:=					\
	-L$(LIB_FT_PATH)				\
	-lftfull						\

# **************************************************************************** #
#                                                                              #
# Push Swap files                                                              #
#                                                                              #
# **************************************************************************** #

PS_FILES		:=															\
	algorithms/fixed_size/n2												\
	algorithms/fixed_size/n3												\
	algorithms/fixed_size/n4												\
	algorithms/fixed_size/n5												\
	algorithms/fixed_size/ps_code_processor									\
	algorithms/radix/radix													\
	printed_operations/push													\
	printed_operations/reverse_rotate										\
	printed_operations/rotate												\
	printed_operations/swap													\
	main																	\

PS_SRCS			:=	$(addprefix $(PS_SRC_DIR)/,$(addsuffix .c,$(PS_FILES)))

PS_OBJS			:=	$(addprefix $(PS_OBJ_DIR)/,$(addsuffix .o,$(PS_FILES)))

# **************************************************************************** #
#                                                                              #
# Checker files                                                                #
#                                                                              #
# **************************************************************************** #

CK_FILES		:=															\
	main																	\

CK_SRCS			:=	$(addprefix $(CK_SRC_DIR)/,$(addsuffix .c,$(CK_FILES)))

CK_OBJS			:=	$(addprefix $(CK_OBJ_DIR)/,$(addsuffix .o,$(CK_FILES)))

# **************************************************************************** #
#                                                                              #
# Common files                                                                 #
#                                                                              #
# **************************************************************************** #

CM_FILES		:=															\
	context/ps_cleanup														\
	context/ps_initialize													\
	operations/ps_push														\
	operations/ps_rotate													\
	operations/ps_reverse_rotate											\
	operations/ps_swap														\
	utils/is_string_integer													\

CM_SRCS			:=	$(addprefix $(CM_SRC_DIR)/,$(addsuffix .c,$(CM_FILES)))

CM_OBJS			:=	$(addprefix $(CM_OBJ_DIR)/,$(addsuffix .o,$(CM_FILES)))

# **************************************************************************** #
#                                                                              #
# Phony rules                                                                  #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re cleanlibs fcleanlibs norminette

all: $(BIN_DIR)/$(PUSH_SWAP)

bonus: $(BIN_DIR)/$(CHECKER)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

cleanlibs:
	$(MAKE) clean -C $(LIB_FT_PATH)

fcleanlibs:
	$(MAKE) fclean -C $(LIB_FT_PATH)

re:	fclean all

norminette:
	@norminette												\
		`find $(SRC_DIR) -type f -name \*.c`				\
		`find $(INC_DIR) -type f -name \*.h`				\
		| grep -Ev '^Notice: |OK\!$$' 2> /dev/null			\
		&& exit 1 || printf 'Norminette OK!\n' && exit 0

# **************************************************************************** #
#                                                                              #
# Binary rules                                                                 #
#                                                                              #
# **************************************************************************** #

$(BIN_DIR)/$(PUSH_SWAP): $(LIB_FT) $(CM_OBJS) $(PS_OBJS)
	@mkdir -p $(@D)
	$(CC) -o $@ $(CM_OBJS) $(PS_OBJS) $(LFLAGS)

$(BIN_DIR)/$(CHECKER): $(LIB_FT) $(CM_OBJS) $(CK_OBJS)
	@mkdir -p $(@D)
	$(CC) -o $@ $(CM_OBJS) $(CK_OBJS) $(LFLAGS)

$(LIB_FT):
	$(MAKE) -C $(LIB_FT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)