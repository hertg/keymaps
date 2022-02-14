
ARG = $(subst :, ,$*)
KEYBOARD = $(word 1, $(ARG))
KEYMAP = $(word 2, $(ARG))
TARGET = $(word 3, $(ARG))
TARGET := $(or $(TARGET),all)

LINK_TARGET = $(shell pwd)/$(KEYBOARD)/$(KEYMAP)
LINK_NAME = qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

all: compile

.PHONY: %
%:
	@echo ${LINK_TARGET} ${LINK_NAME}
	ln -s ${LINK_TARGET} ${LINK_NAME}
	make BUILD_DIR=$(shell pwd)/.build -j1 -C qmk_firmware $(KEYBOARD):$(KEYMAP):$(TARGET)
	rm ${LINK_NAME}

clean:
	rm -rf $(shell pwd)/.build