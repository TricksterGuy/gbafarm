OUTPUT := main
CPPFLAGS := -Wall
CC := gcc -std=c99 -Wall
FILES := main.o \
	sin_lut.o \
	cos_lut.o

all : $(OUTPUT)

$(OUTPUT) : $(FILES)
	$(CC) $(LDFLAGS) $^ -o $(OUTPUT) $(LDLIBS)

clean :
	$(RM) -rf *.o $(OUTPUT)

main.o : sin_lut.h cos_lut.h main.c
sin_lut.o : sin_lut.h sin_lut.c
cos_lut.o : cos_lut.h cos_lut.c
