#ifndef __IREMOTE_PARTY__H__
#define __IREMOTE_PARTY__H__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace CMUX {
    class Package;
};

class IRemoteParty {
public:
    IRemoteParty();
    virtual ~IRemoteParty();

    virtual void sendMessage(CMUX::Package &package) = 0;
    virtual void close() = 0;

#if defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
#if defined(HAVE_STRUCT_XUCRED)
  virtual uid_t uid() = 0;
  virtual gid_t gid() = 0;
#elif defined(HAVE_STRUCT_UCRED)
  virtual pid_t pid() = 0;
  virtual uid_t uid() = 0;
  virtual gid_t gid() = 0;
#endif
#endif
};

#endif
