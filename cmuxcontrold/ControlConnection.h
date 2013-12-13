#ifndef __CONTROL_CONNECTION__H__
#define __CONTROL_CONNECTION__H__

#include <vector>
#include <sys/socket.h>
#include <sys/un.h>
#if defined(HAVE_STRUCT_XUCRED)
#include <sys/ucred.h>
#endif

#include "DescriptorWatcher.h"
#include "IRemoteParty.h"

class ControlServer;
class ControlRequestHandler;

class ControlConnection: public DescriptorWatcher, public IRemoteParty {
public:
  ControlConnection(ControlServer *server, int fd);
  virtual ~ControlConnection();

  virtual int fd() const;
  virtual bool wantsRead() const;
  virtual bool wantsWrite() const;

  virtual void readable();
  virtual void writable();
  virtual void abnormal();

  virtual void sendMessage(CMUX::Package &package);
  virtual void close();

#if defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
#if defined(HAVE_STRUCT_XUCRED)
  virtual uid_t uid();
  virtual gid_t gid();
#elif defined(HAVE_STRUCT_UCRED)
  virtual pid_t pid();
  virtual uid_t uid();
  virtual gid_t gid();
#endif
#endif

private:
  ControlServer *m_server;
  int m_fd;
  std::vector<unsigned char> m_recvBuf, m_sendBuf;

#if defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
#if defined(HAVE_STRUCT_XUCRED)
  struct xucred m_cred;
#elif defined(HAVE_STRUCT_UCRED)
  struct ucred m_cred;
#endif
#endif

  ControlRequestHandler *m_requestHandler;
};

#endif
