sbin_PROGRAMS = cmuxcontrold
cmuxcontrold_SOURCES = CMUXChannel.cpp CMUXChannel.h CMUXInstance.cpp \
	CMUXInstance.h CMUXManager.cpp CMUXManager.h ControlConnection.cpp \
	ControlConnection.h ControlRequestHandler.cpp ControlRequestHandler.h \
	ControlServer.cpp ControlServer.h DescriptorWatcher.h EventLoop.cpp \
	EventLoop.h gsm0710.c gsm0710.h gsmmux.h IRemoteParty.h main.cpp \
  IRemoteParty.cpp

cmuxcontrold_CXXFLAGS = -Wall -W
cmuxcontrold_CFLAGS = -Wall -W
cmuxcontrold_CPPFLAGS = -I$(top_srcdir)/include "-Dlocalstatedir=\"${localstatedir}\""
cmuxcontrold_LDADD = $(top_builddir)/libcmux/libcmux.la -lutil
