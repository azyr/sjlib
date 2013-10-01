# DEFAULT SETTINGS

BOOST_HEADER_DIR = /opt/boost/master/include

CONFIG(debug, debug|release) {
	message("Debug Build");
	BOOST_LIB_DIR = /opt/boost/master/lib/shared-dbg
}
CONFIG(release, debug|release) {
	message("Release Build");
	BOOST_LIB_DIR = /opt/boost/master/lib/shared
}

INCLUDEPATH += $$PWD/include

# LOAD USER SETTINGS

exists(user.pri) {
	include(user.pri)
}

