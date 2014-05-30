#############################################################################
# Makefile for building: navtex
# Generated by qmake (2.01a) (Qt 4.8.5) on: Wed May 28 15:49:03 2014
# Project:  test_widget.pro
# Template: app
# Command: /opt/EmbedSky/qt-4.8.5/__install/arm/bin/qmake -spec /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/linux-arm-gnueabi-g++ -o Makefile test_widget.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc
CXX           = arm-linux-g++
DEFINES       = -DQESP_NO_UDEV -D__linux__ -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/linux-arm-gnueabi-g++ -I. -I/opt/EmbedSky/qt-4.8.5/__install/arm/include/QtCore -I/opt/EmbedSky/qt-4.8.5/__install/arm/include/QtGui -I/opt/EmbedSky/qt-4.8.5/__install/arm/include/QtSql -I/opt/EmbedSky/qt-4.8.5/__install/arm/include -I/opt/EmbedSky/qt-4.8.5/__install/arm/include/QtTest -I3rdparty/qextserialport/src -I.
LINK          = arm-linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/EmbedSky/qt-4.8.5/__install/arm/lib
LIBS          = $(SUBLIBS)  -L/opt/EmbedSky/qt-4.8.5/__install/arm//lib -lQtTest -L/tslib-1.4/lib -L/opt/EmbedSky/qt-4.8.5/__install/arm//lib -lQtSql -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /opt/EmbedSky/qt-4.8.5/__install/arm/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = 3rdparty/qextserialport/src/qextserialport.cpp \
		3rdparty/qextserialport/src/qextserialenumerator.cpp \
		3rdparty/qextserialport/src/qextserialport_unix.cpp \
		3rdparty/qextserialport/src/qextserialenumerator_linux.cpp \
		main.cpp \
		FlowLayout.cpp \
		panel_info.cpp \
		panel_about.cpp \
		panel_item.cpp \
		panel_setup.cpp \
		panel_detail.cpp \
		mainwin.cpp \
		common.cpp \
		eventspy.cpp moc_panel_info.cpp \
		moc_panel_about.cpp \
		moc_panel_item.cpp \
		moc_panel_setup.cpp \
		moc_panel_detail.cpp \
		moc_mainwin.cpp \
		moc_eventspy.cpp \
		qrc_res.cpp
OBJECTS       = qextserialport.o \
		qextserialenumerator.o \
		qextserialport_unix.o \
		qextserialenumerator_linux.o \
		main.o \
		FlowLayout.o \
		panel_info.o \
		panel_about.o \
		panel_item.o \
		panel_setup.o \
		panel_detail.o \
		mainwin.o \
		common.o \
		eventspy.o \
		moc_panel_info.o \
		moc_panel_about.o \
		moc_panel_item.o \
		moc_panel_setup.o \
		moc_panel_detail.o \
		moc_mainwin.o \
		moc_eventspy.o \
		qrc_res.o
DIST          = /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/linux.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base-unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-base.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/qconfig.pri \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_functions.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_config.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/exclusive_builds.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_pre.prf \
		3rdparty/qextserialport/src/qextserialport.pri \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/release.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_post.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qtestlib.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/shared.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/warn_on.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/thread.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/moc.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/resources.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/uic.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/yacc.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/lex.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/include_source_dir.prf \
		test_widget.pro
QMAKE_TARGET  = navtex
DESTDIR       = 
TARGET        = navtex

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: test_widget.pro  /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/linux-arm-gnueabi-g++/qmake.conf /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/linux.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base-unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-base.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-unix.conf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/qconfig.pri \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_functions.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_config.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/exclusive_builds.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_pre.prf \
		3rdparty/qextserialport/src/qextserialport.pri \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/release.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_post.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qtestlib.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/shared.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/warn_on.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/thread.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/moc.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/resources.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/uic.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/yacc.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/lex.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/include_source_dir.prf \
		/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtTest.prl \
		/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtCore.prl \
		/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtSql.prl \
		/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtGui.prl \
		/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtNetwork.prl
	$(QMAKE) -spec /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/linux-arm-gnueabi-g++ -o Makefile test_widget.pro
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/unix.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/linux.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/gcc-base-unix.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-base.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/common/g++-unix.conf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/qconfig.pri:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_functions.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt_config.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/exclusive_builds.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_pre.prf:
3rdparty/qextserialport/src/qextserialport.pri:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/release.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/default_post.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qtestlib.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/shared.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/gdb_dwarf_index.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/warn_on.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/qt.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/unix/thread.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/moc.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/resources.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/uic.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/yacc.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/lex.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/features/include_source_dir.prf:
/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtTest.prl:
/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtCore.prl:
/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtSql.prl:
/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtGui.prl:
/opt/EmbedSky/qt-4.8.5/__install/arm/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/EmbedSky/qt-4.8.5/__install/arm/mkspecs/linux-arm-gnueabi-g++ -o Makefile test_widget.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/navtex1.0.0 || $(MKDIR) .tmp/navtex1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/navtex1.0.0/ && $(COPY_FILE) --parents 3rdparty/qextserialport/src/qextserialport.h 3rdparty/qextserialport/src/qextserialenumerator.h 3rdparty/qextserialport/src/qextserialport_global.h 3rdparty/qextserialport/src/qextserialport_p.h 3rdparty/qextserialport/src/qextserialenumerator_p.h FlowLayout.hpp panel_info.h panel_about.h panel_item.h panel_setup.h panel_detail.h mainwin.h common.h eventspy.h .tmp/navtex1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/navtex1.0.0/ && $(COPY_FILE) --parents 3rdparty/qextserialport/src/qextserialport.cpp 3rdparty/qextserialport/src/qextserialenumerator.cpp 3rdparty/qextserialport/src/qextserialport_unix.cpp 3rdparty/qextserialport/src/qextserialenumerator_linux.cpp main.cpp FlowLayout.cpp panel_info.cpp panel_about.cpp panel_item.cpp panel_setup.cpp panel_detail.cpp mainwin.cpp common.cpp eventspy.cpp .tmp/navtex1.0.0/ && $(COPY_FILE) --parents chn.ts eng.ts .tmp/navtex1.0.0/ && (cd `dirname .tmp/navtex1.0.0` && $(TAR) navtex1.0.0.tar navtex1.0.0 && $(COMPRESS) navtex1.0.0.tar) && $(MOVE) `dirname .tmp/navtex1.0.0`/navtex1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/navtex1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_qextserialport.cpp moc_qextserialenumerator.cpp moc_panel_info.cpp moc_panel_about.cpp moc_panel_item.cpp moc_panel_setup.cpp moc_panel_detail.cpp moc_mainwin.cpp moc_eventspy.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qextserialport.cpp moc_qextserialenumerator.cpp moc_panel_info.cpp moc_panel_about.cpp moc_panel_item.cpp moc_panel_setup.cpp moc_panel_detail.cpp moc_mainwin.cpp moc_eventspy.cpp
moc_qextserialport.cpp: 3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialport.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) 3rdparty/qextserialport/src/qextserialport.h -o moc_qextserialport.cpp

moc_qextserialenumerator.cpp: 3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialenumerator.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) 3rdparty/qextserialport/src/qextserialenumerator.h -o moc_qextserialenumerator.cpp

moc_panel_info.cpp: FlowLayout.hpp \
		common.h \
		panel_info.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) panel_info.h -o moc_panel_info.cpp

moc_panel_about.cpp: panel_about.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) panel_about.h -o moc_panel_about.cpp

moc_panel_item.cpp: panel_info.h \
		FlowLayout.hpp \
		common.h \
		panel_item.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) panel_item.h -o moc_panel_item.cpp

moc_panel_setup.cpp: FlowLayout.hpp \
		panel_setup.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) panel_setup.h -o moc_panel_setup.cpp

moc_panel_detail.cpp: panel_info.h \
		FlowLayout.hpp \
		common.h \
		panel_detail.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) panel_detail.h -o moc_panel_detail.cpp

moc_mainwin.cpp: common.h \
		mainwin.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) mainwin.h -o moc_mainwin.cpp

moc_eventspy.cpp: eventspy.h
	/opt/EmbedSky/qt-4.8.5/__install/arm//bin/moc $(DEFINES) $(INCPATH) eventspy.h -o moc_eventspy.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		res/spk_blue_on.png \
		res/checkbox_off.png \
		res/712.png \
		res/bg1.png \
		res/spk_blue_off.png \
		res/mail_1_close.png \
		res/navtex.png \
		res/checkbox_on.png \
		res/lock_16.png \
		res/unlock_16.png \
		res/mail_1_open.png
	/opt/EmbedSky/qt-4.8.5/__install/arm/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

qextserialport.o: 3rdparty/qextserialport/src/qextserialport.cpp 3rdparty/qextserialport/src/qextserialport.h \
		3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialport_p.h \
		moc_qextserialport.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialport.o 3rdparty/qextserialport/src/qextserialport.cpp

qextserialenumerator.o: 3rdparty/qextserialport/src/qextserialenumerator.cpp 3rdparty/qextserialport/src/qextserialenumerator.h \
		3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialenumerator_p.h \
		moc_qextserialenumerator.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialenumerator.o 3rdparty/qextserialport/src/qextserialenumerator.cpp

qextserialport_unix.o: 3rdparty/qextserialport/src/qextserialport_unix.cpp 3rdparty/qextserialport/src/qextserialport.h \
		3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialport_p.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialport_unix.o 3rdparty/qextserialport/src/qextserialport_unix.cpp

qextserialenumerator_linux.o: 3rdparty/qextserialport/src/qextserialenumerator_linux.cpp 3rdparty/qextserialport/src/qextserialenumerator.h \
		3rdparty/qextserialport/src/qextserialport_global.h \
		3rdparty/qextserialport/src/qextserialenumerator_p.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialenumerator_linux.o 3rdparty/qextserialport/src/qextserialenumerator_linux.cpp

main.o: main.cpp mainwin.h \
		common.h \
		eventspy.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

FlowLayout.o: FlowLayout.cpp FlowLayout.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FlowLayout.o FlowLayout.cpp

panel_info.o: panel_info.cpp panel_info.h \
		FlowLayout.hpp \
		common.h \
		panel_item.h \
		mainwin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o panel_info.o panel_info.cpp

panel_about.o: panel_about.cpp panel_about.h \
		mainwin.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o panel_about.o panel_about.cpp

panel_item.o: panel_item.cpp panel_item.h \
		panel_info.h \
		FlowLayout.hpp \
		common.h \
		mainwin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o panel_item.o panel_item.cpp

panel_setup.o: panel_setup.cpp panel_setup.h \
		FlowLayout.hpp \
		common.h \
		mainwin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o panel_setup.o panel_setup.cpp

panel_detail.o: panel_detail.cpp panel_detail.h \
		panel_info.h \
		FlowLayout.hpp \
		common.h \
		mainwin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o panel_detail.o panel_detail.cpp

mainwin.o: mainwin.cpp mainwin.h \
		common.h \
		FlowLayout.hpp \
		panel_info.h \
		panel_setup.h \
		panel_about.h \
		panel_detail.h \
		panel_item.h \
		3rdparty/qextserialport/src/qextserialport.h \
		3rdparty/qextserialport/src/qextserialport_global.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwin.o mainwin.cpp

common.o: common.cpp common.h \
		panel_item.h \
		panel_info.h \
		FlowLayout.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o common.o common.cpp

eventspy.o: eventspy.cpp eventspy.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o eventspy.o eventspy.cpp

moc_panel_info.o: moc_panel_info.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_panel_info.o moc_panel_info.cpp

moc_panel_about.o: moc_panel_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_panel_about.o moc_panel_about.cpp

moc_panel_item.o: moc_panel_item.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_panel_item.o moc_panel_item.cpp

moc_panel_setup.o: moc_panel_setup.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_panel_setup.o moc_panel_setup.cpp

moc_panel_detail.o: moc_panel_detail.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_panel_detail.o moc_panel_detail.cpp

moc_mainwin.o: moc_mainwin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwin.o moc_mainwin.cpp

moc_eventspy.o: moc_eventspy.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_eventspy.o moc_eventspy.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

