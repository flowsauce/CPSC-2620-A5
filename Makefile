# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11

# the build target executable:
TARGET = testStrMatrix
CLASS1 = StructMat
CLASS2 = SymMat
CLASS3 = TriMat
CLASS4 = DiaMat
CLASS5 = SymTriDiaMat
CLASS6 = UpperTriMat
CLASS7 = LowerTriMat
MAIN = testStrMatrix

all: $(TARGET)

$(TARGET): $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(CLASS6).o $(CLASS7).o $(MAIN).o
	$(CC) $(CFLAGS) -o $(TARGET) $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(CLASS6).o $(CLASS7).o $(MAIN).o

$(CLASS1).o: $(CLASS1).cc $(CLASS1).h
	$(CC) $(CFLAGS) -c $(CLASS1).cc

$(CLASS2).o: $(CLASS2).cc $(CLASS2).h
	$(CC) $(CFLAGS) -c $(CLASS2).cc

$(CLASS3).o: $(CLASS3).cc $(CLASS3).h
	$(CC) $(CFLAGS) -c $(CLASS3).cc

$(CLASS4).o: $(CLASS4).cc $(CLASS4).h
	$(CC) $(CFLAGS) -c $(CLASS4).cc

$(CLASS5).o: $(CLASS5).cc $(CLASS5).h
	$(CC) $(CFLAGS) -c $(CLASS5).cc

$(CLASS6).o: $(CLASS6).cc $(CLASS6).h
	$(CC) $(CFLAGS) -c $(CLASS6).cc

$(CLASS7).o: $(CLASS7).cc $(CLASS7).h
	$(CC) $(CFLAGS) -c $(CLASS7).cc

$(MAIN).o: $(MAIN).cc $(CLASS1).h $(CLASS2).h $(CLASS3).h $(CLASS4).h $(CLASS5).h $(CLASS6).h $(CLASS7).h
	$(CC) $(CFLAGS) -c $(MAIN).cc

clean:
	$(RM) -f $(TARGET) $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(MAIN).o
