INIT=$(wildcard ./init/*.c)
INIT_BUILD=$(patsubst ./init/%.c,./build/%.o,$(INIT))

SERVER=$(wildcard ./server/*.c)
SERVER_BUILD=$(patsubst ./server/%.c,./build/%.o,$(SERVER))


REQUST=$(wildcard ./requst/*.c)
REQUST_BUILD=$(patsubst ./requst/%.c,./build/%.o,$(REQUST))



RESP=$(wildcard ./response/*.c)
RESP_BUILD=$(patsubst ./response/%.c,./build/%.o,$(RESP))

SERVICE=$(wildcard ./service/*.c)
SERVICE_BUILD=$(patsubst ./service/%.c,./build/%.o,$(SERVICE))


WEBSOCKET=$(wildcard ./websocketserver/*.c)
WEBSOCKET_BUILD=$(patsubst ./websocketserver/%.c,./build/%.o,$(WEBSOCKET))




BUILD:=./build
INIT_SRC:=./init
SERVER_SRC:=./server
REQUST_SRC:=./requst
RESP_SRC:=./response
SERVICE_SRC:=./service
WEBSOCKET_SRC:=./websocketserver


INCLUDE:=-I./

CC:=gcc
# staer:
# 	@echo $(INIT_BUILD)
# 	@echo $(INIT)

BIN:=$(BUILD)/main.o \
	$(BUILD)/init.o \
	$(BUILD)/server.o \
	$(BUILD)/get_http_head.o \
	$(BUILD)/link_list.o \
	$(BUILD)/resp.o \
	$(BUILD)/insert_func.o \
	$(BUILD)/base64.o \
	$(BUILD)/sha1.o

main:$(BIN)
	$(CC) $^ -o $@


$(INIT_BUILD):$(BUILD)/%.o:$(INIT_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(SERVER_BUILD):$(BUILD)/%.o:$(SERVER_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(REQUST_BUILD):$(BUILD)/%.o:$(REQUST_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(RESP_BUILD):$(BUILD)/%.o:$(RESP_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(SERVICE_BUILD):$(BUILD)/%.o:$(SERVICE_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(WEBSOCKET_BUILD):$(BUILD)/%.o:$(WEBSOCKET_SRC)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)


$(BUILD)/main.o:main.c
	$(CC) -c $< -o $@ $(INCLUDE)
