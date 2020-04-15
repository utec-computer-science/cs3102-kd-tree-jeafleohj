CC=g++
BUILD = build
BIN = bin
TARGET = bin/test
SRCDIR = src
INC = -I include

ALL: $(TARGET) 

$(TARGET): $(OBJ)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)";
	@mkdir -p $(BUILD)
	@mkdir -p $(BIN)
	$(CC) $^ -o $(TARGET) $(INC) $(SRCDIR)/main.cpp


.PHONY: clean
clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
