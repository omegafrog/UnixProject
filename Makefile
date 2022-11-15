SRCS = $(notdir $(wildcard src/*/*.c))
OBJS = $(SRCS:.c=.o)

SRVSRC = $(notdir $(wildcard src/server/*.c))
SRVOBJ=$(patsubst %.c, obj/server/%.o, $(SRVSRC))
DBGOBJ=$(patsubst %.c, obj/server/debug_%.o, $(SRVSRC))
CLISRC = $(notdir $(wildcard src/client/*.c))
CLIOBJ=$(patsubst %.c, obj/%.o, $(CLISRC))

$(info $(CLIOBJ) $(SRVOBJ))
$(info $(OBJS))

all : clear server client1 client2

debug : clear server_debug client1_debug client2_debug

obj/util/%.o : src/util/%.c
	gcc -g -c $< -o $@

obj/server/%.o : src/server/%.c 
	gcc -g -c $< -o $@

obj/client/%.o : src/client/%.c 
	gcc -g -c $< -o $@

server : $(SRVOBJ) obj/util/queue.o 
	gcc -g $^ -o server -lpthread

client1 : obj/client/client1.o obj/client/getServerInputThread.o obj/client/printReceivedThread.o obj/client/senderClientThread.o obj/util/queue.o obj/client/managerThread.o 
	gcc -g $^ -o client1 -lpthread

client2 : obj/client/client2.o obj/client/getServerInputThread.o obj/client/printReceivedThread.o obj/client/senderClientThread.o obj/util/queue.o obj/client/managerThread.o 
	gcc -g $^ -o client2 -lpthread



obj/util/debug_%.o : src/util/%.c
	gcc -D DEBUG -g -c $< -o $@

obj/server/debug_%.o : src/server/%.c 
	gcc -D DEBUG -g -c $< -o $@

obj/client/debug_%.o : src/client/%.c 
	gcc -D DEBUG -g -c $< -o $@
	
server_debug : $(DBGOBJ) obj/util/debug_queue.o 
	gcc -g $^ -o server_debug -lpthread

client1_debug : obj/client/debug_client1.o obj/client/debug_getServerInputThread.o obj/client/debug_printReceivedThread.o obj/client/debug_senderClientThread.o obj/util/debug_queue.o obj/client/debug_managerThread.o 
	gcc -g $^ -o client1_debug -lpthread

client2_debug : obj/client/debug_client2.o obj/client/debug_getServerInputThread.o obj/client/debug_printReceivedThread.o obj/client/debug_senderClientThread.o obj/util/debug_queue.o obj/client/debug_managerThread.o 
	gcc -g $^ -o client2_debug -lpthread

clear :
	rm -rf obj/client/*.o obj/server/*.o obj/util/*.o