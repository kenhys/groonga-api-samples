AM_CFLAGS = $(GROONGA_CFLAGS) $(GLIB_CFLAGS)
LIBS = $(GROONGA_LIBS) $(GLIB_LIBS)

bin_PROGRAMS = \
	grn_db_create	\
	grn_db_open	\
	grn_db_open_or_create

grn_db_create_SOURCES = grn_db_create.c
grn_db_open_SOURCES = grn_db_open.c
grn_db_open_or_create_SOURCES = grn_db_open_or_create.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
