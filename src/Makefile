OBJECTS = main.o
TARGET = hello

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

main.o: version.h

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean

# vim: noet
