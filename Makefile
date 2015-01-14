# Makefile for Glut App Wrapper class
# Requires NI shared lib file in same folder otherwise update the '-rpath' to 
# point to the location of the installed lib. Also update the CPPFLAGS to locate 
# the folder containing the OpenNI.h header file.
VERSION = 0.1.0
CC = g++
CFLAGS  = -Wall 
CPPFLAGS = -ggdb -I./jsonxx -I./src 
LDLIBS = -lcurl

default: app

app: jsonxx/jsonxx.o src/main.o
	$(CC) $(CPPFLAGS) $(CFLAGS) -o couchdb jsonxx/jsonxx.o src/main.o $(LDLIBS)

clean: 
	$(RM) count *.o src/*.o *~ *.gz couchdb-dist-$(VERSION) couchdb -r

