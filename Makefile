
ARG = $(subst :, ,$*)
KEYBOARD = $(word 1, $(ARG))
KEYMAP = $(word 2, $(ARG))
TARGET = $(word 3, $(ARG))

LINK_TARGET = $(shell pwd)/$(KEYBOARD)/$(KEYMAP)
LINK_NAME = $(shell pwd)/qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

all: compile

.PHONY: %
%:
	ln -s ${LINK_TARGET} ${LINK_NAME}
	make BUILD_DIR=$(shell pwd)/.build -j1 -C qmk_firmware $(KEYBOARD):$(KEYMAP):$(TARGET)
	rm ${LINK_NAME}
	rm -f ${LINK_TARGET}/${KEYMAP}

clean:
	rm -rf $(shell pwd)/.build