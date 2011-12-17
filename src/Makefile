OBJECTS = main.o
TARGET = hello

all: $(TARGET)

$(TARGET): $(OBJECTS) mo
	$(CC) -lintl -o $@ $(OBJECTS)

POT=locale/helloworld.pot
pot: $(POT)
$(POT): main.c
	@mkdir -p locale/zh_CN/LC_MESSAGES
	xgettext -s -k_ -o $@ $^

po: pot locale/zh_CN/LC_MESSAGES/helloworld.po
locale/zh_CN/LC_MESSAGES/helloworld.po: $(POT)
	if [ ! -f $@ ]; then msginit -i $(POT) -o $@; fi
	msgmerge $@ $< -o locale/temp.po
	mv locale/temp.po $@

mo:: po
mo:: locale/zh_CN/LC_MESSAGES/helloworld.mo
locale/zh_CN/LC_MESSAGES/helloworld.mo: locale/zh_CN/LC_MESSAGES/helloworld.po
	msgfmt -o $@ $<

main.o: version.h

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean

# vim: noet
