include(default.pri)

TEMPLATE = lib

QT += widgets
CONFIG += c++11
CONFIG += staticlib

TARGET = sj

######### BOOST ########

DEFINES += BOOST_ALL_DYN_LINK
QMAKE_CXXFLAGS += -isystem $$BOOST_HEADER_DIR # regard as system header
LIBS += -L$$BOOST_LIB_DIR

LIBS += -lboost_date_time

########## RAPI ##########

DEFINES += LINUX
DEFINES += _REENTRANT

##########################

SOURCES += \
	sj/colorbutton.cpp \
	sj/datetime.cpp \
	sj/enum_utils.cpp \
	sj/fontselector.cpp \
	sj/hashing.cpp \
	sj/qtinterop.cpp \
	sj/qtutils.cpp \
	sj/twowayaction.cpp \
	sj/trading/rapi_extensions.cpp \

HEADERS += \
	sj/colorbutton.h \
	sj/common_definitions_console.h \
	sj/cpu.h \
	sj/datetime.h \
	sj/demangle.h \
	sj/enum_utils.h \
	sj/exceptions.h \
	sj/fontselector.h \
	sj/hashing.h \
	sj/observable.h \
	sj/preprocessor.h \
	sj/priorityvector.h \
	sj/qtinterop.h \
	sj/qtutils.h \
	sj/safe_windows.h \
	sj/shared_container.h \
	sj/shared_container_sig.h \
	sj/sjmath.h \
	sj/std_extensions.h \
	sj/strmanip.h \
	sj/synchronizer_b.h \
	sj/synchronizer.h \
	sj/timer_chrono.h \
	sj/timer_rdtscp.h \
	sj/twowayaction.h \
	sj/type_definitions.h \


